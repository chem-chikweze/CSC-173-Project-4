#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rel.h"
#define courseSize 5
#define gradeSize 2
#define BASE (256)
#define SIZE (1008)

typedef struct CSG CSGTUPLE;
struct CSG {
    // a type but with no associated storage
    char *StudentId;  //conjugate key
    char *Course;    // = (char*) malloc (courseSize * sizeof(char)); //conjugate key
    char *Grade;     //  = (char*) malloc (gradeSize * sizeof(char)); //conjugate key
    CSGTUPLE* next;
    int count;
};
// typedef CSGTUPLE CSGTABLE[SIZE];


unsigned long hashCSG (char *Course, char *StudentId) {
    unsigned long hash;
    // elements will be treated as having values greater than 0
    hash = 0;
    // loops until the end of chars in Course
    for(char c = 0; c <strlen(StudentId); c++){
        hash += StudentId[c];
    }
    // loops until the end of chars in Course
    for(char d = 0; d <strlen(Course); d++){
        hash += Course[d];
    }
    return hash;
}

CSGTUPLE** createCSGTABLE() {
    CSGTUPLE** ron = (CSGTUPLE**)calloc(SIZE, sizeof(CSGTUPLE*));
    return ron;
}

CSGTUPLE* createCSG(char* Course, char *StudentId, char* Grade){
    CSGTUPLE *tuple = (CSGTUPLE*)malloc(sizeof(CSGTUPLE*));
    (tuple->Course) = (char*)malloc(sizeof(char)*20);
    tuple->StudentId = (char*)malloc(sizeof(char)*20);
    tuple->Grade = (char*)malloc(sizeof(char)*20);
    const char *c = Course;
    const char *s = StudentId;
    const char *g = Grade;
    tuple->Course = strdup(c);
    tuple->StudentId = strdup(s);   
    tuple->Grade = strdup(g);    
    tuple->next = NULL;
    // printf("%s\t%s\t%s\n", tuple->Course, tuple->StudentId, tuple->Grade);
    return tuple;
}

void insertCSGIntoListOfCSGs(CSGTUPLE* head, CSGTUPLE* t){
    int c = 0;
    if(head == NULL){
        head = t;
        head->count = c;
    }else{
        CSGTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
            ++c;
        }
        current->count = c;
        current->next = t;
        
    }
}

void insertCSG(CSGTUPLE* tuple, CSGTUPLE** table){
    unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
    // printf("Insert%s\t%d\n", tuple->Course, hashIndex); 
    
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (CSGTUPLE*)malloc(sizeof(CSGTUPLE*));
        table[hashIndex]->count = 0;
        table[hashIndex]->Course = strdup(tuple->Course);
        table[hashIndex]->Grade = strdup(tuple->Grade);
        table[hashIndex]->StudentId = strdup(tuple->StudentId);
        table[hashIndex]->next = NULL;
    }else{
        CSGTUPLE* head = table[hashIndex];
        insertCSGIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
        // printf("%d\n",table[hashIndex]->count);
    }
}

// void delete(CSGTUPLE tuple, CSGTABLE table){
    // c and s are keys in CSG so if one is missing O(n) linear search through the whole list
    // * S G
    // if(tuple->Course == "*" && tuple->StudentId != '*'){
    //     int count = 0;
    //     while (count < SIZE){
    //         if(table[count]->Grade == tuple->Grade && table[count]->StudentId == tuple->StudentId){
    //             table[count] = NULL;
    //         }
    //     }
    // }

    // C * G
    // if(tuple->Course != "*" && tuple->StudentId == '*'){
    //     int count = 0;
    //     while (count < SIZE){
    //         if(table[count]->Course == tuple->Course && table[count]->Grade == tuple->Grade){
    //             table[count] = NULL;
    //         }
    //     }
    // }

    // * * G;
    // if(tuple->Course == "*" && tuple->StudentId == '*' && tuple->Grade != '*'){
    //     int count = 0;
    //     while (count < SIZE){
    //         if(table[count]->Grade == tuple->Grade){
    //             table[count] = NULL;
    //         }
    //     }
    // }

    // C S *
    // if(tuple->Course != "*" && tuple->StudentId != '*' && tuple->Grade == '*'){
    //     int hash = hashCode(tuple->Course, tuple->StudentId);
    //     while (table[hash]){
    //     if(table[hash]->Course == tuple->Course && table[hash]->StudentId == tuple->StudentId){
    //         table[hash] = NULL;
    //         return NULL;
    //     } hash = (hash + 1) % SIZE;
    //     }
    // }

    // C S G
    // if(tuple->Course != "*" && tuple->StudentId != '*' && tuple->Grade != "*"){
    //     int hash = hashCode(tuple->Course, tuple->StudentId);
    //     while (table[hash]){
    //     if(table[hash]->Course == tuple->Course && table[hash]->StudentId == tuple->StudentId && table[hash]->Grade == tuple->Grade){
    //         table[hash] = NULL;
    //         return NULL;
    //     } hash = (hash + 1) % SIZE;
    //     }
    // }

    // int hash = hashCode(tuple->Course, tuple->StudentId);
    // while (table[hash]){
    //     if(table[hash]->Course == tuple->Course && table[hash]->StudentId == tuple->StudentId && table[hash]->Grade == tuple->Grade){
    //         table[hash] = NULL;
    //         return NULL;
    //     } hash = (hash + 1) % SIZE;
    // }    
// }

// void printTable(CSGTUPLE** t){
//     for (int i = 0; i < SIZE; i++)
//     {   
//         if (t[i] ){     printf("%s", t[i]->Course);     } 
//     }
// }

void printCSG(CSGTUPLE** t){
    printf("NULL\n");
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE* head = t[i];
        if(head == NULL){
        }else{
            CSGTUPLE* current = head;
            while(current != NULL){
                printf("%s\t%s\t%s\t%d\n", current->Course,current->StudentId,current->Grade, current->count);
                current = current->next;
            }
        }
    }
}

typedef struct database db;
struct database{
    CSGTUPLE** csg;
    SNAPTUPLE** snap;
    CPTUPLE** cp;
    CDHTUPLE** cdh;
    CRTUPLE** cr;
};

db createDB(){
    int n = 0;
    db *dbase =  malloc (sizeof(db));
    (dbase->csg) = createCSGTABLE();
    dbase->snap = createSNAPTABLE();
    dbase->cp = createCPTABLE();
    dbase->cdh = createCDHTABLE();
    dbase->cr = createCRTABLE();

    int i;
    for(i =0; i < SIZE; i++){
        dbase->csg[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->snap[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cr[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cdh[i] = NULL;
    }
    for(i =0; i < SIZE; i++){
        dbase->cp[i] = NULL;
    }
    return dbase;
}

int main() {
    CSGTUPLE** r = createCSGTABLE();
    insertCSG(createCSG("CSC 173", "123", "A"), r);
    insertCSG(createCSG("CSC 173", "123", "A"), r);
    insertCSG(createCSG("CSC 173", "123", "A"), r);
    printCSG(r);
    // printf("\n");
    // CSGTUPLE t1 = createTuple("CSC 173", "A", 123);
    // delete(t1, r);
    // printTable(r);
    return 0;
}



// void insert(CSGTUPLE tuple, CSGTABLE table){
//     int hashIndex = hashCode(tuple->Course, tuple->StudentId);
//     hashIndex = hashIndex % SIZE;
//     // go to bucket,, walk through bucket for if it contains the struct or not.
//     while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
//     table[hashIndex] = tuple;
// }