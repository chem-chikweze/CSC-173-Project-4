#include "rel.h"
#include "db.h"

unsigned long hashCSG (char *Course, int StudentId) {
    unsigned long hash;
    int val1,val2, val3;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    val2 = StudentId;
    val3 = val1*val2;
    hash = (val3 * BASE)% SIZE;
    return hash;
}

unsigned long hashSNAP (int StudentId){
    unsigned long hash = 0;
    hash = StudentId % SIZE;
    return hash;
}

unsigned long hashCP (char *Course, char* Prerequisite){
    unsigned long hash;
    int val1,val2, val3;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Prerequisite);
    val2 = atoi(str);
    val3 = val1*val2;
    hash = (val3 * BASE)% SIZE;
    return hash;
}

unsigned long hashCDH (char* Course, char* Day, char* Hour){
    unsigned long hash;
    int val1,val2, val3,val4;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Day);
    val2 = atoi(str);
    strcpy(str, Hour);
    val3 = atoi(str);
    val4 = val1*val2*val3;
    hash = (val4 * BASE)% SIZE;  
    return hash;
}

unsigned long hashCR (char* Course, char* Room){
    int hash;
    int val1,val2, val3;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Room);
    val2 = atoi(str);
    val3 = val1*val2 + val1 * 47;
    hash = ((val3 * BASE* 47) )% SIZE;

    // printf("RMH%s%d\n", Room, hash);
    return hash;
}



CSGTUPLE createCSG(char* Course, int StudentId, char* Grade){
    CSGTUPLE tuple = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Grade = (char *)malloc(sizeof(char)*gradeSize);
    tuple->StudentId = StudentId;
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Grade, Grade);
    return tuple;
}

SNAPTUPLE createSNAP(int StudentId, char *Name, char* Address, int Phone){
    SNAPTUPLE tuple = (SNAPTUPLE)malloc(sizeof(SNAPTUPLE));
    tuple->StudentId = StudentId;
    tuple->Name = (char *)malloc(sizeof(char)*NameSize);
    tuple->Address = (char *)malloc(sizeof(char)*AddressSize);
    tuple->Phone = Phone;
    tuple->next = NULL;
    strcpy(tuple->Name, Name);
    strcpy(tuple->Address, Address);
    return tuple;
}

CPTUPLE createCP(char* Course, char* Prerequisite){
    CPTUPLE tuple = (CPTUPLE)malloc(sizeof(CPTUPLE));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Prerequisite = (char *)malloc(sizeof(char)*prereqSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Prerequisite, Prerequisite);
    return tuple;
}

CDHTUPLE createCDH(char* Course, char* Day, char* Hour){
    CDHTUPLE tuple = (CDHTUPLE)malloc(sizeof(CDHTUPLE));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Day = (char *)malloc(sizeof(char)*daySize);
    tuple->Hour = (char *)malloc(sizeof(char)*hourSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Day, Day);
    strcpy(tuple->Hour, Hour);
    return tuple;
}

CRTUPLE createCR(char* Course, char* Room){
    CRTUPLE tuple = (CRTUPLE)malloc(sizeof(CRTUPLE));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Room = (char *)malloc(sizeof(char)*roomSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Room, Room);
    return tuple;
}

void insertCSG(CSGTUPLE tuple, CSGTABLE table){
    unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
    // go to bucket,, walk through bucket for if it contains the struct or not.
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = tuple;
}

void insertSNAP(SNAPTUPLE tuple, SNAPTABLE table){
    unsigned long hashIndex = hashSNAP(tuple->StudentId);
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = tuple;
    // table[hashIndex] = (SNAPTUPLE)malloc(sizeof(SNAPTUPLE));
    // table[hashIndex]->StudentId = tuple->StudentId;
    // table[hashIndex]->Name = (char *)malloc(sizeof(char)*NameSize);
    // table[hashIndex]->Address = (char *)malloc(sizeof(char)*AddressSize);
    // table[hashIndex]->Phone = tuple->Phone;
    // table[hashIndex]->next = NULL;
    // strcpy(table[hashIndex]->Name, tuple->Name);
    // strcpy(table[hashIndex]->Address, tuple->Address);
}

void insertCP(CPTUPLE tuple, CPTABLE table){
    int hashIndex = hashCP(tuple->Course, tuple->Prerequisite);
    // go to bucket,, walk through bucket for if it contains the struct or not.
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = tuple;
    // table[hashIndex] = (CPTUPLE)malloc(sizeof(CPTUPLE));
    // table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    // table[hashIndex]->Prerequisite = (char *)malloc(sizeof(char)*prereqSize);
    // table[hashIndex]->next = NULL;
    // strcpy(table[hashIndex]->Course, tuple->Course);
    // strcpy(table[hashIndex]->Prerequisite, tuple->Prerequisite);
}

void insertCDH(CDHTUPLE tuple, CDHTABLE table){
    int hashIndex = hashCDH(tuple->Course, tuple->Day, tuple->Hour);
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = tuple;

    // table[hashIndex] = (CDHTUPLE)malloc(sizeof(CDHTUPLE));
    // table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    // table[hashIndex]->Day = (char *)malloc(sizeof(char)*daySize);
    // table[hashIndex]->Hour = (char *)malloc(sizeof(char)*hourSize);
    // table[hashIndex]->next = NULL;
    // strcpy(table[hashIndex]->Course, tuple->Course);
    // strcpy(table[hashIndex]->Day, tuple->Day);
    // strcpy(table[hashIndex]->Hour, tuple->Hour);
}

void insertCR(CRTUPLE tuple, CRTABLE table){
    int hashIndex = hashCR(tuple->Course, tuple->Room);
    while ( table[hashIndex]){
        hashIndex = (hashIndex + 1) % SIZE;
    }
    table[hashIndex] = tuple;
}

void printCSG(CSGTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){  
            printf("\n%s\t%d\t%s", t[i]->Course,t[i]->StudentId,t[i]->Grade);     
        } 
    }
}

void printSNAP(SNAPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%d\t%s\t%d\n", t[i]->Name, t[i]->StudentId, t[i]->Address, t[i]->Phone);     
            // printf("%d\t", t[i]->StudentId);     
            // printf("%s\t", t[i]->Address);     
            // printf("%d\n", t[i]->Phone);     
        } 
    }
}
void printCP(CPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){   
            printf("%s\t%s", t[i]->Course, t[i]->Prerequisite);     
        } 
    }
}
void printCDH(CDHTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%s\t%s", t[i]->Course, t[i]->Day, t[i]->Hour);        
            // printf("%s\t", t[i]->Day);        
            // printf("%s\n", t[i]->Hour);     
        } 
    }
}
void printCR(CRTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%s", t[i]->Course, t[i]->Room);        
        } 
    }
}


