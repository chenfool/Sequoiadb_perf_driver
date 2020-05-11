#include "perl_sequoiadb.hpp"

int get_sv_type (SV * sv)
{
   if (!SvOK (sv))
   {
      return ERROR ; 
   }
   if (!SvROK (sv)) // sv is a Scalar Variable
   {
      switch (SvTYPE (sv))
      {
         case SVt_IV :
            return INT ;
         case SVt_NV :
            return DOUBLE ;
         case SVt_PV :
            return STRING ;
         default : return UNKNOW ;
      }
   }
   else //sv is a References Variable
   {
      if (sv_derived_from (sv, "SequoiaDB::BSON::OID"))
      {
         return BSONOID ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::REGEX"))
      {
         return BSONREGEX ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::CODE"))
      {
         return BSONCODE ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::DATE"))
      {
         return BSONDATE ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::BOOLEAN"))
      {
         return BSONBOOLEAN ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::BINARY"))
      {
         return BSONBINARY ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::MaxKey"))
      {
         return BSONMAXKEY ;
      }
      else if (sv_derived_from (sv, "SequoiaDB::BSON::MinKey"))
      {
         return BSONMINKEY ;
      }


      switch (SvTYPE (SvRV (sv))) 
      {
         case SVt_PVAV :
            return ARRAY ;
         case SVt_PVHV :
            return HASH ;
         default : return UNKNOW ;
      }
   }
}

bool hv_to_bson (BSONObjBuilder * objbuilder, SV * sv)
{
   HV * hv ;
   HE * he ;
   int svtp ;
   hv = (HV *) SvRV (sv) ;
   while ((he = hv_iternext(hv)))
   {
      SV ** hval ;
      STRLEN len ;
      const char * key = HePV (he, len) ;
      //bson::StringData::StringData bsonkey (keychar) ;

      //std::string key (keychar) ;
     
      if ((hval = hv_fetch (hv, key, true ? -len : len, 0)) == 0)
      {
         croak ("could not find hash value for key %s, len:%lu\n", key, len) ;
      }

      svtp = get_sv_type (*hval) ; 
  
      switch (svtp)
      {
         case HASH :
         {
            BSONObjBuilder buildertemp ;
            BSONObj obj ;
            hv_to_bson (&buildertemp, *hval) ;

            obj = buildertemp.obj () ;
 
            objbuilder->append (key, obj) ;
         }
            break ;
         case ARRAY :
         { 
            BSONArrayBuilder objarraybuilder ;
            BSONArray objarray ;

            av_to_bson (&objarraybuilder, *hval) ;
 
            objarray = objarraybuilder.arr () ;

            objbuilder->append (key, objarray) ;

         }
            break ;

         case INT :
         {
            long vllong = SvIV (*hval) ;
            
            objbuilder->appendIntOrLL (key, vllong) ;
         }
            break ;

         case DOUBLE :
         {
            double vldouble = SvNV (*hval) ;
            objbuilder->appendNumber (key, vldouble) ;
         }
            break ;

         case STRING :
         {
            char * vlstring = SvPV_nolen (*hval) ;
            objbuilder->append (key, vlstring) ;
         }
            break ;

         case BSONOID :
         {
            plBSONOID * poid = (plBSONOID *) SvIV(*hval) ;
            const char * oidstr = poid->_getValue () ;
            OID oid ;
            oid.init (oidstr) ;
            objbuilder->appendOID (key, &oid) ;
            break ;
         }
         case BSONBOOLEAN :
         {
            plBSONBOOLEAN * pbool = (plBSONBOOLEAN *) SvIV(*hval) ;
            BOOLEAN t = pbool->getValue () ;
            objbuilder->appendBool (key, t) ;
            break ;
         }
         case BSONREGEX :
         {
            plBSONREGEX * pregex = (plBSONREGEX *) SvIV(*hval) ;
            const char * regexStr = pregex->getRegex () ;
            const char * optStr = pregex->getOption () ;
            objbuilder->appendRegex (key, regexStr, optStr) ;
            break ;
         }
         case BSONBINARY :
         {
            plBSONBINARY * pbinary = (plBSONBINARY *) SvIV(*hval) ;
            const char * buff = pbinary->getValue () ;
            objbuilder->appendBinData (key, sizeof (buff), BinDataGeneral, buff) ;
            break ;
         }
         case BSONCODE :
         {
            plBSONCODE * pcode = (plBSONCODE *) SvIV(*hval) ;                      
            const char * codestr = pcode->getValue () ;                          
            objbuilder->appendCode (key, codestr) ;
            break ;
         }
         case BSONDATE :
         {
            plBSONDATE * pPldate = (plBSONDATE *) SvIV(*hval) ;

            const Date_t date = pPldate->getValue () ;
            objbuilder->appendDate (key, date) ;
            break ;
         }
         case BSONMAXKEY :
         {
            objbuilder->appendMaxKey (key) ;
            break ;
         }
         case BSONMINKEY :
         {
            objbuilder->appendMinKey (key) ;
            break ;
         }

         default : break ;
      }
   
   }
}

bool av_to_bson (BSONArrayBuilder * objarraybuilder, SV * sv)
{
   AV * sav ;
   int svtp ;

   sav = (AV *) SvRV (sv) ;
   long arrnum = av_len (sav) ;
  
   for (int i = 0; i <= arrnum; ++i)
   {
      SV * aval = av_shift (sav) ;

      svtp = get_sv_type (aval) ;

      switch (svtp)
      {
         case HASH :
         {
            BSONObjBuilder buildertemp ;   
            BSONObj obj ;

            hv_to_bson (&buildertemp, aval) ;

            obj = buildertemp.obj () ;

            objarraybuilder->append (obj) ;
         }
            break ;
         case ARRAY :
         {
            BSONArrayBuilder bsonarraybuildertemp ;
            BSONArray objarraytemp ;

            av_to_bson (&bsonarraybuildertemp, aval) ;

            objarraytemp = bsonarraybuildertemp.arr () ;
 
            objarraybuilder->append (objarraytemp) ;
         }
            break ;
 
         case INT :
         {  
            long long  vllong = SvIV (aval) ;
            objarraybuilder->append (vllong) ;
         }
            break ;

         case DOUBLE :
         {
            double vldouble = SvNV (aval) ;
            objarraybuilder->append (vldouble) ;
         }
            break ;

         case STRING :
         {
            char * vlstring = SvPV_nolen (aval) ;
            objarraybuilder->append (vlstring) ;
         }
            break ;
         case BSONOID :
         {
            plBSONOID * poid = (plBSONOID *) SvIV(aval) ;
            const char * oidstr = poid->_getValue () ;
            OID oid ;
            oid.init (oidstr) ;
            objarraybuilder->append (oid) ;
            break ;
         }
         case BSONBOOLEAN :
         {
            plBSONBOOLEAN * pbool = (plBSONBOOLEAN *) SvIV(aval) ;
            BOOLEAN t = pbool->getValue () ;
            objarraybuilder->append (t) ;
            break ;
         }
/*
         case BSONREGEX :
         {
            plBSONREGEX * pregex = (plBSONREGEX *) SvIV(aval) ;
            const char * regexStr = pregex->getRegex () ;
            const char * optStr = pregex->getOption () ;

            objarraybuilder->append (t) ;
            break ;
         }
*/
/*
         case BSONCODE :
         {
            plBSONCODE * pcode = (plBSONCODE *) SvIV(aval) ;
            const char * codestr = pcode->getValue () ;
            objarraybuilder->append (&codestr) ;
            break ;
         }
*/
         case BSONDATE :
         {
            plBSONDATE * pPldate = (plBSONDATE *) SvIV(aval) ;
            const Date_t date = pPldate->getValue () ;

            objarraybuilder->append (date) ;
            break ;
         }
            //set_value_from_sdbclass_hv (objbuilder, key, *hval, svtp) ;
            //set_value_from_sdbclass_av (objarraybuilder, aval, svtp) ;
            break ;

         default : break ;
      }


   }

}


bool sv_to_bson (BSONObjBuilder * objbuilder, int svtp, SV * sv)
{

 
   switch (svtp)
   {
      case HASH :
         hv_to_bson (objbuilder, sv) ;
         break ;
      default : break ;
   }

}


/*
bool set_value_from_sdbclass_hv (BSONObjBuilder * objbuilder, const char * key, SV * sdbsv, int svtp)
{
   dSP;
   SV *ret;
   I32 count;
  
   const char * str ; 
   OID oid ;

   ENTER;
   SAVETMPS;

   PUSHMARK (SP);
   XPUSHs (sdbsv);
   PUTBACK;

   count = call_method ("_getValue", G_SCALAR);

   SPAGAIN;

   if (count != 1) {
      croak ("reader didn't return a value");
   }

   ret = POPs;
   SvREFCNT_inc (ret);

   PUTBACK;
   FREETMPS;
   LEAVE;

   str = SvPV_nolen (ret) ;
   switch (svtp)
   {
      case BSONOID :
         oid.init (str) ;
         objbuilder->appendOID (key, &oid) ;
         break ;
      case BSONREGEX :
  
      case BSONCODE :
 
      case BSONDATE :

      default :
         break ;

   }
   return true ;

}
*/
/*
bool set_value_from_sdbclass_av (BSONArrayBuilder * objarraybuilder, SV * sdbsv, int svtp)
{
   dSP;
   SV *ret;
   I32 count;

   const char * str ;
   OID oid ;

   ENTER;
   SAVETMPS;

   PUSHMARK (SP);
   XPUSHs (sdbsv);
   PUTBACK;

   count = call_method ("_getValue", G_SCALAR);

   SPAGAIN;

   if (count != 1) {
      croak ("reader didn't return a value");
   }

   ret = POPs;
   SvREFCNT_inc (ret);

   PUTBACK;
   FREETMPS;
   LEAVE;

   str = SvPV_nolen (ret) ;
   switch (svtp)
   {
      case BSONOID :
         oid.init (str) ;
         objarraybuilder->append (oid) ;
         break ;
      case BSONREGEX :

      case BSONCODE :

      case BSONDATE :

      default :
         break ;

   }
   return true ;
}
*/

bool encode_bson (BSONObjBuilder * objbuilder, SV * sv)
{
   int svtp = 0 ;
   svtp = get_sv_type (sv) ;
  
   if (svtp != HASH)
   {
      return false ;
   }

   sv_to_bson (objbuilder, svtp, sv) ;
  
}

bool bson_to_av (vector<BSONElement> * pbsoniter, AV * av) 
{
   vector<BSONElement>::iterator iter ;

   SV * value ;
   const char * str ;                                                                   
   const char * name ;
   BSONObj objtemp ;                                                                    
   HV * hvtemp = newHV () ;                                                             
   AV * avtemp = newAV () ;                                                             
   vector<BSONElement> bsoniter ;


   for (iter = pbsoniter->begin (); iter != pbsoniter->end (); ++iter)
   {
      BSONElement element = *iter ;
      switch (element.type ())
      {
         case NumberInt:
            value = newSViv (element._numberInt ()) ;
            break ;
         case NumberLong:
            value = newSViv (element._numberLong ()) ;
            break ;
         case String :
            str = element.String ().c_str () ;
            value = newSVpvn (str, strlen (str)) ;
            break ;
         case Array :
            bsoniter = element.Array () ;
            bson_to_av (&bsoniter, avtemp) ;
            value = newRV_noinc ((SV *) avtemp) ;
            break ;

         case NumberDouble :
            value = newSVnv (element._numberDouble ()) ;
            break ;
         case Object :
            objtemp = element.Obj () ;
            bson_to_hv (&objtemp, hvtemp) ;
            value = newRV_noinc ((SV *)hvtemp) ;
            break ;

         case jstOID :
         {

            SV * tmpsv  = newSV(1) ;
            OID oid ;
            plBSONOID * poid ;
            const char * oidstr ;
            oid = element.OID () ;
            //oidstr = oid.toString ().c_str () ;
            poid = new plBSONOID (oid) ;
            sv_setref_pv (tmpsv, "SequoiaDB::BSON::OID", (void *) poid) ;
            value = tmpsv ; 
            break ;
         }
         case RegEx :
         {

         }
         case Code :
         {

         }
         case Date :
         {
 
         }
         case Bool :
         {

         }
         case BinData :
         {

         }
            break ;
         default :
            break ;
      }
 
      av_push (av, value) ;
   }
}

bool bson_to_hv (BSONObj * obj, HV * hv)
{
   SV * value ;
   const char * str ;
   BSONObjIterator bsoniterator (*obj) ;
   const char * name ;
   BSONObj objtemp ;
   HV * hvtemp = newHV () ;
   AV * avtemp = newAV () ;
   vector<BSONElement> bsoniter ;
   while (bsoniterator.more())
   {
      BSONElement element = bsoniterator.next () ;
      name = element.fieldName () ;
      //warn ("key is %s", name) ;
      switch (element.type ())
      {
         case NumberInt:
            value = newSViv (element._numberInt ()) ;
            
            break ; 
         case NumberLong:
            value = newSViv (element._numberLong ()) ;
            break ;
         case String :
            str = element.String ().c_str () ; 
            value = newSVpvn (str, strlen (str)) ; 
            break ;
         case Array :
            bsoniter = element.Array () ;
            bson_to_av (&bsoniter, avtemp) ; 
            value = newRV_noinc ((SV *) avtemp) ;
            break ;

         case NumberDouble :
            value = newSVnv (element._numberDouble ()) ; 
            break ;
         case Object :
            objtemp = element.Obj () ;
            bson_to_hv (&objtemp, hvtemp) ;
            value = newRV_noinc ((SV *)hvtemp) ;
            break ;
         case jstOID :
         {
            SV * tmpsv  = newSV(1) ;
            OID oid ;
            plBSONOID * poid ;
            oid = element.OID () ;
            //const char * oidstr ;
            //oidstr = oid.toString ().c_str () ;
            poid = new plBSONOID (oid) ;
            sv_setref_pv (tmpsv, "SequoiaDB::BSON::OID", (void *) poid) ;
            value = tmpsv ; 
            break ;
         }
         case RegEx :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONREGEX * pregex ;
            const char * regexStr = element.regex () ;
            const char * optStr = element.regexFlags () ;

            pregex = new plBSONREGEX (regexStr, optStr) ;
            sv_setref_pv (tmpsv, "SequoiaDB::BSON::REGEX", (void *) pregex) ;
            value = tmpsv ;
            break ;
         }
         case Code :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONCODE * pcode ;
            const char * pcodestr = element.codeWScopeScopeData () ;

            pcode = new plBSONCODE (pcodestr) ;
            sv_setref_pv (tmpsv, "SequoiaDB::BSON::CODE", (void *) pcode) ;
            value = tmpsv ;
            break ;

         }
         case Date :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONDATE * pdate ;
            Date_t date = element.date () ;

            pdate = new plBSONDATE (date.millis) ;

            sv_setref_pv (tmpsv, "SequoiaDB::BSON::DATE", (void *) pdate) ;
            value = tmpsv ;
            break ;
 
         }
         case Bool :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONBOOLEAN * pbool ;
            bool tbool = element.Bool () ;
         
            if (tbool)
               pbool = new plBSONBOOLEAN (TRUE) ;
            else
               pbool = new plBSONBOOLEAN (FALSE) ;

            sv_setref_pv (tmpsv, "SequoiaDB::BSON::BOOLEAN", (void *) pbool) ;
            value = tmpsv ;
            break ;
         }
         case BinData :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONBINARY * pbinary ;
            int len ;
            const char * binary = element.binData (len) ;
         
            pbinary = new plBSONBINARY (binary) ;

            sv_setref_pv (tmpsv, "SequoiaDB::BSON::BINARY", (void *) pbinary) ;
            value = tmpsv ;
            break ;

         }
         case MaxKey :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONMAXKEY * pmaxkey ;
         
            pmaxkey = new plBSONMAXKEY () ;

            sv_setref_pv (tmpsv, "SequoiaDB::BSON::MaxKey", (void *) pmaxkey) ;
            value = tmpsv ;
            break ;
         }
         case MinKey :
         {
            SV * tmpsv  = newSV(1) ;
            plBSONMINKEY * pminkey ;
         
            pminkey = new plBSONMINKEY () ;

            sv_setref_pv (tmpsv, "SequoiaDB::BSON::MinKey", (void *) pminkey) ;
            value = tmpsv ;
            break ;
         }
         default :
            break ;
      }
      
      if (!hv_store (hv, name, strlen (name), value, 0))
      //if (!hv_store (hv, name, strlen (name), value, 0))
      {
         croak ("failed storing value in hash") ;
      }
   }
}

