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
#include "plSequoiadb.hpp"
#include "plCollectionSpace.hpp"
using namespace std ;
using namespace sdbclient ;
using namespace bson ;

MODULE = SequoiaDB::Sdb		PACKAGE = SequoiaDB::Sdb		

plSequoiadb *
plSequoiadb::new (pHostName, Port, pUsr, pPasswd)
          const char * pHostName
          int Port
          const char * pUsr
          const char * pPasswd

plCollectionSpace *
plSequoiadb::getCollectionSpace (pCollectionSpaceName)
          const char * pCollectionSpaceName

plCollectionSpace *
plSequoiadb::createCollectionSpace (pCollectionSpaceName, sv=NULL)
          const char * pCollectionSpaceName
          SV * sv

bool
plSequoiadb::dropCollectionSpace (pCollectionSpaceName)
          const char * pCollectionSpaceName

bool
plSequoiadb::createUsr (user, passwd)
          const char * user
          const char * passwd

bool
plSequoiadb::dropDomain (domainName)
          const char * domainName

plCursor *
plSequoiadb::listCollectionSpaces ()

plCursor *
plSequoiadb::listCollections ()

plCursor *
plSequoiadb::listReplicaGroups ()

plDomain *
plSequoiadb::createDomain(domainName, sv)
           const char * domainName
           SV * sv

plDomain *
plSequoiadb::getDomain (domainName)
           const char * domainName

plReplicaGroup *
plSequoiadb::createRG (rgName)
           const char * rgName

plReplicaGroup *
plSequoiadb::createCatalogRG (hostname, serviceName, databasePath, config = NULL)
           const char * hostname
           SV * serviceName
           const char * databasePath
           SV * config

plReplicaGroup *
plSequoiadb::getRG (rgName)
           const char * rgName

void
plSequoiadb::DESTROY()
