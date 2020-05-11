#include "plDomain.hpp"

plDomain::plDomain () {}

sdbDomain * plDomain::getDomainPoint ()
{
   return & this->domainObject ;
}
plDomain::~plDomain () {}
