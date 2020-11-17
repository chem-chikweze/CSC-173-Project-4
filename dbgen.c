#include "rel.h"
#include "db.h"


db createDB(){
    n = 0;
    db dbase = (db) malloc (sizeof(db));
    dbase->csg = malloc(sizeof(CSGTABLE) * CSGSIZE);
    dbase->snap = (SNAPTABLE)malloc(sizeof(SNAPTABLE) * SNAPSIZE);
    dbase->cp = (CPTABLE)malloc(sizeof(CPTABLE) * CPSIZE);
    dbase->cdh = (CDHTABLE)malloc(sizeof(CDHTABLE) * CDHSIZE);
    dbase->cr = (CRTABLE)malloc(sizeof(CRTABLE) * CRSIZE);

    int i;
    for(i =0; i < SIZE; i++){
        *(dbase->cr + i) = NULL;
    }
    for(i =0; i < SIZE; i++){
        *(dbase->csg + i) = NULL;
    }
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

void fromFIle(db r, char *f){
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
                insertCSG(t, r->csg);
                // printf("%s%s%d\n",t->Course, t->Grade, studentid);
            }
            else if(strcmp(words[j], "SNAP") == 0){
                // int phone;
                // sscanf(words[4], "%d", &phone);
                // int studentid;
                // sscanf(words[1], "%d", &studentid);
                SNAPTUPLE t = createSNAP(words[1], words[2], words[3], words[4]);
                insertSNAP(t, r->snap);
                // printf("%s\t%d\t%d\t%s\n",t->Address, phone, t->Name, studentid);
            }
             if(strcmp(words[j], "CP") == 0){
                CPTUPLE t = createCP(words[1], words[2]);
                insertCP(t, r->cp);
                // printf("2");
                // printf("%s\t%s",t->Course, t->Prerequisite);
            }
            if(strcmp(words[j], "CDH") == 0){
                CDHTUPLE t = createCDH(words[1], words[2], words[3]);
                insertCDH(t, r->cdh);
            }
            if(strcmp(words[j], "CR") == 0){
                CRTUPLE t = createCR(words[1], words[2]);
                insertCR(t, r->cr);

            }
        }

    }
    fclose(fp);

}


void grow(){}