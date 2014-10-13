//##################Helper Functions#############################
void print_Array(int *array, int lastIndx);
void printVal(int val);
int countOfArray(int *ar);
int scanInt();

//################## 1D #############################
one_D_Array init_one_D_Array();
one_D_Array addToArray(one_D_Array array, int toAdd);

//################## 2D #############################
int **init_2d_Array(void);
int **addArrayToArray(int **array, int *toAdd, int oldcount);
void print2dArray(int **array, int count);
