#include <stdio.h>

int factorial(int n);

int main()
{
	int n, result;

	/* prompt the user to enter an integer */
	printf("Type an integer > 0:\n");
	scanf(" %d", &n);

	result = factorial(n);

	/* print the result, n! */
	printf("Result %d! = %d\n", n, result);

	return(0);
}

/* a bugged function to compute the factorial of an integer n */
int factorial(int n)
{
	int result;

	while(n > 0)
	{
		result *= n;
		n--;
	}

	return result;
}