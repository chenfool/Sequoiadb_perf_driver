use XML::Simple;
use Data::Dumper;

my $xmlfile = "/home/SequoiaDB/misc/autogen/rclist.xml" ;
#my $xmlfile = "test.xml";

if (-e $xmlfile){
   print "----------------\n";
   my $userxs = XML::Simple->new(KeyAttr => "name");
   my $userxml = $userxs->XMLin($xmlfile);

   print Dumper($userxml);
   print $userxml->{"go"} . "\n";
}
