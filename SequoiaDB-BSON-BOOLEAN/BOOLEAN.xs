#ifdef __cplusplus
extern "C"{
#endif

#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifdef __cplusplus
}
#endif

#include "ppport.h"

#include "plBSONBOOLEAN.hpp"

using namespace std ;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::BSON::BOOLEAN		PACKAGE = SequoiaDB::BSON::BOOLEAN		

plBSONBOOLEAN *
plBSONBOOLEAN::new (sv = NULL)
              SV * sv

void
plBSONBOOLEAN::setValue (sv)
              SV * sv

int
plBSONBOOLEAN::getValue ()

void
plBSONBOOLEAN::DESTROY ()
