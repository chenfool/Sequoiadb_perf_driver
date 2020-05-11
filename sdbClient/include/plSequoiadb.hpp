#ifndef INCLUDE_PLSEQUOIADB_H
#define INCLUDE_PLSEQUOIADB_H 1
#include "client.hpp"
#include "plCollectionSpace.hpp"
#include "plDomain.hpp"
#include "plReplicaGroup.hpp"
#include "plCursor.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace sdbclient ;
using namespace bson ;
class plSequoiadb
{
private:
   sdb connection ;
   //sdbCollectionSpace collectionspace ;
   //sdbCollection collection ;
   //sdbCursor cursor ;
   plCollectionSpace * pPlCollectionSpace ;
   plCursor * pPlCursor ;
public:
   plSequoiadb (const char *, int, const char *, const char *) ;
//   bool hasError() ;
//   int getErrorCode() ;
//   int getRC() ;
   plCollectionSpace * getCollectionSpace (const char *) ;
   plCollectionSpace * createCollectionSpace (const char *, SV * sv = NULL) ;
   bool disconnect () ;
   bool dropCollectionSpace (const char *) ;
   bool createUsr (const char *, const char *) ;
   bool dropDomain (const char *) ;
   
   plCursor * listReplicaGroups () ;
   plCursor * listCollections () ;
   plCursor * listCollectionSpaces () ;
   plDomain * createDomain (const char *, SV * sv) ;
   plDomain * getDomain (const char *) ;
   plReplicaGroup * createRG (const char *) ;
   plReplicaGroup * createCatalogRG (const char *,
                                     SV *,
                                     const char *,
                                     SV * sv = NULL) ;
   plReplicaGroup * getRG (const char *) ;
   
   ~plSequoiadb () ;
};
#endif
