#ifndef DB_H
#define DB_H
#include "rel.h"
#define SIZE 100
#define CSGSIZE 50
#define SNAPSIZE 100
#define CPSIZE 100
#define CDHSIZE 100
#define CRSIZE 100
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct database *db;
struct database
{
    CSGTUPLE** csg;
    SNAPTUPLE** snap;
    CPTUPLE** cp;
    CDHTUPLE** cdh;
    CRTUPLE** cr;
};

db createDB();
void fromFIle(db r, const char *f);
void grow();

#endif