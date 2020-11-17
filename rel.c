#include "rel.h"
#include "db.h"


// unsigned long hashCSG (char *Course, char *StudentId) {
//     unsigned long hash = 0;
//     int val1 = 0;
//     const char *c = Course;
//
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
//
//     hash = (val1 * BASE)% SIZE;
//     return hash;
// }

unsigned long hashSNAP (char *StudentId){
    unsigned long hash = 0;
    int val1;
    const char *s = StudentId;
    while (s != NULL && *s != '\0')
    {
        val1 += (intptr_t)s;
        ++s;
    }

    hash = (val1 * BASE)% SIZE;
    return hash;
}

unsigned long hashCP (char *Course, char* Prerequisite){
    unsigned long hash;
    int val1,val2, val3;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Prerequisite);
    val2 = atoi(str);
    val3 = val1*val2;
    hash = (val3 * BASE)% SIZE;
    return hash;
}

unsigned long hashCDH (char* Course, char* Day, char* Hour){
    unsigned long hash;
    int val1,val2, val3,val4;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Day);
    val2 = atoi(str);
    strcpy(str, Hour);
    val3 = atoi(str);
    val4 = val1*val2*val3;
    hash = (val4 * BASE)% SIZE;  
    return hash;
}

unsigned long hashCR (char* Course, char* Room){
    int hash  = 0;
    int val1,val2, val3 = 0;
    char str[100];
    strcpy(str, Course);
    val1 =  atoi(str);
    strcpy(str, Room);
    val2 = atoi(str);
    val3 = val1*val2 + val1 * 47;
    hash = ((val3 * BASE* 47) )% SIZE;

    // printf("RMH%s%d\n", Room, hash);
    return hash;
}



// CSGTUPLE createCSG(char* Course, char *StudentId, char* Grade){
//     CSGTUPLE tuple = (CSGTUPLE)malloc(sizeof(CSGTUPLE));
//     tuple->Course = strdup(Course);
//     tuple->Grade = strdup(Grade);
//     tuple->StudentId = strdup(StudentId);
//     tuple->next = NULL;
//     return tuple;
// }

SNAPTUPLE createSNAP(char *StudentId, char *Name, char* Address, char *Phone){
    SNAPTUPLE tuple = (SNAPTUPLE)malloc(sizeof(SNAPTUPLE));
    tuple->StudentId = strdup(StudentId);
    tuple->Name = strdup(Name);
    tuple->Address = strdup(Address);
    tuple->Phone = strdup(Phone);
    tuple->next = NULL;
    return tuple;
}

CPTUPLE createCP(char* Course, char* Prerequisite){
    CPTUPLE tuple = (CPTUPLE)malloc(sizeof(CPTUPLE));
    tuple->Course = strdup(Course);
    tuple->Prerequisite = strdup(Prerequisite);
    tuple->next = NULL;
    return tuple;
}

CDHTUPLE createCDH(char* Course, char* Day, char* Hour){
    CDHTUPLE tuple = (CDHTUPLE)malloc(sizeof(CDHTUPLE));
    tuple->Course = strdup(Course);
    tuple->Day = strdup(Day);
    tuple->Hour = strdup(Hour);
    tuple->next = NULL;
    return tuple;
}

CRTUPLE createCR(char* Course, char* Room){
    CRTUPLE tuple = (CRTUPLE)malloc(sizeof(CRTUPLE));
    tuple->Course = strdup(Course);
    tuple->Room = strdup(Room);
    tuple->next = NULL;
    return tuple;
}

void insertNodeCSG(CSGTABLE table){

}

