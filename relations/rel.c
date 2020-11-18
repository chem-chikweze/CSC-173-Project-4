#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rel.h"
#include "db.h"

unsigned long hashSNAP (char *StudentId){
    unsigned long hash = 0;
    for(char c = 0; c <strlen(StudentId); c++){
        hash += StudentId[c];
    }
    hash = hash % SIZE;
    return hash;
}

unsigned long hashCP (char *Course, char* Prerequisite){
    unsigned long hash;
    // elements will be treated as having values greater than 0
    hash = 0;
    // loops until the end of chars in Course
    for(char c = 0; c <strlen(Course); c++){
        hash += Course[c];
    }
    // loops until the end of chars in Course
    for(char d = 0; d <strlen(Prerequisite); d++){
        hash += Prerequisite[d];
    }
    hash = hash % SIZE;
    return hash;
}

unsigned long hashCDH (char* Course, char* Day, char* Hour){
    unsigned long hash;
    // elements will be treated as having values greater than 0
    hash = 0;
    // loops until the end of chars in Course
    for(char c = 0; c <strlen(Course); c++){
        hash += Course[c];
    }
    // loops until the end of chars in Course
    for(char d = 0; d <strlen(Day); d++){
        hash += Day[d];
    }
    for(char d = 0; d <strlen(Hour); d++){
        hash += Hour[d];
    }
    hash = hash % SIZE;
    return hash;
}

unsigned long hashCR (char* Course, char* Room){
    unsigned long hash;
    // elements will be treated as having values greater than 0
    hash = 0;
    // loops until the end of chars in Course
    for(char c = 0; c <strlen(Room); c++){
        hash += Room[c];
    }
    // loops until the end of chars in Course
    for(char d = 0; d <strlen(Course); d++){
        hash += Course[d];
    }
    return hash;
}

SNAPTUPLE** createSNAPTABLE() {
    SNAPTUPLE** ron = (SNAPTUPLE**)calloc(SIZE, sizeof(SNAPTUPLE*));
    // printf("print");
    return ron;
}

CPTUPLE** createCPTABLE() {
    CPTUPLE** ron = (CPTUPLE**)calloc(SIZE, sizeof(CPTUPLE*));
    // printf("print");
    return ron;
}

CDHTUPLE** createCDHTABLE() {
    CDHTUPLE** ron = (CDHTUPLE**)calloc(SIZE, sizeof(CDHTUPLE*));
    // printf("print");
    return ron;
}

CRTUPLE** createCRTABLE() {
    CRTUPLE** ron = (CRTUPLE**)calloc(SIZE, sizeof(CRTUPLE*));
    // printf("print");
    return ron;
}



SNAPTUPLE* createSNAP(char *StudentId, char *Name, char* Address, char *Phone){
    SNAPTUPLE* tuple = (SNAPTUPLE*)malloc(sizeof(SNAPTUPLE*));
    tuple->StudentId = (char *)malloc(sizeof(char)*studentSize);
    tuple->Name = (char *)malloc(sizeof(char)*NameSize);
    tuple->Address = (char *)malloc(sizeof(char)*AddressSize);
    tuple->Phone = (char *)malloc(sizeof(char)*gradeSize);
    tuple->next = NULL;
    strcpy(tuple->Name, Name);
    strcpy(tuple->Address, Address);
    strcpy(tuple->StudentId, StudentId);
    strcpy(tuple->Phone, Phone);
    return tuple;
}

CPTUPLE* createCP(char* Course, char* Prerequisite){
    CPTUPLE* tuple = (CPTUPLE*)malloc(sizeof(CPTUPLE*));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Prerequisite = (char *)malloc(sizeof(char)*prereqSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Prerequisite, Prerequisite);
    return tuple;
}

CDHTUPLE* createCDH(char* Course, char* Day, char* Hour){
    CDHTUPLE* tuple = (CDHTUPLE*)malloc(sizeof(CDHTUPLE*));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Day = (char *)malloc(sizeof(char)*daySize);
    tuple->Hour = (char *)malloc(sizeof(char)*hourSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Day, Day);
    strcpy(tuple->Hour, Hour);
    return tuple;
}

