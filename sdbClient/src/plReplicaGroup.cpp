#include "plReplicaGroup.hpp"

plReplicaGroup::plReplicaGroup () {}

sdbReplicaGroup * plReplicaGroup::getPlReplicaGroupPoint ()
{
   return & this->replGroup ;
}

plNode * plReplicaGroup::createNode (const char * hostname,
                                     SV * serviceNameSv,
                                     const char * pDatabasePath,
                                     SV * sv)
{
   int rc = SDB_OK ;
   const char * serviceName ;
   int svtp = get_sv_type (serviceNameSv) ;
   std::map< std::string, std::string > config ;
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

      BSONObj obj = objbuilder.obj () ;

      BSONObjIterator bsoniterator (obj) ;

      string value ;

      while (bsoniterator.more ())
      {
         BSONElement element = bsoniterator.next () ;
         string key (element.fieldName ()) ;

         switch (element.type ())
         {
            case NumberInt :
            {
               int t = element._numberInt () ;
               ostringstream os ;
               os << t ;
               istringstream is (os.str()) ;
               is >> value ;
               break ;
            }
            case NumberLong :
            {
               long t = element._numberLong () ;
               ostringstream os ;
               os << t ;
               istringstream is (os.str()) ;
               is >> value ;
               break ;
            }
            case String :
            {
               value = element.String () ;
               break ;
            }
            case NumberDouble :
            {
               double t = element._numberDouble () ;
               ostringstream os ;
               os << t ;
               istringstream is (os.str()) ;
               is >> value ;
               break ;
            }
            default :
               break ;
        
         }
         config.insert (map<string, string>::value_type (key, value)) ;
      }
   }
   rc = replGroup.createNode (hostname, serviceName, pDatabasePath, config) ;
   checkOutRcType(rc, RCLANGUAGE) ;
 

   plNode * pPlNode = new plNode () ;
   sdbNode * pSdbNode = pPlNode->getSdbNodePoint () ;
   rc = replGroup.getNode (hostname, serviceName, *pSdbNode) ;

   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlNode ;


}

plNode * plReplicaGroup::getNode (const char * hostname, SV * serviceNameSv)
{
   const char * serviceName ;
   int svtp = get_sv_type (serviceNameSv) ;
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
   plNode * pPlNode = new plNode () ;
   sdbNode * pSdbNode = pPlNode->getSdbNodePoint () ;
   int rc = replGroup.getNode (hostname, serviceName, *pSdbNode) ;

   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlNode ;

}

plNode * plReplicaGroup::getMaster ()
{
   plNode * pPlNode = new plNode () ;
   sdbNode * pSdbNode = pPlNode->getSdbNodePoint () ;
   int rc = replGroup.getMaster (*pSdbNode) ;

   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlNode ;


}

plNode * plReplicaGroup::getSlave ()
{
   plNode * pPlNode = new plNode () ;
   sdbNode * pSdbNode = pPlNode->getSdbNodePoint () ;
   int rc = replGroup.getSlave (*pSdbNode) ;

   checkOutRcType(rc, RCLANGUAGE) ;
   return pPlNode ;

}

bool plReplicaGroup::removeNode (const char * hostname, SV * serviceNameSv)
{
   const char * serviceName ;
   int svtp = get_sv_type (serviceNameSv) ;
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
   int rc = replGroup.removeNode (hostname, serviceName) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plReplicaGroup::start ()
{
   int rc = replGroup.start () ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plReplicaGroup::stop ()
{
   int rc = replGroup.stop () ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
   
}

const char * plReplicaGroup::getName ()
{
   const char * name = replGroup.getName () ;
   return name ;
}

bool plReplicaGroup::isCatalog ()
{
   bool iscatalog = replGroup.isCatalog () ;
   return iscatalog ;

}

/*
int plReplicaGroup::getNodeNum ()
{

}
*/


plReplicaGroup::~plReplicaGroup () {}
