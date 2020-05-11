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
#include "plLob.hpp"

MODULE = SequoiaDB::Lob		PACKAGE = SequoiaDB::Lob		

plLob *
plLob::new ()

const char *
plLob::getOid ()

bool
plLob::write (buf)
         const char * buf

bool
plLob::close ()

bool
plLob::isClosed ()

const char *
plLob::read ()

long
plLob::getSize ()

long
plLob::getCreateTime ()



void
plLob::DESTROY ()
