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

int n;
//table 1: course studentid grade   CSG
// add date. What part should it be? Attribute or key?
typedef struct CSG *CSGTUPLE;
struct CSG {
    char *Course;       //conjugate key
    char *StudentId;    //conjugate key
    char *Grade;
    CSGTUPLE next;
};
typedef CSGTUPLE CSGTABLE[100];

//table 2: StudentId Name Address Phone  SNAP
typedef struct SNAP *SNAPTUPLE;
struct SNAP {
    char *StudentId;  //k
    char *Name;
    char *Address;
    char *Phone;
    SNAPTUPLE next;
};
typedef SNAPTUPLE* SNAPTABLE;

// table 3:Course Prerequisite    CP
typedef struct CP *CPTUPLE;
struct CP {
    char *Course;             //conjugate key
    char *Prerequisite;       //conjugate key
    CPTUPLE next;
};
typedef CPTUPLE* CPTABLE;

//table 4:Course Day Hour    CDH
typedef struct CDH *CDHTUPLE;
struct CDH {
    char *Course;         //conjugate key
    char *Day;            //conjugate key
    char *Hour;           //conjugate key
    CDHTUPLE next;
};
typedef CDHTUPLE *CDHTABLE;

//table 5:Course Room    CR
typedef struct CR *CRTUPLE;
struct CR {
    char *Course;
    char *Room;
    CRTUPLE next;
};
typedef CRTUPLE* CRTABLE;

// hash
unsigned long hashCSG (char *Course, char *StudentId);
unsigned long hashSNAP (char *StudentId);
unsigned long hashCP (char *Course, char* Prerequisite);
unsigned long hashCDH (char* Course, char* Day, char* Hour);
unsigned long hashCR (char* Course, char* Room);

// create
CSGTUPLE createCSG(char* Course, char *StudentId, char* Grade);
SNAPTUPLE createSNAP(char *StudentId, char* Name, char* Address, char *Phone);
CPTUPLE createCP(char* Course, char* Prerequisite);
CDHTUPLE createCDH(char* Course, char* Day, char* Hour);
CRTUPLE createCR(char* Course, char* Room);

// insert
void insertCSG(CSGTUPLE tuple, CSGTABLE table);
void insertSNAP(SNAPTUPLE tuple, SNAPTABLE table);
void insertCP(CPTUPLE tuple, CPTABLE table);
void insertCDH(CDHTUPLE tuple, CDHTABLE table);
void insertCR(CRTUPLE tuple, CRTABLE table);

// delete
void deleteCSG(CSGTUPLE tuple, CSGTABLE table);
void deleteSNAP(SNAPTUPLE tuple, SNAPTABLE table);
void deleteCP(CPTUPLE tuple, CPTABLE table);
void deleteCDH(CDHTUPLE tuple, CDHTABLE table);
void deleteCR(CRTUPLE tuple, CRTABLE table);

// lookup
CSGTUPLE lookupCSG(CSGTUPLE tuple, CSGTABLE table);
SNAPTUPLE lookupSNAP(SNAPTUPLE tuple, SNAPTABLE table);
CPTUPLE lookupCP(CPTUPLE tuple, CPTABLE table);
CDHTUPLE lookupCDH(CDHTUPLE tuple, CDHTABLE table);
CRTUPLE lookupCR(CRTUPLE tuple, CRTABLE table);
//printf
void printCSG(CSGTABLE t);
void printSNAP(SNAPTABLE t);
void printCP(CPTABLE t);
void printCDH(CDHTABLE t);
void printCR(CRTABLE t);

// commented thest out. Hope they did not play a part in the h file.
// CSGTABLE createCSGTABLE();
// CSGTUPLE createTuple(char* Course, char* Grade, int StudentId);
// void insert(CSGTUPLE tuple, CSGTABLE table);
// int delete(CSGTUPLE tuple, CSGTABLE table);
// void printCSG(CSGTABLE t);

#endif