CRTUPLE* createCR(char* Course, char* Room){
    CRTUPLE* tuple = (CRTUPLE*)malloc(sizeof(CRTUPLE*));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Room = (char *)malloc(sizeof(char)*roomSize);
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Room, Room);
    return tuple;
}


void insertSNAPIntoListOfCSGs(SNAPTUPLE* head, SNAPTUPLE* t){
    int c = 0;
    if(head == NULL){
        head = t;
        head->count = c;
    }else{
        SNAPTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
            ++c;
        }
        current->count = c;
        current->next = t;
    }
}
void insertCPIntoListOfCSGs(CPTUPLE* head, CPTUPLE* t){
    int c = 0;
    if(head == NULL){
        head = t;
        head->count = c;
    }else{
        CPTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
            ++c;
        }
        current->count = c;
        current->next = t;
    }
}
void insertCDHIntoListOfCSGs(CDHTUPLE* head, CDHTUPLE* t){
    int c = 0;
    if(head == NULL){
        head = t;
        head->count = c;
    }else{
        CDHTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
            ++c;
        }
        current->count = c;
        current->next = t;
    }
}

void insertCRIntoListOfCSGs(CRTUPLE* head, CRTUPLE* t){
    int c = 0;
    if(head == NULL){
        head = t;
        head->count = c;
    }else{
        CRTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
            ++c;
        }
        current->count = c;
        current->next = t;
    }
}

void insertSNAP(SNAPTUPLE* tuple, SNAPTUPLE** table){
    unsigned long hashIndex = hashSNAP(tuple->StudentId);
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (SNAPTUPLE*)malloc(sizeof(SNAPTUPLE*));
        table[hashIndex]->StudentId = strdup(tuple->StudentId);
        table[hashIndex]->Name = strdup(tuple->Name);
        table[hashIndex]->Address = strdup(tuple->Address);
        table[hashIndex]->Phone = strdup(tuple->Phone);
        table[hashIndex]->next = NULL;
    }else{
        SNAPTUPLE* head = table[hashIndex];
        insertSNAPIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        // printf("%d\n",table[hashIndex]->count);
    }
}

void insertCP(CPTUPLE* tuple, CPTUPLE** table){
    unsigned long hashIndex = hashCP(tuple->Course, tuple->Prerequisite);
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (CPTUPLE*)malloc(sizeof(CPTUPLE*));
        table[hashIndex]->Course = strdup(tuple->Course);
        table[hashIndex]->Prerequisite = strdup(tuple->Prerequisite);
        table[hashIndex]->next =NULL;
    }else{
        CPTUPLE* head = table[hashIndex];
        insertCPIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        // printf("%d\n",table[hashIndex]->count);
    }
}

void insertCDH(CDHTUPLE* tuple, CDHTUPLE** table){
    unsigned long hashIndex = hashCDH(tuple->Course, tuple->Day, tuple->Hour);
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (CDHTUPLE*)malloc(sizeof(CDHTUPLE*));
        table[hashIndex]->Course = strdup(tuple->Course);
        table[hashIndex]->Day = strdup(tuple->Day);
        table[hashIndex]->Hour = strdup(tuple->Hour);
        table[hashIndex]->next =NULL;
    }else{
        CDHTUPLE* head = table[hashIndex];
        insertCDHIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        // printf("%d\n",table[hashIndex]->count);
    }
}

void insertCR(CRTUPLE* tuple, CRTUPLE** table){
    unsigned long hashIndex = hashCR(tuple->Course, tuple->Room);
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (CRTUPLE*)malloc(sizeof(CRTUPLE*));
        table[hashIndex]->Course = strdup(tuple->Course);
        table[hashIndex]->Room = strdup(tuple->Room);
        table[hashIndex]->next =NULL;
    }else{
        CRTUPLE* head = table[hashIndex];
        insertCRIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        // printf("%d\n",table[hashIndex]->count);
    }
}

