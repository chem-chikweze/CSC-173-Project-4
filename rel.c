#include "rel.h"
#include "db.h"

unsigned long hashCSG (char *Course, int StudentId) {
    unsigned long hash;
    unsigned const char *cs;
    // elements will be treated as having values greater than 0
    cs = (unsigned const char *) Course;
    hash = 0;
    // loops until the end of chars in Course
    while (*cs != '\0'){
        // multiplies current hash by BASE, adding current Course character and StudentId then mod m
        hash = (hash * BASE + *cs + StudentId)% SIZE;
        cs++;
    }
    return hash;
}

unsigned long hashSNAP (int StudentId){
    unsigned long hash = 0;
    hash = StudentId % SIZE;
    return hash;
}

unsigned long hashCP (char *Course, char* Prerequisite){
    unsigned long hash;
    unsigned const char *cs;
    // elements will be treated as having values greater than 0
    cs = (unsigned const char *) Course;
    hash = 0;
    while (*cs != '\0'){
        // multiplies current hash by BASE, adding current Course character and StudentId then mod m
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    cs = (unsigned const char *) Prerequisite;
    hash = 0;
    while (*cs != '\0'){
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    return hash;
}

unsigned long hashCDH (char* Course, char* Day, char* Hour){
    unsigned long hash;
    unsigned const char *cs;
    // elements will be treated as having values greater than 0
    cs = (unsigned const char *) Course;
    hash = 0;
    while (*cs != '\0'){
        // multiplies current hash by BASE, adding current Course character and StudentId then mod m
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    cs = (unsigned const char *) Day;
    hash = 0;
    while (*cs != '\0'){
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    cs = (unsigned const char *) Hour;
    hash = 0;
    while (*cs != '\0'){
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    return hash;
}

unsigned long hashCR (char* Course, char* Room){
unsigned long hash;
    unsigned const char *cs;
    // elements will be treated as having values greater than 0
    cs = (unsigned const char *) Course;
    hash = 0;
    while (*cs != '\0'){
        // multiplies current hash by BASE, adding current Course character and StudentId then mod m
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    cs = (unsigned const char *) Room;
    hash = 0;
    while (*cs != '\0'){
        hash = (hash * BASE + * cs)% SIZE;
        cs++;
    }
    return hash;
}



CSGTUPLE createCSG(char* Course, char* Grade, int StudentId){
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
    // table[hashIndex]->Course = tuple->Course;
    table[hashIndex] = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
    table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    table[hashIndex]->Grade = (char *)malloc(sizeof(char)*gradeSize);
    table[hashIndex]->StudentId = tuple->StudentId;
    table[hashIndex]->next = NULL;
    strcpy(table[hashIndex]->Course, tuple->Course);
    strcpy(table[hashIndex]->Grade, tuple->Grade);
}

void insertSNAP(SNAPTUPLE tuple, SNAPTABLE table){
    int hashIndex = hashSNAP(tuple->StudentId);
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = (SNAPTUPLE)malloc(sizeof(SNAPTUPLE));
    table[hashIndex]->StudentId = tuple->StudentId;
    table[hashIndex]->Name = (char *)malloc(sizeof(char)*NameSize);
    table[hashIndex]->Address = (char *)malloc(sizeof(char)*AddressSize);
    table[hashIndex]->Phone = tuple->Phone;
    table[hashIndex]->next = NULL;
    strcpy(table[hashIndex]->Name, tuple->Name);
    strcpy(table[hashIndex]->Address, tuple->Address);
}

void insertCP(CPTUPLE tuple, CPTABLE table){
    int hashIndex = hashCP(tuple->Course, tuple->Prerequisite);
    // go to bucket,, walk through bucket for if it contains the struct or not.
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = (CPTUPLE)malloc(sizeof(CPTUPLE));
    table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    table[hashIndex]->Prerequisite = (char *)malloc(sizeof(char)*prereqSize);
    table[hashIndex]->next = NULL;
    strcpy(table[hashIndex]->Course, tuple->Course);
    strcpy(table[hashIndex]->Prerequisite, tuple->Prerequisite);
}

void insertCDH(CDHTUPLE tuple, CDHTABLE table){
    int hashIndex = hashCDH(tuple->Course, tuple->Day, tuple->Hour);
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = (CDHTUPLE)malloc(sizeof(CDHTUPLE));
    table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    table[hashIndex]->Day = (char *)malloc(sizeof(char)*daySize);
    table[hashIndex]->Hour = (char *)malloc(sizeof(char)*hourSize);
    table[hashIndex]->next = NULL;
    strcpy(table[hashIndex]->Course, tuple->Course);
    strcpy(table[hashIndex]->Day, tuple->Day);
    strcpy(table[hashIndex]->Hour, tuple->Hour);
}

void insertCR(CRTUPLE tuple, CRTABLE table){
    int hashIndex = hashCR(tuple->Course, tuple->Room);
    while ( table[hashIndex] !=NULL){
        hashIndex = (hashIndex + 1) % SIZE;    
    }
    printf("2");
    table[hashIndex] = (CRTUPLE)malloc(sizeof(CRTUPLE));
    printf("h3");
    table[hashIndex]->Course = (char *)malloc(sizeof(char)*courseSize);
    printf("h4");
    table[hashIndex]->Room = (char *)malloc(sizeof(char)*roomSize);
    printf("h5");
    table[hashIndex]->next = NULL;
    printf("6");
    strcpy(table[hashIndex]->Course, tuple->Course);
    printf("7");
    strcpy(table[hashIndex]->Room, tuple->Room);
    printf("8");

}

void printCSG(CSGTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("\n%s", t[i]->Course);     
        } 
    }
}

void printSNAP(SNAPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   printf("%s", "hen");
        if (t[i] ){     
            printf("\n%s\t%d\t%d\t%s", t[i]->Name, t[i]->StudentId, t[i]->Phone, t[i]->Address);     
        } 
    }
}
void printCP(CPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t", t[i]->Course);        
            printf("%s\n", t[i]->Prerequisite);     
        } 
    }
}
void printCDH(CDHTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t", t[i]->Course);        
            printf("%s\t", t[i]->Day);        
            printf("%s\n", t[i]->Hour);     
        } 
    }
}
void printCR(CRTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t", t[i]->Course);        
            printf("%s\n", t[i]->Room);     
        } 
    }
}


