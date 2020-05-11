#include "plBSONBOOLEAN.hpp"

plBSONBOOLEAN::plBSONBOOLEAN (BOOLEAN tbool)
{
   this->value = tbool ;
}

plBSONBOOLEAN::plBSONBOOLEAN (SV * sv)
{
   BOOLEAN t = FALSE ;
   if (sv != NULL)
   {
      int svtp = get_sv_type (sv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (sv) ;
            if (value != 0)
              t = TRUE;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (sv) ;
            if (value != 0)
               t = TRUE ;
            break ;
         }
         case STRING :
         {
            char * value = SvPV_nolen (sv) ;
            int strSize = sizeof (value) ;
            for (int i = 0; i < strSize; ++i)
            {
               if (value[i] >= 'A' && value[i] <= 'Z')
                  value[i] = value[i] + 32 ;
            }
            if (0 == strcmp (value, "true"))
               t = TRUE ;
            break ;
         }
      }
   }
   this->value = t ;
}
  
void plBSONBOOLEAN::setValue (SV * sv)
{
   BOOLEAN t = FALSE ;
   if (sv != NULL)
   {
      int svtp = get_sv_type (sv) ;
      switch (svtp)
      {
         case INT :
         {
            long value = SvIV (sv) ;
            if (value != 0)
              t = TRUE;
            break ;
         }
         case DOUBLE :
         {
            double value = SvNV (sv) ;
            if (value != 0)
               t = TRUE ;
            break ;
         }
         case STRING :
         {
            char * value = SvPV_nolen (sv) ;
            int strSize = sizeof (value) ;
            for (int i = 0; i < strSize; ++i)
            {
               if (value[i] >= 'A' && value[i] <= 'Z')
                  value[i] = value[i] + 32 ;
            }
            if (0 == strcmp (value, "true"))
               t = TRUE ;
            break ;
         }
      }
   }
   this->value = t ;
}

BOOLEAN plBSONBOOLEAN::getValue ()
{
   return this->value ;
}

plBSONBOOLEAN::~plBSONBOOLEAN ()
{}
