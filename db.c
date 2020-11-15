#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "rel.h"

db createDB(){
    db dbase = (db) malloc (sizeof(db));
    dbase->csg = (CSGTABLE)malloc(sizeof(CSGTABLE) * CSGSIZE);
    dbase->snap = (SNAPTABLE)malloc(sizeof(SNAPTABLE) * SNAPSIZE);
    dbase->cp = (CPTABLE)malloc(sizeof(CPTABLE) * CPSIZE);
    dbase->cdh = (CDHTABLE)malloc(sizeof(CDHTABLE) * CDHSIZE);
    dbase->cr = (CRTABLE)malloc(sizeof(CRTABLE) * CRSIZE);

    int i;
    for(i =0; i < CSGSIZE; i++){
        *(dbase->cr + i) = NULL;
    }
    for(i =0; i < CSGSIZE; i++){
        *(dbase->csg + i) = NULL;
    }
    for(i =0; i < CSGSIZE; i++){
        *(dbase->snap + i) = NULL;
    }
    for(i =0; i < CSGSIZE; i++){
        *(dbase->cp + i) = NULL;
    }
    for(i =0; i < CSGSIZE; i++){
        *(dbase->cdh + i) = NULL;

    }

    printf("\nend\n");
    return dbase;
}