bool check_av_isAllHv (SV * sv)
{
   int svtp = get_sv_type (sv) ;
   int av_elm_type ;
   if (svtp != ARRAY)
   {
      croak ("must be array") ;
   }
   AV * sav = (AV *) SvRV (sv) ;
   long arrnum = av_len (sav) ;
   for (int i = 0; i <= arrnum; ++i)
   {
      SV * aval = av_shift (sav) ;
      av_elm_type = get_sv_type (aval) ;
      if (av_elm_type != HASH)
      {
         croak ("AV's element must be HASH") ;
      }
      av_push (sav, aval) ;
   }
   return true ;
}

bool getAv_HvElem (SV * sv, std::vector<bson::BSONObj> * pVec)
{
   int svtp = get_sv_type (sv) ;
   int av_elm_type ;
   if (svtp != ARRAY)
   {
      return false ;
   }
   AV * sav = (AV *) SvRV (sv) ;
   long arrnum = av_len (sav) ;
   for (int i = 0; i <= arrnum; ++i)
   {
      SV * aval = av_shift (sav) ;
      av_elm_type = get_sv_type (aval) ;
      if (av_elm_type == HASH)
      {
         BSONObjBuilder buildertemp ;
         BSONObj obj ;
         hv_to_bson (&buildertemp, aval) ;
         obj = buildertemp.obj () ;
         pVec->insert ((pVec->begin() + i), obj) ;
      }
   }
   return true ;
 
}

/*
void make_sdbclass_hv (BSONElement & element, SV * retsv)
{
  OID oid ;
  plBSONOID * poid ;
  const char * oidstr ;
  switch (element.type ())
  {
     case jstOID :
     {
        SV * tmpSv = sv_newmortal() ;
        oid = element.OID () ;
        oidstr = oid.toString ().c_str () ;
        poid = new plBSONOID(oidstr);
        sv_setref_pv(retsv, "SequoiaDB::BSON::OID", (void *) poid);
     }
        break ;
     case RegEx :
 
     case Code :
 
     case Date :

     defalue :
   
        break ;
  }
}
*/

bool decode_bson (BSONObj * obj, HV * hv)
{

    bson_to_hv (obj, hv) ;
   
}
