#include <stdio.h>
#include <string.h>

void printX(void);

char x[] = "global scope";   		// this x has global scope (the whole file)

int main(void)
{ 
    char x[] = "outer scope"; 		// this local variable x has outer block scope (within main's { })
    printf("1. x = %s\n", x);	
    {								// an inner block has been set by { }
        printf("2. x = %s\n", x);	// because x has not been re-declared, the inner block also has outer scope

        char x[12];					// declare a new x 
		printf("3. x = %s\n", x); 	// the uniniatilized x has inner block scope
        strcpy(x, "inner scope");   // copy a string into inner block scope x
        printf("4. x = %s\n", x);   // print the inner block scope x
    }
    printf("5. x = %s\n", x); 		// we have left the inner bock, outer block has scope again
    printX();						// function call to printX

    return 0;
}

void printX(void)					// inside printX we have not defined x at all
{
	printf("6. x = %s\n", x);		// therefore the global scope gets printed

}