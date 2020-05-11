#ifndef INCLUDE_PLNODE_H
#define INCLUDE_PLNODE_H 1
#include "client.hpp"
#include "perl_sequoiadb.hpp"

using namespace sdbclient ;

class plNode
{
private:
   sdbNode node ;

public:
   plNode () ;
   bool start () ;
   bool stop () ;
   const char * getHostName () ;
   const char * getServiceName () ;
   const char * getNodeName () ;
   sdbNode * getSdbNodePoint () ;
   ~plNode () ;

} ;

#endif
