#!/usr/bin/perl -w
use XML::Simple;
use Data::Dumper;

my $xmlfile = "misc/autogen/rclist.xml" ;

if (-e $xmlfile){
   print "----------------\n";
   my $XMLxs = XML::Simple->new(KeyAttr => "name");
   my $rootxml = $XMLxs->XMLin($xmlfile);
 


   unless (open(OFILE, ">", "src/checkRcType.cpp")){
      die ("open file faild!\n") ;
   } 

   print OFILE (
"#include \"perl_sequoiadb.hpp\"
/*
 * int rcNum
 *      -- sdb return rc number
 * int language
 *      -- choose print language, default is english
 *        1 english
 *        2 chinese
 */
int checkOutRcType(int rcNum, int language)
{
   if (rcNum != SDB_OK){
      printf (\"rc = %d\\n\", rcNum) ;
      switch(rcNum)
      {
"
);


#  print Dumper($rootxml);


  $codelist = $rootxml->{"codelist"}->{"code"} ;
 
while(my ($key, $value) = each $codelist){
#    print $value->{"description"}->{"en"} . "\n" ;
   print OFILE ('
         case ' . $key . ' :
            if (language == 1)
            {
               printf ("message : %s\\n", "' . $value->{"description"}->{"en"} . '") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\\n", "' . $value->{"description"}->{"cn"} . '") ;
            }
            croak ("%d", rcNum) ; 
            break ;   
') ;
}


print OFILE ("
      }
   }
   return SDB_OK ;
   
}
") ;




  close (OFILE) ;
}
