#!/usr/bin/perl -w 

#push (@INC, "/opt/sequoiadb_perl/SequoiaDB-BSON/bson") ;
use SequoiaDB::BSON::OID ;


$oid = OID->new("124") ;

print $oid->getValue() ;
