#ifndef BSONCODE_H
#define BSONCODE_H 1

#include "client.hpp"

using namespace sdbclient ;

class plBSONCODE
{
private :
   char * buff ;
public :
   plBSONCODE (const char * value = NULL) ;
   const char * getValue () ;
   void setValue (const char *) ;

} ;
#endif 
