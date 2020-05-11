#include "plCollection.hpp"

plCollection::plCollection (){}


//plCursor * plCollection::query (const char * pQuery, const char * pSelector, const char * pOrderby, const char * pHint)
plCursor * plCollection::query (SV * querysv, SV * selectorsv,
                                SV * orderbysv, SV * hintsv,
                                long numToSkip, long numToReturn, 
                                int flag)
{
   //collection.query (pQuery, pSelector, pOrderby, pHint, cursor);

   BSONObj query, selector, orderby, hint ;
   if (querysv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, querysv) ;

      query = objbuilder.obj () ;
   }
   if (selectorsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, selectorsv) ;

      selector = objbuilder.obj () ;
   }
   if (orderbysv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, orderbysv) ;

      orderby = objbuilder.obj () ;
   }
   if (hintsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, hintsv) ;

      hint = objbuilder.obj () ;
   }
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;
   //pPlcursor->query (&collection, query, selector, orderby, hint) ;
   int rc = collection.query (* pSdbCursor, query, selector, 
                       orderby, hint, numToSkip, numToReturn, flag) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlcursor ;
}

bool plCollection::bulkInsert (SV * sv, int flag)
{
   check_av_isAllHv (sv) ;
   std::vector<bson::BSONObj> vec ;
   bool getElmSuc = getAv_HvElem (sv, &vec) ;
   if (getElmSuc != true)
   {
      croak ("Array to Vector fail\n") ;
   }
 
   int rc = collection.bulkInsert (flag, vec) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plCollection::insert (SV * sv)
{
   BSONObjBuilder objbuilder ;

   encode_bson (&objbuilder, sv) ;

   BSONObj obj = objbuilder.obj () ;

   int rc = collection.insert (obj) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;

}

long long plCollection::count (SV * sv)
{
   long long countNum ;
   int rc = SDB_OK ;
   if (sv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, sv) ;

      BSONObj obj = objbuilder.obj () ;
      rc = collection.getCount (countNum, obj) ;
   }
   else
   {
      BSONObj obj ;
      rc = collection.getCount (countNum, obj) ;
   }
   checkOutRcType(rc, RCLANGUAGE) ;
   return countNum ;
}

const char * plCollection::getCLName ()
{
   const char * pClName = collection.getCollectionName () ;
   return pClName ;

}

const char * plCollection::getCSName ()
{
   const char * pCSName = collection.getCSName () ;
   return pCSName ;
}

const char * plCollection::getFullName ()
{
   const char * pFullName = collection.getFullName () ;
   return pFullName ; 
}

sdbCollection * plCollection::getCollectionPoint ()
{
   return & this->collection ;
}

plLob * plCollection::createLob (const char * oidStr)
{
   plLob * pPlLob = new plLob () ;
   sdbLob * pSdbLob = pPlLob->getLobPoint () ;
   OID oid ;
   if (oidStr == NULL)
   {
      oid.init () ;
   }
   else
   { 
      string s (oidStr) ;
      oid.init (s) ;
   }
   int rc = collection.createLob (*pSdbLob, &oid) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlLob ;
   
}

bool plCollection::removeLob (const char * oidStr)
{
   OID oid ;
   string s (oidStr) ;
   oid.init (s) ;
   int rc = collection.removeLob (oid) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;

}

plLob * plCollection::openLob (const char * oidStr)
{
   plLob * pPlLob = new plLob () ;
   sdbLob * pSdbLob = pPlLob->getLobPoint () ;
   OID oid ;
   string s (oidStr) ;
   oid.init (s) ;

   int rc = collection.openLob (*pSdbLob, oid) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlLob ;
}

plCursor * plCollection::listLobs ()
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;
   int rc = collection.listLobs (*pSdbCursor) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlcursor ;
}

