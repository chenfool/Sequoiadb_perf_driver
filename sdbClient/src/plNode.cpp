#include "plNode.hpp"

plNode::plNode () {} 

sdbNode * plNode::getSdbNodePoint ()
{
   return & this->node ;
}

bool plNode::start ()
{
   int rc = node.start () ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plNode::stop ()
{
   int rc = node.stop () ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

const char * plNode::getHostName ()
{
   const char * hostname = node.getHostName () ;
   return hostname ;
}

const char * plNode::getServiceName ()
{
   const char * serviceName = node.getServiceName () ;
   return serviceName ;
}

const char * plNode::getNodeName ()
{
   const char * nodeName = node.getNodeName () ;
   return nodeName ;
}

plNode::~plNode () {}