void fromfileSNAP(SNAPTUPLE** r, const char* f){
    FILE *fp;
    char line[100];
    if((fp = fopen(f, "r")) == NULL){
        printf("Error! opening SNAP file");
        exit(1);
    }
    while(fgets(line, 100, fp)){
        const char delim[2] = "|";
        char *token;
        int i=0, j;
        char *words[20];
        token = strtok(line, delim);
        while(token){
            words[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        for(int j = 0; j< i; j++){
            if(n>= SIZE){
                grow();
            }
            if(strcmp(words[j], "SNAP") == 0){
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertSNAP(createSNAP(words[1], words[2], words[3], words[4]), r);
            }
        }
    }
    fclose(fp);
}

void fromfileCP(CPTUPLE** r, const char* f){
    FILE *fp;
    char line[100];
    if((fp = fopen(f, "r")) == NULL){
        printf("Error! opening CP file");
        exit(1);
    }
    while(fgets(line, 100, fp)){
        const char delim[2] = "|";
        char *token;
        int i=0, j;
        char *words[20];
        token = strtok(line, delim);
        while(token){
            words[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        for(int j = 0; j< i; j++){
            if(n>= SIZE){
                grow();
            }
            if(strcmp(words[j], "CP") == 0){
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertCP(createCP(words[1], words[2]), r);
            }
        }
    }
    fclose(fp);
}


void fromfileCDH(CDHTUPLE** r, const char* f){
    FILE *fp;
    char line[100];
    if((fp = fopen(f, "r")) == NULL){
        printf("Error! opening CDH file");
        exit(1);
    }
    while(fgets(line, 100, fp)){
        const char delim[2] = "|";
        char *token;
        int i=0, j;
        char *words[20];
        token = strtok(line, delim);
        while(token){
            words[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        for(int j = 0; j< i; j++){
            if(n>= SIZE){
                grow();
            }
            if(strcmp(words[j], "CDH") == 0){
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertCDH(createCDH(words[1], words[2], words[3]), r);
            }
        }
    }
    fclose(fp);
}

void fromfileCR(CRTUPLE** r, const char* f){
    FILE *fp;
    char line[100];
    if((fp = fopen(f, "r")) == NULL){
        printf("Error! opening CR file");
        exit(1);
    }
    while(fgets(line, 100, fp)){
        const char delim[2] = "|";
        char *token;
        int i=0, j;
        char *words[20];
        token = strtok(line, delim);
        while(token){
            words[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        for(int j = 0; j< i; j++){
            if(n>= SIZE){
                grow();
            }
            if(strcmp(words[j], "CR") == 0){
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertCR(createCR(words[1], words[2]), r);
            }
        }
    }
    fclose(fp);
}

void printSNAP(SNAPTUPLE** t){
    for (int i = 0; i < SIZE; i++)  {
        SNAPTUPLE* head = t[i];
        if(head == NULL){
        // printf("print");

        }else{
            SNAPTUPLE* current = head;
            while(current != NULL){
                // printf("ten");
                printf("%s\t%s\t%s\n", current->StudentId, current->Name,current->Address, current->Phone);
                current = current->next;
            }
        }
    }
}

void printCP(CPTUPLE** t){
    for (int i = 0; i < SIZE; i++)  {
        CPTUPLE* head = t[i];
        if(head == NULL){
        // printf("print");

        }else{
            CPTUPLE* current = head;
            while(current != NULL){
                // printf("ten");
                printf("%s\t%s\t%s\n", current->Course, current->Prerequisite);
                current = current->next;
            }
        }
    }
}

void printCDH(CDHTUPLE** t){
    for (int i = 0; i < SIZE; i++)  {
        CDHTUPLE* head = t[i];
        if(head == NULL){
        // printf("print");

        }else{
            CDHTUPLE* current = head;
            while(current != NULL){
                // printf("ten");
                printf("%s\t%s\t%s\n", current->Course, current->Day,current->Hour);
                current = current->next;
            }
        }
    }
}

void printCR(CRTUPLE** t){
    for (int i = 0; i < SIZE; i++)  {
        CRTUPLE* head = t[i];
        if(head == NULL){
        // printf("print");

        }else{
            CRTUPLE* current = head;
            while(current != NULL){
                // printf("ten");
                printf("%s\t%s\t%s\n", current->Course, current->Room);
                current = current->next;
            }
        }
    }
}