plCursor * plCollection::explain (SV * conditionsv, SV * selectorsv,
                                   SV * orderbysv, SV * hintsv,
                                   long numToSkip, long numToReturn, 
                                   int flag, SV * optionsv)
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;

   BSONObjBuilder bcondition ;
   encode_bson (&bcondition, conditionsv) ;
   BSONObj conditionObj ;
   if (conditionsv != NULL)
      conditionObj = bcondition.obj () ;

   BSONObjBuilder bselector ;
   encode_bson (&bselector, selectorsv) ;
   BSONObj selectorObj ;
   if (selectorsv != NULL)
      selectorObj = bselector.obj () ;
 
   BSONObjBuilder borderby ;
   encode_bson (&borderby, orderbysv) ;
   BSONObj orderbyObj ;
   if (orderbysv != NULL)
      orderbyObj = borderby.obj () ;  

   BSONObjBuilder bhint ;
   encode_bson (&bhint, hintsv) ;
   BSONObj hintObj ;
   if (hintsv != NULL)
      hintObj = bhint.obj () ;

   BSONObjBuilder boption ;
   encode_bson (&boption, optionsv) ;
   BSONObj optionObj ;
   if (optionsv != NULL)
      optionObj = boption.obj () ;

   int rc = collection.explain (*pSdbCursor, conditionObj,
                                selectorObj, orderbyObj,
                                hintObj, numToSkip, 
                                numToReturn, flag,
                                optionObj) ;
   checkOutRcType(rc, RCLANGUAGE) ; 
   return pPlcursor ;

}

bool plCollection::update (SV * rulesv, SV * conditionsv, SV * hintsv)
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;
   
   BSONObj ruleObj, conditionObj, hintObj ;
   if (rulesv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, rulesv) ;

      ruleObj = objbuilder.obj () ;
   }

   if (conditionsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, conditionsv) ;

      conditionObj = objbuilder.obj () ;
   }
 
   if (hintsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, hintsv) ;

      hintObj = objbuilder.obj () ;
   }

   int rc = collection.update (ruleObj, conditionObj, hintObj) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return pPlcursor ;

}

bool plCollection::upsert (SV * rulesv, SV * conditionsv, SV * hintsv)
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;
   
   BSONObj ruleObj, conditionObj, hintObj ;
   if (rulesv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, rulesv) ;

      ruleObj = objbuilder.obj () ;
   }

   if (conditionsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, conditionsv) ;

      conditionObj = objbuilder.obj () ;
   }
 
   if (hintsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, hintsv) ;

      hintObj = objbuilder.obj () ;
   }

   int rc = collection.upsert (ruleObj, conditionObj, hintObj) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return pPlcursor ;
}

bool plCollection::createIndex (const char * indexName, SV * conditionsv, 
                                SV * isUniquesv, SV * enforcedsv)
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;
   
   BOOLEAN isUnique = FALSE, enforced = FALSE ;
  
   BSONObj conditionObj ;  
   if (conditionsv != NULL) 
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, conditionsv) ;

      conditionObj = objbuilder.obj () ;
   }
   
   if (isUniquesv != NULL)
   {
      int svtp = get_sv_type (isUniquesv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (isUniquesv) ;
            if (value != 0)
              isUnique = TRUE;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (isUniquesv) ;
            if (value != 0)
               isUnique = TRUE ;
            break ;
         }
         case STRING :
         {
            char * value = SvPV_nolen (isUniquesv) ;
            int strSize = sizeof (value) ;
            for (int i = 0; i < strSize; ++i)
            {
               if (value[i] >= 'A' && value[i] <= 'Z') 
                  value[i] = value[i] + 32 ;
            }
            if (0 == strcmp (value, "true"))
               isUnique = TRUE ;
            break ;
         }
      }
   } 

   if (enforcedsv != NULL)
   {
      int svtp = get_sv_type (enforcedsv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (isUniquesv) ;
            if (value != 0)
              enforced = TRUE;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (isUniquesv) ;
            if (value != 0)
               enforced = TRUE ;
            break ;
         }
         case STRING :
         {
            char * value = SvPV_nolen (isUniquesv) ;
            int strSize = sizeof (value) ;
            for (int i = 0; i < strSize; ++i)
            {
               if (value[i] >= 'A' && value[i] <= 'Z') 
                  value[i] = value[i] + 32 ;
            }
            if (0 == strcmp (value, "true"))
               enforced = TRUE ;
            break ;
         }
      }
   } 


   int rc = collection.createIndex (conditionObj, indexName,
                                    isUnique, enforced) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
   
}

plCursor * plCollection::listIndexes (const char * indexName)
{
   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;

   int rc = collection.getIndexes (*pSdbCursor, indexName) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return pPlcursor ;
   
 
}

