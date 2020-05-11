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

#include "plBSONCODE.hpp"

using namespace std ;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::BSON::CODE		PACKAGE = SequoiaDB::BSON::CODE		

plBSONCODE *
plBSONCODE::new (value = NULL)
               const char * value

const char *
plBSONCODE::getValue ()

void
plBSONCODE::setValue (value)
               const char * value

void
plBSONCODE::DESTROY ()
