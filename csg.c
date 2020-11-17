#include "rel.h"
#include "db.h"
#include <stdbool.h>


struct attribute
{   // attributes of a tuple.
    char* name;
    char* value;
    bool key;
    int columns;
    struct attribute* next;
};
typedef struct attribute* element; // a list of attributes is a tuple. 
//tuple is a pointer to the first attribute in the list.
// hashtable is an array of tuples. (list-elements)

struct node{
    element e;
    struct* node;
}
typedef struct element** hashtable;


unsigned long hash(element e) {
    unsigned long hash = 0;
    element current = e;
    while(current->next != NULL){
        if(current->key == 1){
            const char *c = current->value;
            while (c != NULL && *c != '\0'){
                hash += (intptr_t)c;
                ++c;
            }
        }
    }
    hash = (hash * BASE)% SIZE;
    return hash;
}

void insertIntoList(element head, element new_element){
    if(head == NULL){
        head = new_element;
    }else{
        element current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_element;
    }
}

void insertIntoTable(element e, hashtable t){
    unsigned long hashIndex = hash(e);
    hashIndex = hashIndex % SIZE;
    if(t[hashIndex] == NULL){
        t[hashIndex] = malloc(sizeof(element));

        element head = NULL;
        insertCSGIntoListOfCSGs(head, e);
        t[hashIndex] = head;
    }else{
        element head = t[hashIndex];
        insertCSGIntoListOfCSGs(head, e);
        t[hashIndex] = head;
    }

}
// unsigned long hashCSG (char *Course, char *StudentId) {
//     unsigned long hash = 0;
//     int val1 = 0;
//     const char *c = Course;

//     while (c != NULL && *c != '\0')
//     {
//         val1 += (intptr_t)c;
//         ++c;
//     }
//     const char *s = StudentId;
//     while (s != NULL && *s != '\0')
//     {
//         val1 += (intptr_t)s;
//         ++s;
//     }

//     hash = (val1 * BASE)% SIZE;
//     return hash;
// }

CSGTUPLE createCSG(char* Course, char *StudentId, char* Grade){
    CSGTUPLE tuple = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
    tuple->Course = strdup(Course);
    tuple->Grade = strdup(Grade);
    tuple->StudentId = strdup(StudentId);
    tuple->next = NULL;
    return tuple;
}
// void insertCSGIntoListOfCSGs(CSGTUPLE head, CSGTUPLE t){
//     if(head == NULL){
//         head = t;
//     }else{
//         CSGTUPLE current = head;\
//         while(current->next != NULL){
//             current = current->next;
//         }
//         current->next = t;
//     }
// }
// void insertCSG(CSGTUPLE tuple, CSGTABLE table){
//     unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
//     hashIndex = hashIndex % SIZE;
//     if(table[hashIndex] == NULL){
//         table[hashIndex] = malloc(sizeof(CSGTUPLE));

//         CSGTUPLE head = NULL;
//         insertCSGIntoListOfCSGs(head, tuple);
//         table[hashIndex] = head;
//     }else{
//         CSGTUPLE head = table[hashIndex];
//         insertCSGIntoListOfCSGs(head, tuple);
//         table[hashIndex] = head;
//     }

// }

void print(hashtable t){
    for (int i = 0; i < SIZE; i++)  {
        element head = t[i];
        if(head == NULL){
        }else{
            element current = head;
            while(current != NULL){
                printElement(current);
                // printf("%s\t%s\t%s", t[i]->Course,t[i]->StudentId,t[i]->Grade);
                current = current->next;
            }
        }
    }
}

void printCSG(CSGTABLE t){
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE head = t[i];
        if(head == NULL){
        }else{
            CSGTUPLE current = head;
            while(current != NULL){
                printf("%s\t%s\t%s", t[i]->Course,t[i]->StudentId,t[i]->Grade);
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