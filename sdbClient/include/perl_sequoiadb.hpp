#ifndef PERL_SEQUOIADB
#define PERL_SEQUOIADB 1

#include "sdbclient/client.hpp"

#include "plBSONOID.hpp"
#include "plBSONBINARY.hpp"
#include "plBSONDATE.hpp"
#include "plBSONCODE.hpp"
#include "plBSONREGEX.hpp"
#include "plBSONBOOLEAN.hpp"
#include "plBSONCODE.hpp"
#include "plBSONMAXKEY.hpp"
#include "plBSONMINKEY.hpp"

/*
#include "plSequoiadb.hpp"
#include "plCollectionSpace.hpp"
#include "plCollection.hpp"
#include "plCursor.hpp"
#include "plDomain.hpp"
#include "plNode.hpp"
#include "plLob.hpp"
#include "plReplicaGroup.hpp"
*/


#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
//#include "ppport.h"

#define ERROR          -1
#define UNKNOW          0
#define HASH            1
#define ARRAY           2
#define INT             3
#define DOUBLE          4
#define STRING          5
#define BSONOID         6
#define BSONREGEX       7
#define BSONCODE        8
#define BSONDATE        9
#define BSONBOOLEAN     10
#define BSONBINARY      11 
#define BSONMAXKEY      12 
#define BSONMINKEY      13 

#define RCLANGUAGE      1

using namespace sdbclient ;
using namespace bson ;

int get_sv_type (SV *) ;

bool sv_to_bson (BSONObjBuilder *, int,SV *) ;

bool hv_to_bson (BSONObjBuilder *, SV *) ;

bool av_to_bson (BSONArrayBuilder *, SV *) ;

bool bson_to_hv (BSONObj *, HV *) ;

bool bson_to_av (vector<BSONElement> *, AV *) ;

bool encode_bson (BSONObjBuilder *, SV *) ;

bool decode_bson (BSONObj *, HV *) ;

bool check_av_isAllHv (SV *) ;

int checkOutRcType(int rcNum, int language = RCLANGUAGE) ;

bool getAv_HvElem (SV *, std::vector<bson::BSONObj> *) ;

#endif
