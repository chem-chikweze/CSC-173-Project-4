#include "rel.h"
#include "db.h"
#include "csg.c"


db createDB(){
    n = 0;
    db dbase = (db) malloc (sizeof(db));
    dbase->csg = createCSGTABLE();
    // dbase->snap = createSNAPTABLE();
    // dbase->cp = createCPTABLE();
    // dbase->cdh = createCDHTABLE();
    // dbase->cr = createCRTABLE();

    int i;
    for(i =0; i < SIZE; i++){
        dbase
    }
    // // for(i =0; i < SIZE; i++){
    // //     *(dbase->cr + i) = NULL;
    // // }

    // for(i =0; i < SIZE; i++){
    //     *(dbase->snap + i) = NULL;
    // }
    // for(i =0; i < SIZE; i++){
    //     *(dbase->cp + i) = NULL;
    // }
    // for(i =0; i < SIZE; i++){
    //     *(dbase->cdh + i) = NULL;

    // }
    return dbase;

}

void fromFIle(db r, const char *f){
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
                // int studentid;
                // sscanf(words[2], "%d", &studentid);
                CSGTUPLE t = createCSG(words[1], words[2], words[3]);
                // printf("%s\t%s\t%s",t->Course, t->StudentId, t->Grade);
                insertCSGTable(t, (r->csg));
            }
            // else if(strcmp(words[j], "SNAP") == 0){
            //     SNAPTUPLE t = createSNAP(words[1], words[2], words[3], words[4]);
            //     insertSNAP(t, r->snap);
            //     // printf("%s\t%d\t%d\t%s\n",t->Address, phone, t->Name, studentid);
            // }
            //  if(strcmp(words[j], "CP") == 0){
            //     CPTUPLE t = createCP(words[1], words[2]);
            //     insertCP(t, r->cp);
            //     // printf("2");
            //     // printf("%s\t%s",t->Course, t->Prerequisite);
            // }
            // if(strcmp(words[j], "CDH") == 0){
            //     CDHTUPLE t = createCDH(words[1], words[2], words[3]);
            //     insertCDH(t, r->cdh);
            // }
            // if(strcmp(words[j], "CR") == 0){
            //     CRTUPLE t = createCR(words[1], words[2]);
            //     insertCR(t, r->cr);

            // }
        }

    }
    fclose(fp)
}


void grow(){}