#ifndef BSONBINARY_H
#define BSONBINARY_H 1

#include "client.hpp"

class plBSONBINARY
{
private :
   char * buff ;
public :
   plBSONBINARY (const char * value = NULL) ;
   const char * getValue () ;
   void setValue (const char *) ;

} ;
#endif 
