#include "plBSONBINARY.hpp"

plBSONBINARY::plBSONBINARY (const char * value)
{
   if (value != NULL)
   {
      buff = new char[sizeof (value)] ;
      strcpy (buff, value) ;
   }
}

void plBSONBINARY::setValue (const char * value)
{
   if (buff != NULL)
      delete [] buff ;
   buff = new char[sizeof (value)] ;
   strcpy (buff, value) ;
}

const char * plBSONBINARY::getValue ()
{
   // TODO test perl if use buff addr, or new addr ?
   if (buff != NULL)
      return buff ;
   else
      return "" ;
   
}

