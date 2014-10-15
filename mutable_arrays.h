typedef struct {
    int lastIndx;
    int *array;
    
}one_D_Array;

typedef struct  {
    int lastIndx;
    int count;
    one_D_Array *array; 
}two_D_Array;



//##################Helper Functions#############################

void printVal(int val);
int countOfArray(int *ar);
int scanInt();

//##################1D Array#############################

one_D_Array init_one_D_Array();
one_D_Array addToArray(one_D_Array array, int toAdd);
void print_Array(int *array, int lastInd);

//##################2D Array#############################

int **init_2d_Array(void);
void print_2d_Array(int **array, int len, int lastInd);
int **addArrayToArray(int **array, int *toAdd, int oldcount);

//##################2D STRUCT ARRAY####################
	
one_D_Array* init_Struct_Array_1D();
two_D_Array init_2D_Struct(void);
void add_To_2D_Struct(one_D_Array toAdd, two_D_Array addedTo);
void print_2D_Struct(two_D_Array toPrint, int untilIndx);
