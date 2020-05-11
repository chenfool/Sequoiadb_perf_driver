#include "perl_sequoiadb.hpp"

plBSONDATE::plBSONDATE (unsigned long long mil)
{
   date.millis = mil ;
}

void plBSONDATE::setValue (unsigned long long mil)
{
   date.millis = mil ;
}

const Date_t plBSONDATE::getValue ()
{
   return date.millis ;
}

const char * plBSONDATE::toString ()
{
   string t = date.toString () ;
   return t.c_str () ;
}

plBSONDATE::~plBSONDATE ()
{
}
