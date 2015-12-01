#include <stdio.h>

int main(int argc, char * argv[])
{

	int a;					/* declare an int */
	char c;					/* declare a char */
	int * p;				/* declare a pointer to integer */


	printf("p  = %p\n", p); /* print the address where the pointer points */
							/* hint: it is a null pointer because we 
							   have not pointed it at anything */

	p = &a;					/* assign the address of a to pointer p */
	printf("p  = %p\n", p); /* print the address where the pointer points */
	printf("&a = %p\n", &a);/* print the address of a */
	printf("a  = %d\n", *p);/* print the value of a */
							/* hint: it has not been initialized so it will
							   be whatever was previously occupying that
							   memory location */

	a = 5;					/* initialize a */
	printf("a  = %d\n", *p);/* print the value of a */
	a++;					/* increment a */	
	printf("a  = %d\n", *p);/* print the value of a */

	
	int b = 10;				/* initialize b */
	p = &b;					/* assign the address of b to pointer p */
	printf("b  = %d\n", *p);/* print the value of b */
	
	
	printf("p  = %p\n", p); /* print the address where p points */
	printf("&b = %p\n", &b);/* print the address of b */

	*p = 8; 				/* change the value of b by assigning a 
							   value to the memory where p is pointing */
	printf("b  = %d\n", *p);/* print the value of b */

	*p = a; 				/* copy a into the value of b */
	printf("b  = %d\n", *p); /* print the value of b */

	return 0;

}