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


typedef struct db *db;
struct db
{
    CSGTABLE csg;
    SNAPTABLE snap;
    CPTABLE cp;
    CDHTABLE cdh;
    CRTABLE cr;
};

db createDB();
void fromFIle(db r, char *f);


#endif