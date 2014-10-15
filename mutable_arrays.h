#include <stdio.h>
#include <stdlib.h>

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

/*-----------------------+(Function Definitions)+-------------------------------------*/
/*------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------*/

#define PRINT_STR(str) {\
printf("%s", str);\
}

//##################Helper Functions#############################

int sizeint = 1;

void printVal(int val) {
    printf("%d", val);
}

int countOfArray(int *ar){
    int sizf = sizeof(*ar) / sizeof(int);
    printVal(sizf);
    return sizf;
}

int scanInt(){
    int begin;
    scanf("%d",&begin);
    return begin;
}
//##################1D Array#############################

one_D_Array init_one_D_Array() {
    one_D_Array array;
    array.array = malloc(sizeof(int));
    array.lastIndx = 0;
    return array;
    
}

one_D_Array addToArray(one_D_Array array, int toAdd) {
    //    int *newAr;
    //    newAr.array = (int *)malloc(array.lastIndx * sizeof(int))
    array.array = realloc(array.array, sizeof(int)*(array.lastIndx+1));
    array.array[array.lastIndx] = toAdd;
    array.lastIndx++;
    
    return array;
}

void print_Array(int *array, int lastInd) {
    for (int i = 0; i <=lastInd ; i++) {
        printf("%d",array[i]);
    }
}

//##################2D Array#############################

int **init_2d_Array(void) {
    int **newarr = (int **)malloc(sizeof(int *));
    return newarr;
}

void print_2d_Array(int **array, int len, int lastInd) {
    for (int range = 0; range <= lastInd; range++) {
        for (int r2 = 0; r2 < len; r2++) {
            printVal(array[range][r2]);
        }
    }
}

int **addArrayToArray(int **array, int *toAdd, int oldcount){//This should add a 1d array to a 2d array
    
    if (array == NULL ) {printf("Array must be initialized"); exit(1);}
    else array = realloc(array, sizeof(int*)*(oldcount+1));
    array[oldcount] = toAdd;
    return array;
}
//##################2D STRUCT ARRAY####################
//I think that if a Macro was used, it would allow for universal arrays, but lets keep it simple for now. 
one_D_Array* init_Struct_Array_1D(){
    one_D_Array *new = malloc(sizeof(one_D_Array ));
    return new;
}

two_D_Array init_2D_Struct(void){
    two_D_Array new;
    new.lastIndx = 0;
    new.count = 0;
    new.array = init_Struct_Array_1D();
    return new;
}

void add_To_2D_Struct(one_D_Array toAdd, two_D_Array addedTo) {

    addedTo.array = realloc(addedTo.array, sizeof(one_D_Array *)*(addedTo.count+1));
    addedTo.array[addedTo.lastIndx] = toAdd;
    addedTo.count++;
    addedTo.lastIndx = addedTo.count-1;
    print_Array(addedTo.array[0].array,addedTo.array[0].lastIndx);

}
void print_2D_Struct(two_D_Array toPrint, int untilIndx){
    for (int i = 0; i < untilIndx; i++) {
        print_Array(((one_D_Array) toPrint.array[i]).array,((one_D_Array) toPrint.array[i]).lastIndx);
    }

}