#include <stdio.h>

int main(int argc, char * argv[])
{

	/* create an integer and a pointer to the integer */
	int x = 5;
	int *p;
	p = &x;

	int **q = &p;	/* a pointer to a pointer to an integer */
	int ***r = &q;  /* a pointer to a pointer to a pointer to an integer */

	/* print the dereferenced pointers and try to guess what each
	   output will be */
	printf("x    = %d\n", x);		// the value of x
	printf("x    = %p\n", p);		// the address of p
	printf("*p   = %d\n", *p);		// *p = the value of x
	printf("*q   = %p\n", *q);		// *q = the address of p
	printf("**q  = %d\n", **q); 	// **q = the value of x
	printf("**r  = %p\n", **r);		// **r = the address of p
	printf("***r = %d\n", ***r);	// ***r = the value of x

	/* you can change the value of x by deferencing the pointer to a 
	   pointer to a pointer to an integer */
	***r = 10;

	printf("x    = %d\n", x);		// the value of x is now 10

	return 0;

}