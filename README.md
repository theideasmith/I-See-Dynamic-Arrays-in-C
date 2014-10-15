I-See-Dynamic-Arrays-in-C
=========================

Exactly as the name implies, this is code for dynamic arrays in C. 
Getting all the intricate pointers to work took a  while, until today, Oct 13 2014 when it finally worked. 

###TO USE 
####1D Arrays
Declare an `int *` or a `one_D_Array` and initialize the array using `one_D_Array init_one_D_Array()`. Then add `int`s to it with `one_D_Array addToArray(one_D_Array array, int toAdd)`

####2D Arrays
Declare an `two_D_Array`, use the `init_2D_Struct` function to initialize it, and use `add_To_2D_Struct()` to add `one_D_Arrays`'s to it. 

####Structs 
These were helpful in development. While not all of the two structs are supported, try playing around with them. 

###TODO LIST:

1. Remove from arrays
2. `free()` memory
3. Change the value stored at any index in the array. 
4. Support for arrays of the different structs
5. **A universal (any data type) and infinitely nestable dynamic array system**
I'd love for someone else to join me in making the best repo for dynamic && mutable arrays in C. 

**A big thanks to [R Sahu](http://stackoverflow.com/users/434551/r-sah) for helping me with this on [Stack Overflow](http://stackoverflow.com/questions/26373830/setting-and-using-variable-in-different-scopes-not-working-in-c?noredirect=1#comment41407131_26373830)**

####Interesting Things Possible in C: Which I Learned Through this Project

#####Functions in Structs

    void print_Console(const char *str) {
        printf("%s",str);
    }
    
    typedef struct {
      void (*consolePrint)(const char *str);
    }testStr;
    
    testStr str;
    str.consolePrint = print_Console
    str.consolePrint("Hello World");
        

    //OUTPUT: "Hello World”

####Code Blocks
  
    ...
    testStr str;
    
    //BLOCK
    str.consolePrint = ^(const char *str){
        printf("%s",str);
    };
    //END BLOCK
    
    ...
    //OUTPUT: "Hello World"



####Typedefs in Functions
    
    int main() {
        typedef struct {
            void (*consolePrint)(const char *str);
        }testStr;
    }


