#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define courseSize 5
#define gradeSize 2
#define BASE (256)
#define SIZE (1008)

typedef struct CSG *CSGLIST;
struct CSG {
    // a type but with no associated storage
    int StudentId;  //conjugate key
    char *Course;    // = (char*) malloc (courseSize * sizeof(char)); //conjugate key
    char *Grade;     //  = (char*) malloc (gradeSize * sizeof(char)); //conjugate key
    CSGLIST next;
};
typedef CSGLIST* HASHTABLE;

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
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    
    return hashtable;
}

CSGLIST createTuple(char* Course, char* Grade, int StudentId){
    CSGLIST tuple = (CSGLIST)malloc(sizeof(CSGLIST));
    tuple->Course = (char *)malloc(sizeof(char)*courseSize);
    tuple->Grade = (char *)malloc(sizeof(char)*gradeSize);
    tuple->StudentId = StudentId;
    tuple->next = NULL;
    strcpy(tuple->Course, Course);
    strcpy(tuple->Grade, Grade);
    return tuple;
}

void insert(HASHTABLE table, char *Course, int StudentId, char *Grade){
    CSGLIST item = createTuple(Course, Grade, StudentId);
    int hashIndex = hashCode(Course, StudentId);
    // go to bucket,, walk through bucket for if it contains the struct or not.
    while (table[hashIndex])
    {
        hashIndex += (hashIndex + 1) % SIZE;
    }
    table[hashIndex] = item;
}

void printTable(HASHTABLE t){
    for (int i = 0; i < SIZE; i++)
    {
        if (t[i] )
        {
            printf("%s", t[i]->Course);
        }
        
    }
    
}
int main() {
    // printf("Hello World");
    HASHTABLE t = createHashtable();
    insert(t, "CSC 173", 123, "A");
    printTable(t);
    return 0;
}