#include "plCursor.hpp"

plCursor::plCursor ()
{
}



SV * plCursor::next(SV * sv)
{
   int rc = 0 ;
   SV * retsv ;
   BSONObj obj ;
   rc = cursor.next (obj) ;

   if (rc == SDB_OK)
   {
      if (sv == NULL)
      {
         HV * ret = newHV () ;
         decode_bson (&obj, ret) ;
         retsv = newRV_noinc ((SV *) ret) ;
         return retsv ;
      }
      else
      {
         const char * str = obj.toString ().c_str () ;
         retsv = newSVpvn (str, strlen (str)) ;
         return retsv ;
      }
   }
   else
   {
        return newSVsv(&PL_sv_undef) ;
   }
}

SV * plCursor::current (SV * sv)
{
   int rc = 0 ;
   SV * retsv ;
   BSONObj obj ;
   rc = cursor.current (obj) ;

   if (rc == SDB_OK)
   {
      if (sv == NULL)
      {
         HV * ret = newHV () ;
         decode_bson (&obj, ret) ;
         retsv = newRV_noinc ((SV *) ret) ;
         return retsv ;
      }
      else
      {
         const char * str = obj.toString ().c_str () ;
         retsv = newSVpvn (str, strlen (str)) ;
         return retsv ;
      }
   }
   else
   {
        return newSVsv(&PL_sv_undef) ;
   }
}


sdbCursor * plCursor::getCursorPoint ()
{
   return & cursor ;

}
plCursor::~plCursor () 
{
}
