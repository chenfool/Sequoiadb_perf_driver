#ifndef BSONDATE_H
#define BSONDATE_H 1

#include "client.hpp"

using namespace bson ;

class plBSONDATE
{
private :
   Date_t date ;
public :
   plBSONDATE (unsigned long long mil = 0) ;
   void setValue (unsigned long long) ;
   const Date_t getValue () ;
   const char * toString () ;
   ~plBSONDATE () ;
} ;

#endif
