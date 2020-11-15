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
10. projection
11. join

**/

int main() {
    db r = createDB();
    fromFIle(r, "input.txt");
    CSGTUPLE t = createCSG("CSC 173", "A", 123);
    SNAPTUPLE s = createSNAP(345, "Adamma Chidi", "Onitsha", 585123123);
    CPTUPLE p = createCP("CSC 173", "CSC 172");
    CDHTUPLE h = createCDH("CSC 173", "Monday", "12:30pm");
    CRTUPLE rt = createCR("MTHs 173", "Room 2");

    insertCSG(t, r->csg);
    insertSNAP(s, r->snap);
    insertCP(p, r->cp);
    insertCDH(h, r->cdh);
    insertCR(rt, r->cr);

    // printf("\nYup %d", t->StudentId);
    // printf("\nYup %d", s->StudentId);
    // printf("\nYup %s", p->Prerequisite);printf("%s", "hen");
    // printf("\nYup %s", h->Hour);
    // printf("\nYup %s", rt->Room);
    // printf("\n");

    printCSG(r->csg);
    printSNAP(r->snap);
    printCP(r->cp);
    printCDH(r->cdh);
    printCR(r->cr);


    // printf("\n");
    // CSGTUPLE t1 = createCSGTuple("CSC 173", "A", 123);
    // delete(t1, r);
    // printTable(r);
    return 0;
}
