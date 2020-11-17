#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
};
// typedef CSGTUPLE CSGTABLE[SIZE];

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

CSGTUPLE** createCSGTABLE() {
    CSGTUPLE** ron = calloc(SIZE, sizeof(CSGTUPLE*));
    return ron;
}

CSGTUPLE* createCSG(char* Course, char *StudentId, char* Grade){
    CSGTUPLE *tuple = (CSGTUPLE*)malloc(sizeof(CSGTUPLE*));
    tuple->Course = strdup(Course);
    tuple->Grade = strdup(Grade);
    printf("hey");
    tuple->StudentId = strdup(StudentId);
    tuple->next = NULL;
    return tuple;
}

void insertCSGIntoListOfCSGs(CSGTUPLE* head, CSGTUPLE* t){
    if(head == NULL){
        head = t;
    }else{
        CSGTUPLE* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = t;
    }
}

void insertCSG(CSGTUPLE* tuple, CSGTUPLE** table){
    unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
    hashIndex = hashIndex % SIZE;
    if(table[hashIndex] == NULL){
        table[hashIndex] = (CSGTUPLE*)malloc(sizeof(CSGTUPLE*));
        CSGTUPLE* head = NULL;
        insertCSGIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
    }else{
        CSGTUPLE* head = table[hashIndex];
        insertCSGIntoListOfCSGs(head, tuple);
        table[hashIndex] = head;
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
    printf("NULL");
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE* head = t[i];
        if(head == NULL){
            printf("NULL");
        }else{
            CSGTUPLE* current = head;
            while(current != NULL){
                printf("NULL");
                printf("%s\t%s\t%s", current->Course,current->StudentId,current->Grade);
                current = current->next;
            }
        }
    }
}

int main() {
    CSGTUPLE** r = createCSGTABLE();
    CSGTUPLE* t = createCSG("CSC 173", "A", 123);
    printf("NULL");
    insertCSG(t, r);
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