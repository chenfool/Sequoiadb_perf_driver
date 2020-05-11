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

#include "plBSONObj.hpp"

using namespace std;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::BSON		PACKAGE = SequoiaDB::BSON		

plBSONObj *
plBSONObj::new(sv=NULL)
      SV * sv

const char *
plBSONObj::toString()

const char *
plBSONObj::get(key)
     const char * key

bool
plBSONObj::put(key, value)
     const char * key
     const char * value

int
plBSONObj::toBson (sv)
     SV * sv

int
plBSONObj::toBson2 (sv)
     SV * sv

SV *
plBSONObj::getBson (sv)
     SV * sv

SV *
plBSONObj::toString2()

void
plBSONObj::DESTROY()
