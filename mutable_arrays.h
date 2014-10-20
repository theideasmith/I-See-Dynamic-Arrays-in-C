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
int factorial(int i){
    int current_TTL = i;
    for (int x = i-1; x > 0; x--) {
        current_TTL*=x;
    }
    return current_TTL;
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

int *swap(int *array, int ind1, int ind2) //Swaps the location of two arrays
{
    int v1 = array[ind1];
    int v2 = array[ind2]; 
    array[ind2] = v1;
    array[ind1] = v2; 

    return array;
}
void permute(int *toPermute, int elementCount) {
    int ttLoops = factorial(elementCount);
    printVal(ttLoops); PRINT_STR("\n");
    int currentLoop = 0;
    int currentIndx = elementCount-1;
    while (currentLoop<ttLoops){
        toPermute = swap(toPermute, currentIndx, elementCount-1);
        print_Array(toPermute,elementCount-1);
        PRINT_STR("\n");
        currentLoop++;
        currentIndx = currentIndx == 0 ? elementCount -1:currentIndx-1;
    }
    /*---(OUTPUT)----
    Not as I expected. The process used does get the string back to its original form, 
    but it does not produce every permutation. I think I'll need to implement the shift every
    time the counter produces the set of outputs for a single first digit. 
    - As you will notice, the functions correctly permutes an array of length 3, but not four. 
Digits:  3  |  4
        123 | 1234 
        132 | 1234
        213 | 1342
        231 | 1342
        312 | 2314
        321 | 2314
            | 2341
              2341
              2413
              2413
              3124
              3124
              3412
              3412
              3421
              3421
              4123
              4123
              4132
              4132
              4231
              4231
    --------------*/
}
