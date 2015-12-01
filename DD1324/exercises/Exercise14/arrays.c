#include <stdio.h>

int sumOfArray(int A[], int size)
{
	/* When arrays are used as function arguments, they are
	   always call by reference (not call by value). This means
	   the array has not been copied into sumOfArray, instead
	   a pointer has been created. The better way to write the
	   declaration is:
	   int sumOfArray(int* A, int size)
	*/
	int i, sum = 0;
	
	/* Because A is a pointer to the array A in main, the size
	   we calculate here will be the size of a pointer, not the
	   size of the 5-element array */
	int localsize = sizeof(A)/sizeof(A[0]);
	printf("Size of A = %d (in sumOfArray)\n", localsize);

	/* because the syntax for pointers and arrays are so similar
	   we cannot tell here if A is a pointer or an array */
	for (i=0; i<size; i++)
	{
		sum = sum + A[i];
	}
	return sum;
}


int main(int argc, char * argv[])
{

	int i;

	/* create an integer array and assign initial values */
	int A[5] = {9,0,2,1,0};
	
	/* create a pointer to an integer */
	int *p;
	
	/* in C, writing the identifier of an array (A) gives its
	   base address, we can use this to assign a pointer */
	p = A;
	printf("\nbase address\n A = %p\n", A);
	printf("Pointer to A\n p = %p\n", p);

	/* in C, you can dereference an array identifier similar to
	   the way you dereference a pointer */
	printf("\nEquivelent ways to dereference an array\n");
	printf("A[0] = %d\n", A[0]);
	printf("*A   = %d\n", *A);
	printf("*p   = %d\n\n", *p); 

	/* To access a value or address of an element of an array,
	   we can use the following equivelent statements:
	   Address:  &A[i]  or  (A + i)   or   (p + i)
	   Value:    A[i]   or  *(A+i)    or  *(p + i)   */
	for(i = 0; i < 5; i ++)
	{
		printf("i = %d\n", i);
		printf("&A[%d]=%p, (A+%d)=%p, (p+%d)=%p\n", i,&A[i],i,(A+i),i,(p+i));
		printf("A[%d]=%d, *(A+%d)=%d, *(p+%d)=%d, p[%d]=%d\n\n", i,A[i],i,*(A+i),i,*(p+i),i,p[i]);
	}

	/* use sizeof to computer the number of elements in A and print it */
	int size = sizeof(A)/sizeof(A[0]);
	printf("Size of A = %d (in main)\n", size);

	/* call the function sumOfArray which sums the elements of the array */
	sumOfArray(A, size);

	return 0;

}