// void insertCSG(CSGTUPLE tuple, CSGTABLE table){
//     unsigned long hashIndex = hashCSG(tuple->Course, tuple->StudentId);
//     hashIndex = hashIndex % SIZE;
//     if(table[hashIndex] == NULL){
//         table[hashIndex] = malloc(sizeof(CSGTUPLE));
//
//         CSGTUPLE head = NULL;
//         insertNodeCSG(&head, tuple);
//         table[hashIndex] = head;
//     }else
//     {
//         CSGTUPLE head = table[hashIndex];
//         insertListCSG(&head, table);
//       
//         table[hashIndex] = head;
//     }
// //     tuple->next = table[hashIndex];
// // //     if(table[hashIndex]){    printf("second %d\t%s\n", hashIndex, tuple->next->Course);
// // // }
// //     table[hashIndex] = tuple;
// //     n++;
//     // printf("%d\t%s", hashIndex, table[hashIndex]->Grade);
// }

void insertSNAP(SNAPTUPLE tuple, SNAPTABLE table){
    unsigned long hashIndex = hashSNAP(tuple->StudentId);
    tuple->next = table[hashIndex];
    table[hashIndex] = tuple;
    n++;
}

void insertCP(CPTUPLE tuple, CPTABLE table){
    int hashIndex = hashCP(tuple->Course, tuple->Prerequisite);
    tuple->next = table[hashIndex];
    table[hashIndex] = tuple;
    n++;

}

void insertCDH(CDHTUPLE tuple, CDHTABLE table){
    int hashIndex = hashCDH(tuple->Course, tuple->Day, tuple->Hour);
    tuple->next = table[hashIndex];
    table[hashIndex] = tuple;
    n++;

}

void insertCR(CRTUPLE tuple, CRTABLE table){
    int hashIndex = hashCR(tuple->Course, tuple->Room);
    tuple->next = table[hashIndex];
    table[hashIndex] = tuple;
    n++;
}

// void printCSG(CSGTABLE t){
//     for (int i = 0; i < 45; i++)  {
//         for(CSGTUPLE e = t[i]; e != NULL; e = e->next){
//             printf("%s\t%s\t%s", t[i]->Course,t[i]->StudentId,t[i]->Grade);
//         }
//     }
//
//     // for (int i = 0; i < CSGSIZE; i++)
//     // {   
//     //     if (t[i] ){  
//     //         printf("\n%s\t%d\t%s", t[i]->Course,t[i]->StudentId,t[i]->Grade);     
//     //     } 
//     // }
// }

void printSNAP(SNAPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%d\t%s\t%d\n", t[i]->Name, t[i]->StudentId, t[i]->Address, t[i]->Phone);     
            // printf("%d\t", t[i]->StudentId);     
            // printf("%s\t", t[i]->Address);     
            // printf("%d\n", t[i]->Phone);     
        } 
    }
}
void printCP(CPTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){   
            printf("%s\t%s", t[i]->Course, t[i]->Prerequisite);     
        } 
    }
}
void printCDH(CDHTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%s\t%s", t[i]->Course, t[i]->Day, t[i]->Hour);        
            // printf("%s\t", t[i]->Day);        
            // printf("%s\n", t[i]->Hour);     
        } 
    }
}
void printCR(CRTABLE t){
    for (int i = 0; i < CSGSIZE; i++)
    {   
        if (t[i] ){     
            printf("%s\t%s", t[i]->Course, t[i]->Room);        
        } 
    }
}


// CSGTUPLE lookupCSG(CSGTUPLE tuple, CSGTABLE table){
//     // printf("%s\t%s\n", tuple->Course, tuple->Grade);
// /
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
// 
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
// 
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
// 
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
// 
//     // * * *
//     else if(!strcmp(tuple->Course,"*") && !strcmp(tuple->StudentId, "*") && !strcmp(tuple->Grade, "*")){
//         for (int i = 0; i < SIZE; i++)  {
//             for(CSGTUPLE e = table[i]; e != NULL; e = e->next){
// 
//                 return e;
// 
//             }
//         }
//     }
//    
//     return NULL;
// }

// SNAPTUPLE lookupSNAP(SNAPTUPLE tuple, SNAPTABLE table){
//     return NULL;
// }
// CPTUPLE lookupCP(CPTUPLE tuple, CPTABLE table){}
// CDHTUPLE lookupCDH(CDHTUPLE tuple, CDHTABLE table){}
// CRTUPLE lookupCR(CRTUPLE tuple, CRTABLE table){}