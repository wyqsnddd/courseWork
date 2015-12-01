#include <stdio.h>

int main(int argc, char * argv[])
{

	/* create an integer and a pointer to the integer */
	int a = 1025;
	int *p;
	p = &a;

	/* display the memory size of the integer, the address
	   of the p, and the value pointed at by p */
	printf("The size of an integer is %lu bytes\n", sizeof(a));
	printf("p  address   = %p, value = %d\n", p, *p);

	/* create a char* pointer, point it to the address of
	   a using typecasting */
	char *p0;
	p0 = (char*) p;

	/* display the memory size of the char, the address of p0,
	   and the value pointed at by p0 */
	printf("The size of a char is %lu bytes\n", sizeof(char));
	printf("p0 address   = %p, value = %d\n", p0, *p0);

	/* the memory contains
	   00000000 00000000 00000100 00000001
	   therefore *p0 = 1 because it points at the last
	   byte and only the last byte */

	/* Now we will perform some pointer arithmetic. Here
	   we have moved the address ahead by 4 bytes (the size
	   of one int) and the value at that address is whatever
	   garbage was in the memory previously */
	printf("p  address+1 = %p, value = %d\n", p+1, *(p+1));	  

	/* Adding 1 to p0 only increments us by 1 byte, so the value
	   is now 4. */
	printf("p0 address+1 = %p, value = %d\n", p0+1, *(p0+1));

	return 0;

}
