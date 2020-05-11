#ifndef INCLUDE_PLLOB_H
#define INCLUDE_PLLOB_H 1

#include "client.hpp"
#include "perl_sequoiadb.hpp"

#define BUFSIZE 1024*1024*10

using namespace sdbclient ;
class plLob
{
private:
   sdbLob lobObject ;

public:
   plLob () ;

   const char * getOid () ;
   bool write (const char *) ;
   bool close () ;
   const char * read () ;
   bool isClosed () ;
   long long getSize () ;
   unsigned long long getCreateTime () ;
   
   sdbLob * getLobPoint () ;
   ~plLob () ;
   
} ;

#endif
