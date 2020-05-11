#include "plBSONObj.hpp"

plBSONObj::plBSONObj (SV * sv)
{
    BSONObjBuilder objbuilder ;

    encode_bson (&objbuilder, sv) ;

    BSONObj obj = objbuilder.obj () ;
   
    this->bsonObj = obj ;
}

/*
bool plBSONObj::put (const char * key, const char * value)
{ 
   this->bsonBuilder.append(key, value) ;
   this->bsonObj = this->bsonBuilder.obj() ; 
}

bool plBSONObj::put (const char * key, int value)
{
   this->bsonBuilder.append(key, value) ;
   this->bsonObj = this->bsonBuilder.obj() ; 
}

void plBSONObj::setBson (BSONObj obj)
{
   this->bsonObj = obj ;
}
*/
const char * plBSONObj::toString ()
{
   return this->bsonObj.toString().c_str() ;
}

/*
SV * plBSONObj::toString2()
{
   const char * str = this->bsonObj.toString().c_str() ;

   SV * retsv = newSVpvn (str, strlen(str)) ;
   
   return retsv ;
}
const char * plBSONObj::get (const char * key)
{
   BSONElement ele = this->bsonObj.getField(key) ;
   return ele.valuestr();
}

*/
int  plBSONObj::toBson (SV * sv)
{
   HE * he ;
   HV * hv ;
   /*
   if (SvTYPE (SvRV(sv)) == SVt_PVHV)
   {
      return 1 ;
   }
   else
   {
      return 0 ;
   }
   */


   if (!SvROK (sv) && (SvTYPE (SvRV (sv)) ==  SVt_PVHV))
   {
      croak ("Input value is Hash\n") ;
   }

   if (SvTYPE (SvRV (sv)) ==  SVt_PVHV)
   {   
      hv = (HV *) SvRV (sv) ;
      (void) hv_iterinit (hv) ;
      while ((he = hv_iternext (hv)))
      {
         SV ** hval ;
         STRLEN len ;
         const char * key = HePV (he, len) ;
         warn ("This is a test , test, hash key is %s\n", key) ;
         //uint32_t utf8 = HeUTF8 (he) ;
         //containsNullChar (key, len) ;
         long valuelong ;
         double valuedouble ;
         char * valuechar ;
         AV * valueav ;
         int arrnum ;
         if ((hval = hv_fetch (hv, key, true ? -len : len, 0)) == 0)
         {
            croak ("could not find hash value for key %s, len:%lu\n", key, len);
         }
/*
         if (SvPOK (*hval))
         {
            valuechar = SvPV_nolen (*hval) ;
            warn ("value is %s\n", valuechar) ;
         }

         if (SvIOK (*hval))
         {
            valuelong = SvIV (*hval) ;
            warn ("value is %ld\n", valuelong) ;
         }
         if (SvNOK (*hval))
         {
            valuedouble = SvNV (*hval) ;
            warn ("value is %f\n", valuedouble) ;
         }
*/
         if (!SvROK (*hval))
         {
            switch (SvTYPE (*hval))
            {
               case SVt_IV :
                  valuelong = SvIV (*hval) ;
                  warn ("value is %ld\n", valuelong) ;
                  break ;
               case SVt_NV :
                  valuedouble = SvNV (*hval) ;
                  warn ("value is %f\n", valuedouble) ;
                  break ;
               case SVt_PV :
                  valuechar = SvPV_nolen (*hval) ;
                  warn ("value is %s\n", valuechar) ;
                  break ;
               
            
            }
         }
         else
         {
            switch (SvTYPE (SvRV (*hval)))
            {
               case SVt_PVAV :
                  warn ("value is array \n") ;
                  valueav = (AV *) SvRV (*hval) ;
                  arrnum = av_len (valueav) ;
                  for (int i = 0; i <= arrnum; ++i)
                  {
                     SV * sv1 = av_shift (valueav) ;
                     warn ("array[%d] is %ld\n", i, SvIV (sv1)) ;
                  }
                  break ;
               case SVt_PVHV :
                  warn ("vale is hash\n") ;
                  break ;
            }
         }
      }
         
   }
}

int plBSONObj::toBson2(SV * sv)
{
    BSONObjBuilder objbuilder ;

    encode_bson (&objbuilder, sv) ;

    BSONObj obj = objbuilder.obj () ;

    warn ("hash is :\n%s", obj.toString().c_str()) ;

    return 0 ;
}

SV * plBSONObj::getBson(SV * sv)
{
    BSONObjBuilder objbuilder ;

    encode_bson (&objbuilder, sv) ;

    BSONObj obj = objbuilder.obj () ;

    warn ("hash is :\n%s", obj.toString().c_str()) ;

///////////////////////////////////

    HV * ret = newHV () ;

    decode_bson (&obj, ret) ;

    return newRV_noinc ((SV *)ret) ;
}

plBSONObj::~plBSONObj ()
{

}
