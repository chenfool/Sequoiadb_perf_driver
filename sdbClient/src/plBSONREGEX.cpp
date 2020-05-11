#include "plBSONREGEX.hpp"

plBSONREGEX::plBSONREGEX (const char * regex, const char * opt)
{
   if (regex != NULL)
   {
      long regexSize = sizeof (regex) ;
      pRegexStr = new[regexSize] ;
      strcpy (pRegexStr, regex) ;
   }
   if (opt != NULL)
   {
      long optSize = sizeof (opt) ;
      pOption = new[optSize] ;
      strcpy (pOption, opt) ;
   }
}

void plBSONREGEX::setRegex (const char * regex)
{
   if (pRegexStr != NULL)
      delete[] pRegexStr ;
   long regexSize = sizeof (regex) ;
   pRegexStr = new[regexSize] ;
   strcpy (pRegexStr, regex) ;   
}

void plBSONREGEX::setOption (const char * opt)
{
   if (pOption != NULL)
      delete[] pOption ;
   long optSize = sizeof (opt) ;
   pOption = new[optSize] ;
   strcpy (pOption, opt) ;
}

const char * plBSONREGEX::getRegex ()
{
   return pRegexStr ;
}

const char * plBSONREGEX::getOption ()
{
   return pOption ;
}

plBSONREGEX::~plBSONREGEX ()
{ 
   if (pRegexStr != NULL)
      delete[] pRegexStr ;
   if (pOption != NULL)
      delete[] pOption ;
}
