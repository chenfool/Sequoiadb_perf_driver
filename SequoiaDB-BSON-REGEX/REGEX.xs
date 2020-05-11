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

#include "plBSONREGEX.hpp"

MODULE = SequoiaDB::BSON::REGEX		PACKAGE = SequoiaDB::BSON::REGEX		

plBSONREGEX *
plBSONREGEX::new (regex = NULL, opt = NULL)
               const char * regex
               const char * opt

void
plBSONREGEX::setRegex (regex)
               const char * regex

void
plBSONREGEX::setOption (opt)
               const char * opt

const char *
plBSONREGEX::getRegex ()

const char *
plBSONREGEX::getOption ()

void
plBSONREGEX::DESTROY ()
