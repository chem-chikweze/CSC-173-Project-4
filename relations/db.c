#include "rel.h"


typedef struct database db;
struct database{
    CSGTUPLE** csg;
    SNAPTUPLE** snap;
    CPTUPLE** cp;
    CDHTUPLE** cdh;
    CRTUPLE** cr;
};

db *createDB(){
    int n = 0;
    db *dbase =  malloc (sizeof(db));
    (dbase->csg) = createCSGTABLE();
    dbase->snap = createSNAPTABLE();
    dbase->cp = createCPTABLE();
    dbase->cdh = createCDHTABLE();
    dbase->cr = createCRTABLE();

    int i;
    for(i =0; i < SIZE; i++){
        dbase->csg[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->snap[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cr[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cdh[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cp[i] = NULL;
    }
    return dbase;
}