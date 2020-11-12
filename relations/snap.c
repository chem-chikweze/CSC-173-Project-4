#include <stdlib.h>

typedef struct SNAP *SNAPLIST;
struct SNAP {
    int StudentId;
    char Name[30];
    char Address[50];
    char Phone[8];
    SNAPLIST next;
};
typedef SNAPLIST HASHTABLE[1009];

int hashCode (int StudentId) {
    return StudentId % 1009;
}

void insert(int StudentId, char *Name, char *Address, char *Phone){
    int hash =  hashCode(StudentId);
    struct SNAP *item = (struct SNAP*) malloc (sizeof(struct SNAP));
    item->StudentId = StudentId;

    // item->Name = Name;
    // item->Address = Address;
    // item->Phone = Phone; 

    // get hash bucket
    int hashIndex = hashCode(StudentId);

    // go to bucket,, walk through bucket for if it contains the struct or not.
    // while (HASHTABLE[hashIndex] != NULL && HASHTABLE[hashIndex] )
    // {
    //     /* code */
    // }
    
}