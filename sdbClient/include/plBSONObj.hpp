#ifndef INCLUDE_PLBSONOBJ_H
#define INCLUDE_PLBSONOBJ_H 1
#include "client.hpp"
#include "perl_sequoiadb.hpp"

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
//#include "ppport.h"

using namespace sdbclient ;
using namespace bson ;
class plBSONObj
{
private:
   BSONObj bsonObj ;
   BSONObjBuilder bsonBuilder ;
public:
   plBSONObj (SV *) ;

   bool put (const char *, const char *) ;
   bool put (const char *, int) ;
   bool put (const char *, float) ;
   bool put (const char *, double) ;
   bool put (const char *, bool) ;
   const char * toString () ;
   SV * toString2 () ;
   const char * get (const char *) ;
   void setBson (BSONObj) ;

   int toBson (SV *) ;
   int toBson2 (SV *) ;

   SV * getBson (SV *) ;

   ~plBSONObj () ;
   
};

#endif
