#include <stdio.h>

void print2darray(int (*A)[3]);

int main(int argc, char * argv[])
{


	int A[2][3] = {
		{0,1,2},  // initialize row A[0]
		{3,4,5}   // initialize row A[1]
	};

	/* create a pointer to a 1-D array of 3 integers */
	int (*p)[3] = A;

	/* these are all equivelant ways of printing the address
	   of the beginning of the array */
	printf("&A[0][0] = %p\n", &A[0][0]);  	// the standard way
	printf("A        = %p\n", A);			// base address of A 	
	printf("&A[0]    = %p\n", &A[0]);		// the address of the 1st array
//	printf("**A       = %p\n", *(*A)); 			// dereference the pointer A which points to 1st row
	printf("*A       = %p\n", *A); 			// dereference the pointer A which points to 1st row
	printf("A[0]     = %p\n", A[0]);		// base address of 1st array
//	printf("A[0][0]     = %p\n", A[0][0]);		// base address of 1st array
	printf("p        = %p\n", p); 			// The pointer	
	printf("\n");

	/* these  are all equivelant ways of printing the address
	   of the beginning of the 2nd array 1-D array of 3 integers, 
	   or 12 bytes after the base address of the array */
	printf("&A[1][0] = %p\n", &A[1][0]);  	// the standard way
	printf("A+1      = %p\n", A+1);			// base address of A with pointer arithmetic
	printf("&A[1]    = %p\n", &A[1]);		// address of 2nd array
	printf("*(A+1)   = %p\n", *(A+1)); 		// derefernce the pointer *(A+1) which points to the 2nd array
	printf("A[1]     = %p\n", A[1]);		// base address of the 2nd array
	printf("p[1]     = %p\n", p[1]); 		// pointer with array indexing
	printf("\n");

	/* These are all equivelant ways of printing the address of the
	   [1][2] element of A (2nd row, 3rd column) */
	printf("&A[1][2] = %p\n", &A[1][2]);
	printf("*(A+1)+2 = %p\n", *(A+1)+2);
	printf("A[1]+2   = %p\n", A[1]+2);
	printf("p[1]+2   = %p\n", p[1]+2);
	printf("\n");

	/* These are all equivelant ways of printing the value of the
	   [0][1] element of A (1st row, 2nd column) */
	printf("A[0][1]  = %d\n", A[0][1]);  	// the standard way
	printf("*(*A+1)  = %d\n", *(*A+1));		// *A = A[0], *(A[0]+1) = A[0][1]
	printf("\n");

	/* Call a function to print the array */
	print2darray(A);


	return 0;

}


/* A function to print a 2-dimensional array of integers.
   Note the type of the argument. We pass the return type of
   A, in this case a pointer to an array of 3 elements, 
   (*A)[3]. Alternatively, we can write  A[][3] or A[2][3] */
void print2darray(int (*A)[3])
{

	int i,j;

	/* For a 2-dimensional array
	   A[i][j] = *(A[i] + j);
		       = *(*(A + i) + j);
	*/


/* print the whole array using A[i][j]*/
	printf("A using A[i][j]\n");
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

/* print the whole array using *(A[i] + j)*/
	printf("\nA using *(A[i] + j)\n");
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++)
		{
			printf("%d ", *(A[i] + j));
		}
		printf("\n");
	}

/* print the whole array using *(*(A + i) + j) */
	printf("\nA using *(*(A + i) + j)\n");
	for (i=0; i<2; i++) {
		for (j=0; j<3; j++)
		{
			printf("%d ", *(*(A + i) + j));
		}
		printf("\n");
	}
}
