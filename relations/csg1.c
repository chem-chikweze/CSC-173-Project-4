#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define courseSize 5
#define gradeSize 2
#define BASE (256)
#define SIZE (1008)

unsigned long hashCode (char *Course, int StudentId) {
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

HASHTABLE createHashtable() {
    HASHTABLE hashtable = (HASHTABLE) malloc (sizeof(HASHTABLE) * SIZE);
    for (int i = 0; i < SIZE; i++){ hashtable[i] = NULL;    }
    return hashtable;
}

CSGTUPLE createCSGTuple (char* Course, char* Grade, int StudentId){
    CSGTUPLE tuple = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Grade = (char *)malloc(sizeof(char)*gradeSize);
    tuple->StudentId = StudentId;
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Grade, Grade);
    return tuple;
}

void insert(CSGTUPLE tuple, HASHTABLE table){
    int hashIndex = hashCode(tuple->Course, tuple->StudentId);
    // go to bucket,, walk through bucket for if it contains the struct or not.
    while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
    table[hashIndex] = tuple;
}

// void delete(CSGTUPLE tuple, HASHTABLE table){
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

//     int hash = hashCode(tuple->Course, tuple->StudentId);
//     while (table[hash]){
//         if(table[hash]->Course == tuple->Course && table[hash]->StudentId == tuple->StudentId && table[hash]->Grade == tuple->Grade){
//             table[hash] = NULL;
//             return NULL;
//         } hash = (hash + 1) % SIZE;
//     }    
// }

// void printTable(HASHTABLE t){
//     for (int i = 0; i < SIZE; i++)
//     {   
//         if (t[i] ){     printf("%s", t[i]->Course);     } 
//     }
// }

// int main() {
//     HASHTABLE r = createHashtable();
//     CSGTUPLE t = createCSGTuple("CSC 173", "A", 123);
//     insert(t, r);
//     printTable(r);
//     printf("\n");
//     CSGTUPLE t1 = createCSGTuple("CSC 173", "A", 123);
//     delete(t1, r);
//     printTable(r);
//     return 0;
// }