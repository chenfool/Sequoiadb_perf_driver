#!/usr/bin/perl

use SequoiaDB::Sdb ;
use SequoiaDB::CollectionSpace ;
use SequoiaDB::Collection ;
use SequoiaDB::Cursor ;
use SequoiaDB::BSON ;
use SequoiaDB::BSON::CODE;
use SequoiaDB::BSON::OID ;
use SequoiaDB::BSON::MaxKey ;
use SequoiaDB::BSON::MinKey ;

use Data::Dumper;

print "nihao\n";
my $sdb = new SequoiaDB::Sdb("localhost",11810,"","");
print "nihao\n";
my $cursor = $sdb->listCollections();
while(my $bson = $cursor->next(1)) {
   if (defined $bson)
   {
      print "***********************\n" ;
#      print Dumper($bson);
      print $bson ;
   }
}



my $cs = $sdb->getCollectionSpace("foo");
print "####" . $cs . "\n";
#$cs->createCollection("chen");
print "***###" . $cs->getCSName() . "\n";

my $cl = $cs->getCollection("bar");
my $cc = new SequoiaDB::BSON::CODE ("t");
my $max = new SequoiaDB::BSON::MaxKey ();
my $min = new SequoiaDB::BSON::MinKey ();

$cl->insert ({"max"=>$max, "min"=>$min});
my $cursor = $cl->query();
#my $cursor = $sdb->listReplicaGroups(); 

while(my $bson = $cursor->next(1))
{
   if (defined $bson)
   {
      print "***********************\n" ;
#      print Dumper($bson);
      print $bson ;
   }   
   print "***********************\n" ;
}
#my $arr = [{"name"=>"chen"},{"name"=>"fool"}] ;
#push ( $arr, {"id"=> 23}) ;
#$cl->bulkInsert ($arr) ;

#$cl->insert({"name"=>[{"id"=>12},333]}) ; 

