#include <stdio.h>

void main()
{
	/* initialize a string literal */
	char *temp = "Paras";

	/* initialize a counting variable */
	int i;
	i=0;
	
	/*The array will be statically allocated; it is not const , but modifying it is undefined behaviour. If it had pointer type char * or incomplete type char [] , sizeof could not work as expected. Making string literals const is a C++ idiom and not part of any C standard.*/
	
    /* attempt to modify a string literal which causes the program to crash */
	temp[3]='F';

	/* print the contents of temp */
	for (i =0 ; i < 5 ; i++ )
	  printf("%c\n", temp[i]);
}
