#include "db.c"
#include "rel.c"



/**
0 create the table structs do {}
1.  createdb 
    A struct that contains 5 hashtables.
2.  read from file
3.  lookup1
4.  lookup2
5.  file save
6.  advanced query
7.  union
8.  difference
9.  insert
10. projection    printf("1");
11. joinn


**/
int main() {
    db r = createDB();
    fromFIle(r, "input.txt");

    //PRINT
    printCSG(r->csg);
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
    return 0;
}

// void insert(HASHTABLE table, char *Course, int StudentId, char *Grade){
//     CSGLIST item = createTuple(Course, Grade, StudentId);
//     int hashIndex = hashCode(Course, StudentId);
//     // go to bucket,, walk through bucket for if it contains the struct or not.
//     while (table[hashIndex])
//     {
//         hashIndex += (hashIndex + 1) % SIZE;
//     }
//     table[hashIndex] = item;
// }
