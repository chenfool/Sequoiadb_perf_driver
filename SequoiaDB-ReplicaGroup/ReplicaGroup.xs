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
#include "plReplicaGroup.hpp"
using namespace sdbclient;


MODULE = SequoiaDB::ReplicaGroup		PACKAGE = SequoiaDB::ReplicaGroup		

plReplicaGroup *
plReplicaGroup::new ()

plNode *
plReplicaGroup::createNode (hostname, serviceSv, path, sv)
                      const char * hostname
                      SV * serviceSv
                      const char * path
                      SV * sv

plNode *
plReplicaGroup::getNode (hostname, serviceSv)
                      const char * hostname
                      SV * serviceSv

plNode *
plReplicaGroup::getMaster ()

plNode *
plReplicaGroup::getSlave ()

bool
plReplicaGroup::removeNode (hostname, serviceSv)
                      const char * hostname
                      SV * serviceSv

bool
plReplicaGroup::start ()

bool
plReplicaGroup::stop ()

const char *
plReplicaGroup::getName ()

bool
plReplicaGroup::isCatalog () 

void
plReplicaGroup::DESTROY ()
