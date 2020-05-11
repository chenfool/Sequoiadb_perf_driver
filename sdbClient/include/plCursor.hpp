#ifndef INCLUDE_PLCURSOR_H
#define INCLUDE_PLCURSOR_H 1
#include "client.hpp"
#include "plBSONObj.hpp"

#include "perl_sequoiadb.hpp"

using namespace sdbclient ;
using namespace bson ;
using namespace std ;
class plCursor
{
private:
   sdbCursor cursor ;
public:
   plCursor () ;
   //const char * next () ;
   SV * next (SV * sv = NULL) ;
   SV * current (SV * sv = NULL) ;
//   int query (sdbCollection *, BSONObj & query, BSONObj & selector, BSONObj & orderby, BSONObj & hint) ;
//   int listCollectionSpaces (sdb *) ;
//   int listCollections (sdb *) ;
   sdbCursor * getCursorPoint () ;
   
   ~plCursor () ;
  
};
#endif
