#ifndef BSONREGEX_H
#define BSONREGEX_H 1

#include "client.hpp"

using namespace sdbclient ;

class plBSONREGEX
{
private :
   const char * pRegexStr ;
   const char * pOption ;
public :

   plBSONREGEX (const char * regex = NULL, const char * opt = NULL) ;
   void setRegex (const char *) ;
   void setOption (const char *) ;
   const char * getRegex () ;
   const char *  getOption () ;
   ~plBSONREGEX () ;

} ;

#endif
