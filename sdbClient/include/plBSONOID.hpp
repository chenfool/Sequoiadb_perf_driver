#ifndef INCLUDE_PLBSONOID_H
#define INCLUDE_PLBSONOID_H 1

#include "client.hpp"
#include "perl_sequoiadb.hpp"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

using namespace sdbclient ;
using namespace bson ;

class plBSONOID
{
private:
   OID oid ;
public:
   bool gen () ;
   plBSONOID (const char * str = NULL) ;
   plBSONOID (OID oid) ;
   const char * _getValue () ;
   const char * toString () ;
   bool _setValue (SV *) ;

   ~plBSONOID () ;
} ;

#endif
