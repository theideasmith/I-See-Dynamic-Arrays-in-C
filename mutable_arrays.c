#include <stdio.h>
#include <stdlib.h>

#define PRINT_STR(str) {\
printf("%s", str);\
}

typedef struct {
    int lastIndx;
    int *array;
    
}one_D_Array;

//##################Helper Functions#############################

int sizeint = 1;
void print_Array(int *array, int lastInd) {
    for (int i = 0; i <=lastInd ; i++) {
        printf("%d",array[i]);
    }
}


void printVal(int val) {
    printf("%d", val);
}

int countOfArray(int *ar){
    int sizf = sizeof(ar) / sizeof(int);
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
    // 2222222222
}

//##################2D Array#############################

int **init_2d_Array(void) {
    int **newarr = (int **)malloc(sizeof(int *));
    return newarr;
}

void print2dArray(int **array, int len, int lastInd) {
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

int main()
{
    PRINT_STR("Please enter a number");
    int ttlLoops = scanInt(); //Total Number of loops run
    int count = 0; //How many times the loop has run in total
    int **tu_D = init_2d_Array();
    //LOOP A
    for (int x = 0; x < ttlLoops;x++) {
        one_D_Array ar2 = init_one_D_Array(); //Initializing a one_D_Array
        
        for (int i = 0; i < 10; i++) {
            ar2 = addToArray(ar2, i); //Adding to the one dimensional array an int
        }
        tu_D = addArrayToArray(tu_D, ar2.array, count); //Adding the one dimensional array to a 2d array
        printf("\n<<%d:",count);
        print_Array(tu_D[count], 9); //Printing the 1D array just saved above into the 2D array
        PRINT_STR(">>\n");
        count ++;
        
        
    }
    //LOOP A
    //LOOP B
    for (int i =0; i < count; i++) {
        printf("\n<<%d:",i);
        print_Array(tu_D[i], 9);
        PRINT_STR(" of Size:");
        countOfArray(tu_D[i]);
        PRINT_STR(">>\n");
    }
    return 0;
    //LOOP B
}
