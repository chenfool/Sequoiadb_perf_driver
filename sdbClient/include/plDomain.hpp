#ifndef INCLUDE_PLDOMAIN_H
#define INCLUDE_PLDOMAIN_H 1

#include "client.hpp"

using namespace sdbclient ;

class plDomain
{
private:
   sdbDomain domainObject ;
public:
   plDomain () ;
   sdbDomain * getDomainPoint () ;
   ~plDomain () ;
} ;
#endif
