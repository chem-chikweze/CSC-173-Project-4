#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rel.c"
#include "db.h"

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
    // printf("print");
    return ron;
}

void grow(){
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

void fromfileCSG(CSGTUPLE** r, const char* f){
    FILE *fp;
    char line[100];
    if((fp = fopen(f, "r")) == NULL){
        printf("Error! opening file");
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
            if(strcmp(words[j], "CSG") == 0){
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertCSG(createCSG(words[1], words[2], words[3]), r);
            }
        }
    }
    fclose(fp);
}

void printCSG(CSGTUPLE** t){
    for (int i = 0; i < SIZE; i++)  {
        CSGTUPLE* head = t[i];
        if(head == NULL){
        // printf("print");

        }else{
            CSGTUPLE* current = head;
            while(current != NULL){
                // printf("ten");
                printf("%s\t%s\t%s\n", current->Course,current->StudentId,current->Grade);
                current = current->next;
            }
        }
    }
}

int main() {
    db d = createDB();
    d.csg  =  createCSGTABLE();
    d.snap  =  createSNAPTABLE();
    d.cp  =  createCPTABLE();
    d.cdh  =  createCDHTABLE();
    d.cr  =  createCRTABLE();
    // CSGTUPLE** r = createCSGTABLE();
    fromfileCSG(d.csg, "input.txt");
    fromfileSNAP(d.snap, "input.txt");
    fromfileCP(d.cp, "input.txt");
    fromfileCDH(d.cdh, "input.txt");
    fromfileCR(d.cr, "input.txt");
    printf("hye");
    insertCSG(createCSG("CSC 173", "123", "A"), d.csg );
    insertCSG(createCSG("CSC 173", "123", "A"), d.csg );
    insertCSG(createCSG("CSC 173", "123", "A"), d.csg );
    printCSG(d.csg );
    printSNAP(d.snap );
    printCP(d.cp);
    printCDH(d.cdh);
    printCR(d.cr);
    // printf("\n");
    // CSGTUPLE t1 = createTuple("CSC 173", "A", 123);
    // delete(t1, r);
    // printTable(r);
    return 0;
}
// int main() {
    // db r = createDB();
    // fromFIle(r, "input.txt");

    // //PRINT
    // printCSG(*(r->csg));
    // printSNAP(r->snap);
    // printCP(r->cp);
    // printCDH(r->cdh);    
    // printCR(r->cr);        

    // LOOKUP
    // CSGTUPLE rt = createCSG("CSC101", "12345", "*");
    // CSGTUPLE t = lookupCSG(rt, r->csg);
    // if(t !=NULL){
    //     printf("%s", t->Grade);
    // }else
    // {
    //     printf("\nh");
    // }
    
    // insertCR(rt, r->cr);
    // printf("\n%s\n", "print");
    // printf("\n");
    // CSGTUPLE t1 = createCSGTuple("CSC 173", "A", 123);
    // delete(t1, r);
    // printTable(r);
//     return 0;
// }


// void insert(CSGTUPLE tuple, CSGTABLE table){
//     int hashIndex = hashCode(tuple->Course, tuple->StudentId);
//     hashIndex = hashIndex % SIZE;
//     // go to bucket,, walk through bucket for if it contains the struct or not.
//     while ( table[hashIndex]){   hashIndex = (hashIndex + 1) % SIZE;    }
//     table[hashIndex] = tuple;
// }