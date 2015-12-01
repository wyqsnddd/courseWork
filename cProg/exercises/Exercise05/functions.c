#include <stdio.h>
#include <string.h>

// function declarations
int increment(int x);
void swap(int *x, int *y);
void printIntArray(int *arr, int size);
void str_reverse(char *str_in);

int main()
{
	/* Functions are call by value. When a function is 
	   called, the arguments passed to the function are 
	   copies of the original arguments (except arrays). 
	   Anything you do to the arguments in the function does 
	   not change the value of the original argument where 
	   the function was called. */
	 int a = 10;
	 printf("a = %d (in main)\n", a);
	 /* we increment a, but this only applies to 
       the local scope of the function */
	 increment(a);
	 printf("a = %d (in main)\n", a);
	 /* this time we increment a, but we copy the return
	    value to a, updating it in the main function */ 
     a = increment(a);
	 printf("a = %d (in main)\n\n", a);


    /* To modify the original arguments, we can use call 
       by reference. This makes use of pointers. Here, we
       use a simple function to swap the values of two
       integers using pointers to their memory addresses */
	int zero, one;
	zero = 0;
	one = 1;
	swap(&zero, &one);  // &zero is the address of zero
	printf("zero = %d, one = %d\n\n", zero, one);

	/* Arrays are a special case. They will always be 
	   passed to functions as pointers, even if you 
	   statically allocate an array like `arr[10]`,
       it still gets passed as a pointer to the first 
       element. It is important to also pass the size
       of the array, otherwise the fucntion has no way 
       of knowing how big the array is. */
    int intList[] = {0, 1, 2, 3, 4};
    int size = 5;
    printIntArray(intList, size);

    /* The last example reverses a string using call
       by reference. */
    char str[] = "Reverse me!";
    str_reverse(str);
    printf("\n%s\n", str);


	return 0;
}



int increment(int a)
{
	a++;              // increment a in local scope
	printf("a = %d (in increment function)\n", a);
	return a;
}

void swap(int *x, int *y)   // int *x is a pointer to x
{
    int temp = *x;     // *x is the value at the address x points to
    *x = *y;           // *y is the value at the address y points to
    *y = temp;
}

// printIntArray needs the size to know how long to loop!
void printIntArray(int *arr, int size) 
{
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d] is: %d\n", i, arr[i]);
    }
}

// A void function returns no value
void str_reverse(char *str_in)
{
  char tmp;
  int ii = 0;
  size_t len = strlen(str_in); // `strlen()` is part of the c standard library string.h
  for (ii = 0; ii < len / 2; ii++) {
    tmp = str_in[ii];
    str_in[ii] = str_in[len - ii - 1]; // ii-th char from end
    str_in[len - ii - 1] = tmp;
  }
}