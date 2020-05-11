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

#include "plBSONBINARY.hpp"


MODULE = SequoiaDB::BSON::BINARY		PACKAGE = SequoiaDB::BSON::BINARY		

plBSONBINARY *
plBSONBINARY::new (value = NULL)
               const char * value

const char *
plBSONBINARY::getValue ()

void
plBSONBINARY::setValue (value)
               const char * value

void
plBSONBINARY::DESTROY ()
