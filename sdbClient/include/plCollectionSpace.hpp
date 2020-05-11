#ifndef INCLUDE_PLCOLLECTIONSPACE_H
#define INCLUDE_PLCOLLECTIONSPACE_H 1
#include "client.hpp"
#include "plCollection.hpp"

using namespace sdbclient ;
using namespace bson ;
class plCollectionSpace
{
private:
   sdbCollectionSpace collectionspace ;
   plCollection * pPlcollection ;
public:
   plCollectionSpace () ;
   plCollection * getCollection (const char *) ;
   plCollection * createCollection (const char *, SV * sv = NULL) ;
   bool dropCollection (const char *) ;
   const char * getCSName () ;
   sdbCollectionSpace * getCollectionSpacePoint () ;
   ~plCollectionSpace () ;

};
#endif
