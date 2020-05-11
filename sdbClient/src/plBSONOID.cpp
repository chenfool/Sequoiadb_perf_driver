#include "plBSONOID.hpp"

plBSONOID::plBSONOID(const char * str)
{
   if (str != NULL)
   {
      string s (str) ;
      this->oid.init (s) ;
   }
}

plBSONOID::plBSONOID(OID oid)
{
   this->oid = oid ;
}

bool plBSONOID::gen ()
{
   this->oid.init () ;
   return true ;
}

const char * plBSONOID::_getValue ()
{
   const string str = this->oid.toString () ;
   const char * cstr = str.c_str () ;
   return cstr ;

//   SV * retsv = newSVpvn (cstr, strlen (cstr)) ;
//   return retsv ;
}

bool plBSONOID::_setValue (SV * sv)
{
   const char * cstr = SvPV_nolen (sv) ;
   this->oid.init (cstr) ;
   return true ;
}

const char * plBSONOID::toString ()
{
   const char * cstr = this->oid.toString ().c_str () ;   
   return cstr ;
}

plBSONOID::~plBSONOID () {}
