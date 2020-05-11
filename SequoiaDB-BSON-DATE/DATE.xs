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

#include "plBSONDATE.hpp"

using namespace bson ;

MODULE = SequoiaDB::BSON::DATE		PACKAGE = SequoiaDB::BSON::DATE		

plBSONDATE *
plBSONDATE::new (mil = 0)
             long mil

void
plBSONDATE::setValue (mil)
             long mil

const char *
plBSONDATE::toString ()

void
plBSONDATE::DESTROY ()

