/* Exercise08
   This example code reads in an arbitrary number of command line
   arguments and prints them to the console */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    int eurekaFlag = 0;

    printf ("Number of arguments (argc)\t= %d\n", argc);
    
    // note that the 0th argument is always the program name!
    for (i = 0; i < argc; i++){
        printf ("argv[%i]\t= %s\n", i, argv[i]);
        // use strcmp from the string.h library to check 
        // if the argument string matches -e
        if (strcmp(argv[i], "-e") == 0) {
			eurekaFlag = 1;
		}
    }

    // if the flag is set, print Eureka
    if (eurekaFlag) {
        printf("Eureka!\n");
    	fprintf(stdout, "Eureka!\n");  // fprintf to stdout stream is same as printf!
    }
    return 0;
}