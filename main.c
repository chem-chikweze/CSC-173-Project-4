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

11. join

**/
int main() {
    db r = createDB();
    // fromFIle(r, "input.txt");
    CRTUPLE rt = createCR("MTHs 173", "Room 2");
    insertCR(rt, r->cr);
  

    // printCSG(r->csg);
    // printSNAP(r->snap);
    // printCP(r->cp);
    // printCDH(r->cdh);    printf("1");

    // printCR(r->cr);

    // printf("\n%s\n", "print");
    // printf("\n");
    // CSGTUPLE t1 = createCSGTuple("CSC 173", "A", 123);
    // delete(t1, r);
    // printTable(r);
    return 0;
}

