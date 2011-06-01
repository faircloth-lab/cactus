/*
 * Copyright (C) 2009-2011 by Benedict Paten (benedictpaten@gmail.com)
 *
 * Released under the MIT license, see LICENSE.txt
 */

#include "cactusGlobalsPrivate.h"

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
//Functions shared by the test code.
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

stKVDatabaseConf *testCommon_getTemporaryKVDatabaseConf() {
    testCommon_deleteTemporaryKVDatabase();
    stKVDatabaseConf *conf = stKVDatabaseConf_constructTokyoCabinet(
            "temporaryCactusDisk");
    return conf;
}

void testCommon_deleteTemporaryKVDatabase() {
    int32_t i = system("rm -rf temporaryCactusDisk");
    exitOnFailure(i, "Tried to delete the temporary KV database\n");
}

CactusDisk *testCommon_getTemporaryCactusDisk() {
    stKVDatabaseConf *conf = stKVDatabaseConf_constructTokyoCabinet(
            "temporaryCactusDisk");
    CactusDisk *cactusDisk;
    if (st_random() > 0.5) {
        cactusDisk = cactusDisk_construct(conf, 1);
    } else {
        cactusDisk = cactusDisk_construct2(conf,
                "cactusSequences");
    }
    return cactusDisk;
}

void testCommon_deleteTemporaryCactusDisk(CactusDisk *cactusDisk) {
    cactusDisk_destruct(cactusDisk);
    testCommon_deleteTemporaryKVDatabase();
}
