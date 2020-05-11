#ifdef __cplusplus
extern "C"{
#endif

#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifdef __cplusplus
}
#endif

#include "ppport.h"

#include "plCollection.hpp"
#include "plCursor.hpp"

MODULE = SequoiaDB::Collection		PACKAGE = SequoiaDB::Collection		

plCollection *
plCollection::new()

plCursor *
plCollection::query(querysv=NULL, selectorsv=NULL, orderbysv=NULL, hintsv=NULL, numToSkip = 0, numToReturn = -1, flag = 0)
               SV * querysv
               SV * selectorsv
               SV * orderbysv
               SV * hintsv
               long numToSkip
               long numToReturn
               int flag

bool
plCollection::insert(sv)
               SV * sv

bool
plCollection::bulkInsert (sv, flag = FLG_INSERT_CONTONDUP)
               SV * sv
               int flag

long
plCollection::count (sv = NULL)
               SV * sv

const char *
plCollection::getCLName ()

const char *
plCollection::getCSName ()
 
const char *
plCollection::getFullName ()

plLob *
plCollection::createLob (oidStr = NULL)
                const char * oidStr

bool
plCollection::removeLob (oidStr)
                const char * oidStr

plLob *
plCollection::openLob (oidStr)
                const char * oidStr

plCursor *
plCollection::listLobs ()

plCursor *
plCollection::explain(conditionsv=NULL, selectorsv=NULL, orderbysv=NULL, hintsv=NULL, numToSkip = 0, numToReturn = -1, flag = 0, optionsv = NULL) 
                 SV * conditionsv
                 SV * selectorsv
                 SV * orderbysv
                 SV * hintsv
                 long numToSkip
                 long numToReturn
                 int flag
                 SV * optionsv

bool
plCollection::update (rulesv, conditionsv, hintsv)
                 SV * rulesv
                 SV * conditionsv
                 SV * hintsv

bool
plCollection::upsert (rulesv, conditionsv, hintsv)
                 SV * rulesv
                 SV * conditionsv
                 SV * hintsv

bool
plCollection::createIndex (indexName, conditionsv, \
                           isUniquesv = NULL, enforcedsv = NULL)
                 const char * indexName
                 SV * conditionsv
                 SV * isUniquesv
                 SV * enforcedsv

plCursor *
plCollection::listIndexes (indexName = "")
                 const char * indexName

bool
plCollection::remove (conditionsv, hintsv = NULL)
                 SV * conditionsv
                 SV * hintsv

bool
plCollection::split (sourceGroup, targetGroup, conditionsv, staticsv = NULL)
                 const char * sourceGroup
                 const char * targetGroup
                 SV * conditionsv
                 SV * staticsv

long
plCollection::splitAsync (sourceGroup, targetGroup, conditionsv, staticsv = NULL)
                 const char * sourceGroup
                 const char * targetGroup
                 SV * conditionsv
                 SV * staticsv

bool
plCollection::alterCollection (sv)
                 SV * sv

bool
plCollection::attachCollection (sdbFullName, sv)
                 const char * sdbFullName
                 SV * sv

bool
plCollection::detachCollection (sdbFullName)
                 const char * sdbFullName

plCursor *
plCollection::aggregate (sv)
                 SV * sv

void
plCollection::DESTROY()
