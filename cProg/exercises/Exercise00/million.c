#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
	int i;
	int a = 0;
	int b = 0;
	int c = 0;

	for (i = 0; i < 1000000; i++){
		a = rand();
		b = rand();
		c = a + b;
	}
	printf("Added 1,000,000 random integers using C\n");
	return 0;
}