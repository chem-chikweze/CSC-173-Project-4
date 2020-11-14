//table 1: course studentid grade   CSG
// add date. What part should it be? Attribute or key?
struct CSG {
    char *Course; //conjugate key
    int StudentId;  //conjugate key
    char *Grade;
};
//table 2: StudentId Name Address Phone  SNAP
struct SNAP {
    int StudentId;  //k
    char *Name;
    char *Address;
    int Phone;
};
// table 3:Course Prerequisite    CP
struct CP {
    char *Course;             //conjugate key
    char *Prerequisite;       //conjugate key
};
//table 4:Course Day Hour    CDH
struct CDH {
    char *Course;         //conjugate key
    char *Day;            //conjugate key
    char *Hour           //conjugate key
};
//table 5:Course Room    CR
struct CDH {
    char *Course;
    char *Room;
};

