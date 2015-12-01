#include <stdio.h>
#include <stdlib.h>

void display(int* a, int size);
void fillarray(int* a, int size);

int main(int argc, char * argv[])
{
	/* these variables go on the stack */
	int *p, *q; 
	int n;

	/* prompt the user for the size of an int array
	   to create, and store the value in n */
	printf("Type size of array: ");
	scanf("%d", &n);

	/* use malloc to allocate memory sized to fit the
	   requested array n * 4 bytes (sizeof(int)). malloc
	   returns a void pointer, so we typecast the pointer
	   to obtain an integer pointer (int*) */
	p = (int*)malloc(n*sizeof(int));

	/* this function displays contents of the array */
	display(p, n);

	/* this function fills the array with monotonically
	   increasing values */
	fillarray(p, n);
	display(p, n);

	/* use calloc to allocate memory sized to fit the
	   requested array. calloc makes sure the entire array
	   is ititialized to zero. It has a slightly differnt
	   syntax to malloc. */
	q = (int*)calloc(n,sizeof(int));
	display(q, n);

	/* use realloc to resize the memory allocated for q. In
	   this example we reduce the size of the array by 2. */
	q = (int*)realloc(q,(n-2)*sizeof(int));
	fillarray(q, n-2);
	display(q, n-2);

	/* release the memory we requested from the operating
	   system */
	free(p);
	free(q);
	return 0;
}

/* a function to display the elements of a 1-D integer array */
void display(int* a, int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

/* a function to fill the 1-D integer array with monotonically
   increasing integers */
void fillarray(int* a, int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		a[i] = i+1;
	}
}