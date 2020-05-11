#include "plCollectionSpace.hpp"

plCollectionSpace::plCollectionSpace () {}

plCollection * plCollectionSpace::getCollection (const char * pCollectionName)
{
   pPlcollection = new plCollection () ;
   sdbCollection * pCollection = pPlcollection->getCollectionPoint () ;
   //pPlcollection->getCollection (&collectionspace, pCollectionName) ;
   int rc = collectionspace.getCollection (pCollectionName, * pCollection) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlcollection ;
}

plCollection * plCollectionSpace::createCollection (const char * pCollectionName, SV * sv)
{
   pPlcollection = new plCollection () ;
   sdbCollection * pCollection = pPlcollection->getCollectionPoint () ;
   int rc = SDB_OK ; 
   if (sv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, sv) ;

      BSONObj obj = objbuilder.obj () ;
      rc = collectionspace.createCollection (pCollectionName,
                                                 obj,
                                                 *pCollection) ;
   }
   else
   {
      rc = collectionspace.createCollection (pCollectionName, *pCollection) ; 
   }
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlcollection ;
}

bool plCollectionSpace::dropCollection (const char * pCollectionName)
{
   int rc = collectionspace.dropCollection (pCollectionName) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

const char * plCollectionSpace::getCSName ()
{
   const char * pCsName = collectionspace.getCSName () ;
   return pCsName ;
}

sdbCollectionSpace * plCollectionSpace::getCollectionSpacePoint ()
{
   return & this->collectionspace ;
}

plCollectionSpace::~plCollectionSpace () 
{
}
