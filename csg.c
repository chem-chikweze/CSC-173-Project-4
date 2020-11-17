#include "rel.h"
#include "db.h"
#include <stdbool.h>


CSGTABLE createCSGTable() {
	CSGTABLE hashtable = (CSGTABLE)malloc(sizeof(CSGTABLE));
    hashtable->size = SIZE;
	for(int i = 0; i < SIZE; i++ ) {
		if((hashtable)->table[i] == NULL){printf("hey");}
	}
	hashtable->size = SIZE;
	return hashtable;	
}

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
    hash = (val1 * 7)% SIZE;
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

void insertCSGTable(CSGTABLE table, char* Course, char *StudentId, char* Grade){
    unsigned long hashIndex = hashCSG(Course, StudentId);
    hashIndex = hashIndex % SIZE;
    if(table->table.->table.->table[hashIndex] == NULL){
        table->table[hashIndex] = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
        CSGTUPLE head = NULL;
        insertCSGIntoListOfCSGs(head, tuple);
        table->table[hashIndex] = head;
    }else{
        CSGTUPLE head = table->table[hashIndex];
        insertCSGIntoListOfCSGs(head, tuple);
        table->table[hashIndex] = head;
    }
}

void printCSG(CSGTABLE t){
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE head = t->table[i];
        // printf("%d: ", i);
        if(head == NULL){
            printf("NULL");
        }else{
            CSGTUPLE current = head;
            while(current != NULL){
                printf("%s\t%s\t%s", current->Course,current->StudentId,current->Grade);
                current = current->next;
            }
        }
        // printf("\n");?
    }
}

// CSGTUPLE lookupCSG(CSGTUPLE tuple, CSGTABLE table){
//     // printf("%s\t%s\n", tuple->Course, tuple->Grade);

//     // C S G or C S *
//     if(strcmp(tuple->Course,"*") != 0 && strcmp(tuple->StudentId, "*") != 0){
//         printf("f");
//         int index = hashCSG(tuple->Course, tuple->StudentId);
//         for(CSGTUPLE e = table[hashCSG(tuple->Course, tuple->StudentId) % SIZE]; e != NULL; e = e->next){
//             if(!strcmp(e->Course, tuple->Course) && !strcmp(e->StudentId, tuple->StudentId)){
//                 return e;
//             }
//         }
//         return 0;

//     }
//     // * S G
//     else if( !strcmp(tuple->Course,"*") && strcmp(tuple->StudentId, "*") != 0 && strcmp(tuple->Grade, "*") != 0 ){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
//                 if(!strcmp(e->StudentId, tuple->StudentId) && !strcmp(tuple->Grade, tuple->Grade)){
//                     return e;
//                 }
//             }
//         }
//     }
//     // * S *
//     else if( !strcmp(tuple->Course,"*") && strcmp(tuple->StudentId, "*") != 0 && !strcmp(tuple->Grade, "*") ){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
//                 if(!strcmp(e->StudentId, tuple->StudentId)){
//                     return e;
//                 }
//             }
//         }
//     }

//     // C * G
//     else if( strcmp(tuple->Course,"*") != 0 && !strcmp(tuple->StudentId, "*") && strcmp(tuple->Grade, "*") != 0 ){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
//                 if(!strcmp(e->Grade, tuple->Grade) && !strcmp(tuple->Course, tuple->Course)){
//                     return e;
//                 }
//             }
//         }
//     }
//     // C * *
//     else if( strcmp(tuple->Course,"*") != 0 && !strcmp(tuple->StudentId, "*") && !strcmp(tuple->Grade, "*") ){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
//                 if(!strcmp(tuple->Course, tuple->Course)){
//                     printf("%s", e->Course);
//                     return e;
//                 }
//             }
//         }
//     }

//     // * * G
//     else if(!strcmp(tuple->Course,"*") && !strcmp(tuple->StudentId, "*") && strcmp(tuple->Grade, "*") != 0){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
//                 if(!strcmp(e->Grade, tuple->Grade)){
//                     return e;
//                 }
//             }
//         }
//     }

//     // * * *
//     else if(!strcmp(tuple->Course,"*") && !strcmp(tuple->StudentId, "*") && !strcmp(tuple->Grade, "*")){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){

//                 return e;

//             }
//         }
//     }
    
//     return NULL;
// }