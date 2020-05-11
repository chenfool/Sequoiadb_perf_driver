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
#include "plCursor.hpp"

MODULE = SequoiaDB::Cursor		PACKAGE = SequoiaDB::Cursor		

plCursor *
plCursor::new()

void
plCursor::next(sv = NULL)
       SV * sv
   PPCODE:
      XPUSHs (THIS->next(sv)) ;

void
plCursor::current(sv = NULL)
       SV * sv
   PPCODE:
      XPUSHs (THIS->current(sv)) ;

void
plCursor::DESTROY()
