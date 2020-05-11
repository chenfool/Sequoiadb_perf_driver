#ifndef BSONBOOLEAN_H
#define BSONBOOLEAN_H 1 

#include "perl_sequoiadb.hpp"
#include "client.hpp"

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

using namespace sdbclient ;
using namespace bson ;

class plBSONBOOLEAN
{
private :
   BOOLEAN value ;
public :

   plBSONBOOLEAN (SV * sv = NULL) ;
   plBSONBOOLEAN (BOOLEAN tbool = FALSE) ;
   void setValue (SV *) ;
   BOOLEAN getValue () ;
   ~plBSONBOOLEAN () ;

} ;

#endif
