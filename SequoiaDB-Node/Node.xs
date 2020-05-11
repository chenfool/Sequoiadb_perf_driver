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
#include "plNode.hpp"

MODULE = SequoiaDB::Node		PACKAGE = SequoiaDB::Node		


plNode *
plNode::new ()

bool
plNode::start ()

bool
plNode::stop ()

const char *
plNode::getHostName ()

const char *
plNode::getServiceName ()

const char *
plNode::getNodeName ()

void
plNode::DESTROY ()
