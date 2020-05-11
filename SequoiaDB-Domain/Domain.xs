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
#include "plDomain.hpp"

MODULE = SequoiaDB::Domain		PACKAGE = SequoiaDB::Domain		

plDomain *
plDomain::new () 

void
plDomain::DESTROY ()

