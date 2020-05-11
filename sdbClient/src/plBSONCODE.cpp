#include "plBSONCODE.hpp"

plBSONCODE::plBSONCODE (const char * value)
{
   if (value != NULL)
   {
      buff = new char[sizeof (value)] ;
      strcpy (buff, value) ;
   }
}

void plBSONCODE::setValue (const char * value)
{
   if (buff != NULL)
      delete [] buff ;
   buff = new char[sizeof (value)] ;
   strcpy (buff, value) ;
}

const char * plBSONCODE::getValue ()
{
   // TODO test perl if use buff addr, or new addr ?
   if (buff != NULL)
      return buff ;
   else
      return "" ;
   
}

