//table 1: course studentid grade   CSG
// add date. What part should it be? Attribute or key?
typedef struct CSG *CSGTUPLE;
struct CSG {
    char *Course; //conjugate key
    char* StudentId;  //conjugate key
    char *Grade;
    CSGTUPLE* next;
};
//table 2: StudentId Name Address Phone  SNAP
typedef struct SNAP *SNAPTUPLE;
struct SNAP {
    char* StudentId;  //k
    char *Name;
    char *Address;
    int Phone;
};
// table 3:Course Prerequisite    CP
typedef struct CP *CPTUPLE;
struct CP {
    char *Course;             //conjugate key
    char *Prerequisite;       //conjugate key
};
//table 4:Course Day Hour    CDH
typedef struct CDH *CDHTUPLE;
struct CDH {
    char *Course;         //conjugate key
    char *Day;            //conjugate key
    char *Hour           //conjugate key
};
//table 5:Course Room    CR
typedef struct CR *CRTUPLE;
struct CR {
    char *Course;
    char *Room;
};

