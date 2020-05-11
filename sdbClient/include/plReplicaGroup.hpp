#ifndef INCLUDE_PLREPLICAGROUP_H
#define INCLUDE_PLREPLICAGROUP_H 1

#include "client.hpp"
#include "plNode.hpp"

using namespace std ;
using namespace sdbclient ;
using namespace bson ;

class plReplicaGroup
{
private:
   sdbReplicaGroup replGroup ;
   

public:
   plReplicaGroup () ;
   sdbReplicaGroup * getPlReplicaGroupPoint () ;
   plNode * createNode (const char *,
                        SV *,
                        const char *,
                        SV * sv = NULL) ;
   plNode * getNode (const char *, SV *) ;
   plNode * getMaster () ;
   plNode * getSlave () ;
   bool removeNode (const char *, SV *) ;
   bool start () ;
   bool stop () ;
   const char * getName () ;
   bool isCatalog () ;
//   int getNodeNum () ;
   ~plReplicaGroup () ; 
} ;
#endif
