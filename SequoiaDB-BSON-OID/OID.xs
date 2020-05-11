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

#include "plBSONOID.hpp"

using namespace std ;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::BSON::OID		PACKAGE = SequoiaDB::BSON::OID		

plBSONOID *
plBSONOID::new (str = NULL)
    const char * str

bool
plBSONOID::gen ()


const char *
plBSONOID::toString ()

void
plBSONOID::DESTROY ()
