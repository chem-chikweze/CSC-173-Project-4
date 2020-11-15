#ifndef REL_H
#define REL_H
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
#define BASE (256)
#define SIZE (1008)


//table 1: course studentid grade   CSG
// add date. What part should it be? Attribute or key?
typedef struct CSG *CSGTUPLE;
struct CSG {
    char *Course; //conjugate key
    int StudentId;  //conjugate key
    char *Grade;
    CSGTUPLE next;
};
typedef CSGTUPLE* CSGTABLE;

//table 2: StudentId Name Address Phone  SNAP
typedef struct SNAP *SNAPTUPLE;
struct SNAP {
    int StudentId;  //k
    char *Name;
    char *Address;
    int Phone;
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
unsigned long hashCSG (char *Course, int StudentId);
unsigned long hashSNAP (int StudentId);
unsigned long hashCP (char *Course, char* Prerequisite);
unsigned long hashCDH (char* Course, char* Day, char* Hour);
unsigned long hashCR (char* Course, char* Room);

// create
CSGTUPLE createCSG(char* Course, char* Grade, int StudentId);
SNAPTUPLE createSNAP(int StudentId, char* Name, char* Address, int Phone);
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

//printf
void printCSG(CSGTABLE t);
void printSNAP(SNAPTABLE t);
void printCP(CPTABLE t);
void printCDH(CDHTABLE t);
void printCR(CRTABLE t);

CSGTABLE createCSGTABLE();
CSGTUPLE createTuple(char* Course, char* Grade, int StudentId);
void insert(CSGTUPLE tuple, CSGTABLE table);
int delete(CSGTUPLE tuple, CSGTABLE table);
void printCSG(CSGTABLE t);

#endif

