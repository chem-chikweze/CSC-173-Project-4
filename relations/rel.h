#ifndef REL_H
#define REL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AddressSize 5
#define courseSize 5
#define daySize 5
#define hourSize 5
#define NameSize 5
#define gradeSize 2
#define prereqSize 8
#define roomSize 8
#define studentSize 100
#define phoneSize 12
#define BASE (256)
#define SIZE (1008)

int n;
//table 1: course studentid grade   CSG
// add date. What part should it be? Attribute or key?
typedef struct CSG CSGTUPLE;
struct CSG {
    // a type but with no associated storage
    char *StudentId;  //conjugate key
    char *Course;    // = (char*) malloc (courseSize * sizeof(char)); //conjugate key
    char *Grade;     //  = (char*) malloc (gradeSize * sizeof(char)); //conjugate key
    CSGTUPLE* next;
    int count;
};
// typedef CSGTUPLE CSGTABLE[100];

//table 2: StudentId Name Address Phone  SNAP
typedef struct SNAP SNAPTUPLE;
struct SNAP {
    char *StudentId;  //k
    char *Name;
    char *Address;
    char *Phone;
    SNAPTUPLE* next;
    int count;
};

// table 3:Course Prerequisite    CP
typedef struct CP CPTUPLE;
struct CP {
    char *Course;             //conjugate key
    char *Prerequisite;       //conjugate key
    CPTUPLE* next;
    int count;
};

//table 4:Course Day Hour    CDH
typedef struct CDH CDHTUPLE;
struct CDH {
    char *Course;         //conjugate key
    char *Day;            //conjugate key
    char *Hour;           //conjugate key
    CDHTUPLE* next;
    int count;
};

//table 5:Course Room    CR
typedef struct CR CRTUPLE;
struct CR {
    char *Course;
    char *Room;
    CRTUPLE* next;
    int count;
};


CSGTUPLE** createCSGTABLE();
SNAPTUPLE** createSNAPTABLE();
CPTUPLE** createCPTABLE();
CDHTUPLE** createCDHTABLE();
CRTUPLE** createCRTABLE();

void grow();

// hash
unsigned long hashCSG (char *Course, char *StudentId);
unsigned long hashSNAP (char *StudentId);
unsigned long hashCP (char *Course, char* Prerequisite);
unsigned long hashCDH (char* Course, char* Day, char* Hour);
unsigned long hashCR (char* Course, char* Room);

// csg table
CSGTUPLE** createCSGTABLE() ;
SNAPTUPLE** createSNAPTABLE();
CPTUPLE** createCPTABLE();
CDHTUPLE** createCDHTABLE();
CRTUPLE** createCRTABLE();

//insert into list
void insertCSGIntoListOfCSGs(CSGTUPLE* head, CSGTUPLE* t);
void insertSNAPIntoListOfCSGs(SNAPTUPLE* head, SNAPTUPLE* t);
void insertCPIntoListOfCSGs(CPTUPLE* head, CPTUPLE* t);
void insertCDHIntoListOfCSGs(CDHTUPLE* head, CDHTUPLE* t);
void insertCRIntoListOfCSGs(CRTUPLE* head, CRTUPLE* t);

// create
CSGTUPLE* createCSG(char* Course, char *StudentId, char* Grade);
SNAPTUPLE* createSNAP(char *StudentId, char* Name, char* Address, char *Phone);
CPTUPLE* createCP(char* Course, char* Prerequisite);
CDHTUPLE* createCDH(char* Course, char* Day, char* Hour);
CRTUPLE* createCR(char* Course, char* Room);

// insert
void insertCSG(CSGTUPLE *tuple, CSGTUPLE** table);
void insertSNAP(SNAPTUPLE *tuple, SNAPTUPLE** table);
void insertCP(CPTUPLE* tuple, CPTUPLE** table);
void insertCDH(CDHTUPLE* tuple, CDHTUPLE** table);
void insertCR(CRTUPLE *tuple, CRTUPLE** table);

// from file
void fromfileCSG(CSGTUPLE** r, const char* f);
void fromfileSNAP(SNAPTUPLE** r, const char* f);
void fromfileCP(CPTUPLE** r, const char* f);
void fromfileCDH(CDHTUPLE** r, const char* f);
void fromfileCR(CRTUPLE** r, const char* f);

// delete
void deleteCSG(CSGTUPLE *tuple, CSGTUPLE** table);
void deleteSNAP(SNAPTUPLE *tuple, SNAPTUPLE** table);
void deleteCP(CPTUPLE* tuple, CPTUPLE** table);
void deleteCDH(CDHTUPLE* tuple, CDHTUPLE** table);
void deleteCR(CRTUPLE* tuple, CRTUPLE** table);

// lookup
CSGTUPLE lookupCSG(CSGTUPLE *tuple, CSGTUPLE** table);
SNAPTUPLE lookupSNAP(SNAPTUPLE *tuple, SNAPTUPLE** table);
CPTUPLE lookupCP(CPTUPLE *tuple, CPTUPLE** table);
CDHTUPLE lookupCDH(CDHTUPLE *tuple, CDHTUPLE** table);
CRTUPLE lookupCR(CRTUPLE *tuple, CRTUPLE** table);

//printf
void printCSG(CSGTUPLE** t);
void printSNAP(SNAPTUPLE** t);
void printCP(CPTUPLE** table);
void printCDH(CDHTUPLE** t);
void printCR(CRTUPLE** t);

// commented thest out. Hope they did not play a part in the h file.
// CSGTABLE createCSGTABLE();
// CSGTUPLE createTuple(char* Course, char* Grade, int StudentId);
// void insert(CSGTUPLE tuple, CSGTABLE table);
// int delete(CSGTUPLE tuple, CSGTABLE table);
// void printCSG(CSGTABLE t);

#endif

