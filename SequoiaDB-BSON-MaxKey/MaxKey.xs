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

#include "plBSONMAXKEY.hpp"
#include "ppport.h"

using namespace std ;
using namespace sdbclient ;
using namespace bson ;


MODULE = SequoiaDB::BSON::MaxKey		PACKAGE = SequoiaDB::BSON::MaxKey		

plBSONMAXKEY *
plBSONMAXKEY::new ()

void
plBSONMAXKEY::DESTROY ()
