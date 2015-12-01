#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{

	/* allocate 100 bytes of memory */
	char *x = malloc(100);


	/* allocate an array with 10 bytes and
	   access out-of-bounds */
	char *y = malloc(10);
	y[11] = 'a';

	/* attempt to do operations on an uninitialized
	   variable z */
	int z;
	if (z == 0)
	{
		printf("z is zero\n");
	}

	/* valgrind will not do bounds checking
	   on static arrays (allocated on the stack) */
	char a[10];
	a[11] = 'a';

	return 0;
}