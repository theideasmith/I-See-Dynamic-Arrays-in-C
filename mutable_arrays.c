#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <objc/objc.h>
#include <mutable_arrays.h>

#define Empty ((void *)0)
#define totalCharlieplexed(outs) ((outs * outs) - outs)

typedef struct {
    int **array;
    int count;
}mutableArray;

typedef struct {
    int lastIndx;
    int *array;

}one_D_Array;

//##################Helper Functions#############################
void print_Array(int *array, int lastIndx) {
    for (int i = 0; i < lastIndx; i++) {
        printf("%d",array[i]);
    }
//    printf("\n");
}

void printVal(int val) {
    printf("%d\n", val);
}

int countOfArray(int *ar){
    int sizf = sizeof(ar) / sizeof(int) + 1;
    printVal(sizf);
    return sizf;
}

int scanInt(){
    int begin;
    scanf("%d",&begin);
    return begin;
}

//################## 1D #############################
one_D_Array init_one_D_Array() {
    one_D_Array array;
    array.array = (int *)malloc(sizeof(int *));
    array.lastIndx = 0;
    return array;
    
}

one_D_Array addToArray(one_D_Array array, int toAdd) {
//    int *newAr;
//    newAr.array = (int *)malloc(array.lastIndx * sizeof(int))
    
    array.array[array.lastIndx] = (int)malloc(sizeof(int));
    array.array[array.lastIndx] = toAdd;
    
    array.lastIndx++;
    print_Array(array.array, array.lastIndx);
    return array;
}

//######################## 2D #######################
int **init_2d_Array(void) {
    int **newarr = (int **)malloc(sizeof(int *));
    return newarr;
}

int **addArrayToArray(int **array, int *toAdd, int oldcount){//This should add a 1d array to a 2d array
    
    if (array == NULL ) array = (int**)malloc(sizeof(int *));
    else array[oldcount] = malloc(sizeof(int *));
    
    array[oldcount] = toAdd;
    
    return array;
}

void print2dArray(int **array, int count) {
    if (array != NULL) {
        for (int i = 0; i < count; i++) {
            print_Array(array[i], i);
        }
    }

}
//#################### MAIN ############################
void testarr(int totalItems){
    int count = 0;
    int **tu_D = init_2d_Array();
    for (int x = 0; x < totalItems;x++) {
        one_D_Array ar2 = init_one_D_Array();
        for (int i = 0; i < 10; i ++) {
            addToArray(ar2, i);
        }
        tu_D = addArrayToArray(tu_D, ar2.array, ar2.lastIndx);
        count ++;
        print_Array(tu_D[count -1], ar2.lastIndx);
        if (count % 2 == 0 ) printf("\n");
    }
    

}

int main(int argc, char *argv[]) {
    int argNum = atoi(argv[1]);
    int num = argNum > 0 ? argNum : 10;
    testarr(num);
}

