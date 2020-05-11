PERL_LIB_DIR=

lib/libsdbclient.so : src/plSequoiadb.cpp src/plCollectionSpace.cpp src/plCollection.cpp src/plCursor.cpp src/plBSONObj.cpp src/perl_sequoiadb.cpp src/plBSONOID.cpp src/checkRcType.cpp src/plReplicaGroup.cpp src/plNode.cpp src/plLob.cpp src/plDomain.cpp src/plBSONBOOLEAN.cpp src/plBSONDATE.cpp src/plBSONBINARY.cpp src/plBSONCODE.cpp src/plBSONMAXKEY.cpp src/plBSONMINKEY.cpp
	g++ -shared -fpic -I./include/sdbclient -I./include -I$(PERL_LIB_DIR)/CORE/   $^  -L./lib -lsdbcpp -o $@