bool plCollection::remove (SV * conditionsv,SV * hintsv)
{
   BSONObj conditionObj, hintObj ;

   if (conditionsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, conditionsv) ;

      conditionObj = objbuilder.obj () ;
   }

   if (hintsv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, hintsv) ;

      hintObj = objbuilder.obj () ;
   }

   int rc = collection.del (conditionObj, hintObj) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return true ;

}

//plCursor * plCollection::getIndexes (const char *)
//{
//
//}

bool plCollection::split (const char * sourceGroup, 
                          const char * targetGroup,
                          SV * conditionsv, 
                          SV * staticsv)
{
   double percent ;
   int rc ;
   if (staticsv == NULL)
   {
      int svtp = get_sv_type (conditionsv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (conditionsv) ;
            percent = value ;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (conditionsv) ;
            percent = value ;
            break ;
         }
         case STRING :
         {
            const char * value = SvPV_nolen (conditionsv) ;
            double t = atof (value) ;
            percent = t ;
            break ;
         }
      } 
      rc = collection.split (sourceGroup, targetGroup, percent) ;

   }
   else
   {
      BSONObjBuilder bcondition, bstatic ; 

      encode_bson (&bcondition, conditionsv) ;

      BSONObj conditionObj = bcondition.obj () ;
     
      encode_bson (&bstatic, staticsv) ;
    
      BSONObj staticObj = bstatic.obj () ;
   
      rc = collection.split (sourceGroup, targetGroup, conditionObj, staticObj) ;
   }

   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;

}

SINT64 plCollection::splitAsync (const char * sourceGroup, 
                               const char * targetGroup,
                               SV * conditionsv, 
                               SV * staticsv)
{
   double percent ;
   int rc ;
   SINT64 taskid ;
   if (staticsv == NULL)
   {
      int svtp = get_sv_type (conditionsv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (conditionsv) ;
            percent = value ;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (conditionsv) ;
            percent = value ;
            break ;
         }
         case STRING :
         {
            const char * value = SvPV_nolen (conditionsv) ;
            double t = atof (value) ;
            percent = t ;
            break ;
         }
      } 
      rc = collection.splitAsync (sourceGroup, targetGroup, percent, taskid) ;

   }
   else
   {
      BSONObjBuilder bcondition, bstatic ; 

      encode_bson (&bcondition, conditionsv) ;

      BSONObj conditionObj = bcondition.obj () ;
     
      encode_bson (&bstatic, staticsv) ;
    
      BSONObj staticObj = bstatic.obj () ;
   
      rc = collection.splitAsync (taskid, sourceGroup, targetGroup, conditionObj, staticObj) ;
   }

   checkOutRcType(rc, RCLANGUAGE) ;
   return taskid ;


}

bool plCollection::alterCollection (SV * sv)
{

   BSONObjBuilder objbuilder ;

   encode_bson (&objbuilder, sv) ;

   BSONObj obj = objbuilder.obj () ;

   int rc = collection.alterCollection (obj) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return true ;

}

bool plCollection::attachCollection (const char * sdbFullName, SV * sv)
{
   BSONObjBuilder objbuilder ;

   encode_bson (&objbuilder, sv) ;

   BSONObj obj = objbuilder.obj () ;
 
   int rc = collection.attachCollection (sdbFullName, obj) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return true ;

}

bool plCollection::detachCollection (const char * sdbFullName)
{
   int rc = collection.detachCollection (sdbFullName) ;
  
   checkOutRcType(rc, RCLANGUAGE) ;

   return true ;
}

plCursor * plCollection::aggregate (SV * sv)
{
   check_av_isAllHv (sv) ;
   std::vector<bson::BSONObj> vec ;
   bool getElmSuc = getAv_HvElem (sv, &vec) ;
   if (getElmSuc != true)
   {
      croak ("Array to Vector fail\n") ;
   }

   plCursor * pPlcursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlcursor->getCursorPoint () ;

   int rc = collection.aggregate (*pSdbCursor, vec) ;
   
   checkOutRcType(rc, RCLANGUAGE) ;

   return pPlcursor ;
}

plCollection::~plCollection () 
{
}
