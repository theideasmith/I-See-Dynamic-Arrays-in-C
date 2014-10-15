
#include "mutable_arrays.h"

//##################### Main ############################
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
    // for (int i =0; i < count; i++) {
    //     printf("\n<<%d:",i);
    //     print_Array(tu_D[i], 9);
    //     PRINT_STR(" of Size:");
    //     countOfArray(tu_D[i]);
    //     PRINT_STR(">>\n");
    // }
    two_D_Array addedTo= init_2D_Struct();
    one_D_Array toAdd = init_one_D_Array();
    addToArray(toAdd,4);

    add_To_2D_Struct(toAdd,addedTo);

    print_2D_Struct(addedTo,1);
    PRINT_STR("\n");

    return 0;
    //LOOP B
}
