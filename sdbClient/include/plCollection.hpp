#ifndef INCLUDE_PLCOLLECTION_H
#define INCLUDE_PLCOLLECTION_H 1
#include "client.hpp"
#include "plCursor.hpp"
#include "plLob.hpp"
#include "plReplicaGroup.hpp"

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"



using namespace sdbclient ;
using namespace bson ;
class plCollection
{
private:
   sdbCollection collection ;
public:
   plCollection () ;
   //plCursor * query (const char *,const char *,const char *, const char *) ;
   plCursor * query (SV * querysv = NULL, SV * selectorsv = NULL,
                     SV * orderbysv = NULL, SV * hintsv = NULL,
                     long numToSkip = 0, long numToReturn = -1,
                     int flag = 0) ;
//   void getCollection (sdbCollectionSpace *, const char *) ;
   bool insert (SV *) ;
   bool bulkInsert (SV * sv, int flag = FLG_INSERT_CONTONDUP) ;
   sdbCollection * getCollectionPoint () ;
   long long count (SV * sv = NULL) ;
   const char * getCLName () ;
   const char * getCSName () ;
   const char * getFullName () ;
   plLob * createLob (const char * oidStr = NULL);
   bool removeLob (const char *) ;
   plLob * openLob (const char *) ;
   plCursor * listLobs () ;

   plCursor * explain (SV * conditionsv = NULL, SV * selectorsv = NULL, 
                       SV * orderbysv = NULL, SV * hintsv = NULL, 
                       long numToSkip = 0, long numToReturn = -1, 
                       int flag = 0, SV * optionsv = NULL) ;
   bool update (SV *, SV *, SV * hint = NULL) ;
   bool upsert (SV *, SV *, SV * hint = NULL) ;
   bool createIndex (const char *, SV *,
                     SV * isUniquesv = NULL, SV * enforcedsv = NULL) ;
   plCursor * listIndexes (const char * indexName = "") ;
   bool remove (SV *, SV * hintsv = NULL) ;
//   plCursor * getIndexes (const char *) ;
   bool split (const char *, const char *, SV *, SV * staticsv = NULL) ;
   SINT64 splitAsync (const char *, const char *, SV *, SV * staticsv = NULL) ;
   bool alterCollection (SV *) ;
   bool attachCollection (const char *, SV *) ;
   bool detachCollection (const char *) ;
   plCursor * aggregate (SV *) ;
   ~plCollection () ;
};
#endif
