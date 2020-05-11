#!/usr/bin/perl -w
#package SequoiaDB::BSON::OID ;
package OID ;

use Moose ;

require Exporter ;
@ISA = qw (Exporter) ;
@EXPORT = qw (getValue) ;
use strict ;

sub new {
#   my $this = shift() ;
#   my $class = ref ($this) || $this ;
   my $class = shift () ;
   my $self = {} ;
   $self->{value} = shift () ;
   bless $self, $class ;
   #$self->initialize () ;
   return $self ;
}

sub getValue {
   my ($self) = @_ ;
   return $self->{value} ;
}

has value => (
     is   => 'rw',
     isa  => 'Str',
     required  => 1,
     default   => '123456',
);
