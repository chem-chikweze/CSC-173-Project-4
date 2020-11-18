#ifndef DB_H
#define DB_H
#include "rel.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// typedef struct database *db;
// struct database
// {
//     CSGTUPLE** csg;
//     SNAPTUPLE** snap;
//     CPTUPLE** cp;
//     CDHTUPLE** cdh;
//     CRTUPLE** cr;
// };
typedef struct database db;
struct database{
    CSGTUPLE** csg;
    SNAPTUPLE** snap;
    CPTUPLE** cp;
    CDHTUPLE** cdh;
    CRTUPLE** cr;
};

db* createDB();
void fromFIle(db* r, const char *f);
void grow();

#endif