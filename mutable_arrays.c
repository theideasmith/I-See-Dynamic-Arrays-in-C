
#include "mutable_arrays.h"

//##################### Main ############################
int main()
{
    PRINT_STR("Please enter a number");
    int ttlLoops = scanInt(); //Total Number of loops run
    int count = 0; //How many times the loop has run in total
    //LOOP A
  one_D_Array ar2 = init_one_D_Array(); //Initializing a one_D_Array
        
        for (int i = 1; i < ttlLoops; i++) {
            ar2 = addToArray(ar2, i); //Adding to the one dimensional array an int
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
/*    two_D_Array addedTo= init_2D_Struct();
    one_D_Array toAdd = init_one_D_Array();
    addToArray(toAdd,4);

    add_To_2D_Struct(toAdd,addedTo);

    print_2D_Struct(addedTo,1);
    PRINT_STR("\n");*/
    permute(ar2.array,ttlLoops);
    return 0;
    //LOOP B
}
