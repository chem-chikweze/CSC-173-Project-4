#include "rel.h"
#include "db.h"
#include <stdbool.h>

unsigned long hashCSG (char *Course, char *StudentId) {
    unsigned long hash = 0;
    int val1 = 0;
    const char *c = Course;

    while (c != NULL && *c != '\0')
    {
        val1 += (intptr_t)c;
        ++c;
    }
    const char *s = StudentId;
    while (s != NULL && *s != '\0')
    {
        val1 += (intptr_t)s;
        ++s;
    }

    hash = (val1 * BASE)% SIZE;
    return hash;
}

CSGTUPLE createCSG(char* Course, char *StudentId, char* Grade){
    CSGTUPLE tuple = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
    tuple->Course = strdup(Course);
    tuple->Grade = strdup(Grade);
    tuple->StudentId = strdup(StudentId);
    tuple->next = NULL;
    return tuple;
}

void insertCSGIntoListOfCSGs(CSGTUPLE head, CSGTUPLE t){
    if(head == NULL){
        head = t;
    }else{
        CSGTUPLE current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = t;
    }
}

void insertCSG(CSGTUPLE tuple, CSGTABLE table){
    unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
    hashIndex = hashIndex % SIZE;
    
    if(table[hashIndex] == NULL){
        table[hashIndex] = malloc(sizeof(CSGTUPLE));

        CSGTUPLE head = NULL;
        insertCSGIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        if(table[hashIndex]== NULL){printf("f");}
        // printf("NULL%s\t%s\t%s\n", table[hashIndex]->Course,table[hashIndex]->StudentId,table[hashIndex]->Grade);
    }else{
        CSGTUPLE head = table[hashIndex];
        insertCSGIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        if(table[hashIndex]== NULL){printf("o");}
        // printf("HOPE%s\t%s\t%s\n", table[hashIndex]->Course,table[hashIndex]->StudentId,table[hashIndex]->Grade);
    }
}

void printCSG(CSGTABLE t){
    
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE head = t[i];
        if(head == NULL){
            // printf("%d\n", i);
        }else{
            CSGTUPLE current = head;
            while(current != NULL){
                printf("%s\t%s\t%s\n", t[i]->Course,t[i]->StudentId,t[i]->Grade);
                current = current->next;
            }
        }
    }
}

CSGTUPLE lookupCSG(CSGTUPLE tuple, CSGTABLE table){
    // printf("%s\t%s\n", tuple->Course, tuple->Grade);

    // C S G or C S *
    if(strcmp(tuple->Course,"*") != 0 && strcmp(tuple->StudentId, "*") != 0){
        printf("f");
        int index = hashCSG(tuple->Course, tuple->StudentId);
        for(CSGTUPLE e = table[hashCSG(tuple->Course, tuple->StudentId) % SIZE]; e != NULL; e = e->next){
            if(!strcmp(e->Course, tuple->Course) && !strcmp(e->StudentId, tuple->StudentId)){
                return e;
            }
        }
        return 0;

    }
    // * S G
    else if( !strcmp(tuple->Course,"*") && strcmp(tuple->StudentId, "*") != 0 && strcmp(tuple->Grade, "*") != 0 ){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
                if(!strcmp(e->StudentId, tuple->StudentId) && !strcmp(tuple->Grade, tuple->Grade)){
                    return e;
                }
            }
        }
    }
    // * S *
    else if( !strcmp(tuple->Course,"*") && strcmp(tuple->StudentId, "*") != 0 && !strcmp(tuple->Grade, "*") ){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
                if(!strcmp(e->StudentId, tuple->StudentId)){
                    return e;
                }
            }
        }
    }

    // C * G
    else if( strcmp(tuple->Course,"*") != 0 && !strcmp(tuple->StudentId, "*") && strcmp(tuple->Grade, "*") != 0 ){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
                if(!strcmp(e->Grade, tuple->Grade) && !strcmp(tuple->Course, tuple->Course)){
                    return e;
                }
            }
        }
    }
    // C * *
    else if( strcmp(tuple->Course,"*") != 0 && !strcmp(tuple->StudentId, "*") && !strcmp(tuple->Grade, "*") ){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
                if(!strcmp(tuple->Course, tuple->Course)){
                    printf("%s", e->Course);
                    return e;
                }
            }
        }
    }

    // * * G
    else if(!strcmp(tuple->Course,"*") && !strcmp(tuple->StudentId, "*") && strcmp(tuple->Grade, "*") != 0){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
                if(!strcmp(e->Grade, tuple->Grade)){
                    return e;
                }
            }
        }
    }

    // * * *
    else if(!strcmp(tuple->Course,"*") && !strcmp(tuple->StudentId, "*") && !strcmp(tuple->Grade, "*")){
        for (int i = 0; i < SIZE; i++)  {
            for(CSGTUPLE e = table[i]; e != NULL; e = e->next){

                return e;

            }
        }
    }
    
    return NULL;
}