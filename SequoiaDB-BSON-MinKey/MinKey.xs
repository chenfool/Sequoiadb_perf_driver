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
#include "plBSONMINKEY.hpp"


using namespace std ;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::BSON::MinKey		PACKAGE = SequoiaDB::BSON::MinKey		

plBSONMINKEY *
plBSONMINKEY::new ()

void
plBSONMINKEY::DESTROY ()
