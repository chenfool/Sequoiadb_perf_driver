#include "plSequoiadb.hpp"
plSequoiadb::plSequoiadb (const char * pHostName, int Port, const char * pUsr, const char * pPasswd)
{
   connection.connect (pHostName, Port, pUsr, pPasswd) ;
}

plCollectionSpace * plSequoiadb::getCollectionSpace (const char * pCollectionSpaceName)
{
   pPlCollectionSpace = new plCollectionSpace () ;
   sdbCollectionSpace * pCollectionSpace = pPlCollectionSpace->getCollectionSpacePoint () ;
   //int rc = pPlCollectionSpace->getCollectionSpace (&connection, pCollectionSpaceName) ;
   int rc = connection.getCollectionSpace (pCollectionSpaceName, * pCollectionSpace) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlCollectionSpace ;
}

plCursor * plSequoiadb::listCollectionSpaces ()
{
   int rc ;
   plCursor * pPlCursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlCursor->getCursorPoint () ;
   rc = connection.listCollectionSpaces (*pSdbCursor) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlCursor ;
}

plCursor * plSequoiadb::listCollections ()
{
   int rc ;
   plCursor * pPlCursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlCursor->getCursorPoint () ;
   rc = connection.listCollections (*pSdbCursor) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlCursor ;
}

plCursor * plSequoiadb::listReplicaGroups ()
{
   int rc ;
   plCursor * pPlCursor = new plCursor () ;
   sdbCursor * pSdbCursor = pPlCursor->getCursorPoint () ;
   rc = connection.listReplicaGroups (*pSdbCursor) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlCursor ;
}

plCollectionSpace * plSequoiadb::createCollectionSpace (const char * pCollectionSpaceName, SV * sv)
{
   pPlCollectionSpace = new plCollectionSpace () ;
   sdbCollectionSpace * pCollectionSpace = pPlCollectionSpace->getCollectionSpacePoint () ;
   
   int csSize = SDB_PAGESIZE_4K ;
   int rc = SDB_OK ;
   if (sv == NULL)
   {
      //rc = pPlCollectionSpace->createCollectionSpace (&connection, pCollectionSpaceName, csSize) ;
      rc = connection.createCollectionSpace (pCollectionSpaceName, csSize, * pCollectionSpace) ;
      checkOutRcType(rc, RCLANGUAGE) ;
      return pPlCollectionSpace ;
   }
   // sv is not empty
   int svtp = get_sv_type (sv) ;
   switch (svtp)
   {
      case STRING :
      {
         const char * sizeStr = SvPV_nolen (sv) ;
         csSize = atoi (sizeStr) ;
         rc = connection.createCollectionSpace (pCollectionSpaceName, csSize, * pCollectionSpace) ;
         break ;
      }
      case INT :
      {
         long long  sizelong = SvIV (sv) ;
         csSize = sizelong ;
         rc = connection.createCollectionSpace (pCollectionSpaceName, csSize, * pCollectionSpace) ;
         break ;
      }
      case HASH :
      { 
         BSONObjBuilder objbuilder ;
         encode_bson (&objbuilder, sv) ;
         BSONObj obj = objbuilder.obj () ;

         rc = connection.createCollectionSpace (pCollectionSpaceName, obj, * pCollectionSpace) ;
         break ;
      }
      default : break ;
   }
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlCollectionSpace ;
   
}

bool plSequoiadb::dropCollectionSpace (const char * pCollectionSpaceName)
{
   int rc = SDB_OK ;
   rc = connection.dropCollectionSpace (pCollectionSpaceName) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plSequoiadb::disconnect ()
{
   connection.disconnect () ;
   return true ;
}

bool plSequoiadb::createUsr (const char * user, const char * passwd)
{
   int rc = connection.createUsr (user, passwd) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

plDomain * plSequoiadb::createDomain (const char * domainName, SV * sv)
{
   plDomain * pPlDomain = new plDomain () ;
   sdbDomain * pDomainObject = pPlDomain->getDomainPoint () ;
   BSONObjBuilder objbuilder ;
   encode_bson (&objbuilder, sv) ;
   BSONObj obj = objbuilder.obj () ;
   int rc = connection.createDomain (domainName,
                                    obj,
                                    *pDomainObject) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlDomain ;
}

bool plSequoiadb::dropDomain (const char * domainName)
{
   int rc = connection.dropDomain (domainName) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

plDomain * plSequoiadb::getDomain (const char * domainName)
{
   plDomain * pPlDomain = new plDomain () ;
   sdbDomain * pDomainObject = pPlDomain->getDomainPoint () ;
   int rc = connection.getDomain (domainName, *pDomainObject) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlDomain ;
}

plReplicaGroup * plSequoiadb::createRG (const char * pRgName)
{

   plReplicaGroup * pPlReplicaGroup = new plReplicaGroup () ;
   sdbReplicaGroup * pSdbReplicaGroup = pPlReplicaGroup->getPlReplicaGroupPoint () ;
   int rc = connection.createReplicaGroup (pRgName, *pSdbReplicaGroup) ;

   checkOutRcType(rc, RCLANGUAGE) ;

   return pPlReplicaGroup ;

}

plReplicaGroup * plSequoiadb::createCatalogRG (const char * hostname,
                                               SV * serviceNameSv,
                                               const char * pDatabasePath,
                                               SV * sv)
{
   int rc = SDB_OK ;
   const char * serviceName ; 
   int  svtp = get_sv_type (serviceNameSv) ;
   BSONObj obj ;
   switch (svtp)
   {
      case INT :
      {
         long vllong = SvIV (serviceNameSv) ;
         ostringstream os ;
         os << vllong ;
         istringstream is (os.str()) ;
         string str ;
         is >> str ; 
         serviceName = str.c_str () ;
      }
         break ;
      case STRING :
      {
         serviceName = SvPV_nolen (serviceNameSv) ;
      }
         break ;
      default :
         croak ("service must be a number\n") ;
         break ;
      
   }
   if (sv != NULL)
   {
      BSONObjBuilder objbuilder ;

      encode_bson (&objbuilder, sv) ;

      obj = objbuilder.obj () ;

   }
   rc = connection.createReplicaCataGroup (hostname, serviceName, pDatabasePath, obj) ;
   checkOutRcType(rc, RCLANGUAGE) ;

   plReplicaGroup * pPlReplicaGroup = new plReplicaGroup () ;
   sdbReplicaGroup * pSdbReplicaGroup = pPlReplicaGroup->getPlReplicaGroupPoint () ;
   rc = connection.getReplicaGroup (1, *pSdbReplicaGroup) ;

   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlReplicaGroup ;
}

plReplicaGroup * plSequoiadb::getRG (const char * pRgName)
{
   plReplicaGroup * pPlReplicaGroup = new plReplicaGroup () ;
   sdbReplicaGroup * pSdbReplicaGroup = pPlReplicaGroup->getPlReplicaGroupPoint () ;
   int rc = connection.getReplicaGroup (pRgName, *pSdbReplicaGroup) ;


   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlReplicaGroup ;
}




plSequoiadb::~plSequoiadb () 
{
}
