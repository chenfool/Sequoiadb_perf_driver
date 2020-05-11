#include "plLob.hpp"

plLob::plLob () {}

sdbLob * plLob::getLobPoint () 
{
   return & this->lobObject ;
}

const char * plLob::getOid ()
{
   OID oid ;
   int rc = lobObject.getOid (oid) ;
   checkOutRcType(rc, RCLANGUAGE) ;

   const string str = oid.toString () ;
   const char * cstr = str.c_str () ;
   return cstr ;
}

bool plLob::write (const char * buf)
{
   int size = strlen (buf) ;
   int rc = lobObject.write (buf, size) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plLob::close ()
{
   int rc = lobObject.close () ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return true ;
}

bool plLob::isClosed ()
{
   int isclose ;
   int rc = lobObject.isClosed (isclose) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return isclose ;
}

const char * plLob::read ()
{
   char * cstr = new char[BUFSIZE] ;
   unsigned int readSize ;
   int rc = lobObject.read (BUFSIZE, cstr, &readSize) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return cstr ;
}

long long plLob::getSize ()
{
   long long size ;
   int rc = lobObject.getSize (&size) ;
   checkOutRcType(rc, RCLANGUAGE) ;
   return size ;
}

unsigned long long plLob::getCreateTime ()
{
   unsigned long long time ;
   int rc = lobObject.getCreateTime (&time) ;
   return time ;
}

plLob::~plLob () {}
