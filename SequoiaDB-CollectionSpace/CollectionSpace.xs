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

#include "plCollectionSpace.hpp"
#include "plCollection.hpp"

MODULE = SequoiaDB::CollectionSpace		PACKAGE = SequoiaDB::CollectionSpace		

plCollectionSpace *
plCollectionSpace::new()

plCollection *
plCollectionSpace::getCollection(pCollectionName)
        const char * pCollectionName

plCollection *
plCollectionSpace::createCollection(pCollectionName, sv = NULL)
        const char * pCollectionName
        SV * sv

bool
plCollectionSpace::dropCollection(pCollectionName)
        const char * pCollectionName

const char *
plCollectionSpace::getCSName()

void
plCollectionSpace::DESTROY()
