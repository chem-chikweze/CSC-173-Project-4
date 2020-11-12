#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define courseSize 5
#define gradeSize 2
#define BASE (256)
#define m (1008)


// // add date. What part should it be? Attribute or key?
// // const int courseSize = 5;
// // const int gradeSize = 2;

typedef struct CSG *CSGLIST;
struct CSG {
    // a type but with no associated storage
    int StudentId;  //conjugate key
    char *Course;    // = (char*) malloc (courseSize * sizeof(char)); //conjugate key
    char *Grade;     //  = (char*) malloc (gradeSize * sizeof(char)); //conjugate key
    // char Course[courseSize]; //conjugate key
    // char Grade[gradeSize];
};
typedef CSGLIST HASHTABLE[1009];

// unsigned long hashCode (char *Course, int StudentId) {
//     unsigned long hash;
//     unsigned const char *cs;
//     // elements will be treated as having values greater than 0
//     cs = (unsigned const char *) Course;
//     hash = 0;
//     // loops until the end of chars in Course
//     while (*cs != '\0')
//     {
//         // multiplies current hash by BASE, adding current Course character and StudentId then mod m
//         hash = (hash * BASE + *cs + StudentId)% m;
//         cs++;
//     }
//     return hash;
// }

// void insert(char *Course, int StudentId, char *Grade){
//     int hash =  hashCode(Course, StudentId);
//     struct CSG *item = (struct CSG*) malloc (sizeof(struct CSG));
    
//     // for(int i = 0; i < courseSize; i++){
//     //     item->Course = *Course[i];
//     // }
//     // for(int i = 0; i < gradeSize; i++){
//     //     item->Grade = *Grade[i];
//     // }
    
//     // item->Course = Course;
//     // item->StudentId = StudentId;
//     // item->Grade = Grade;

//     // int hashIndex = hashCode(Course, StudentId);

//     // go to bucket,, walk through bucket for if it contains the struct or not.
//     // while (HASHTABLE[hashIndex] != NULL && HASHTABLE[hashIndex] )
//     // {
//     //     /* code */
//     // }
    
// }

int main() {
    printf("Hello World");
    return 0;
}