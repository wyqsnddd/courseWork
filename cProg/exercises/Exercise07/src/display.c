#include <stdio.h>
#include "operations.h"
#include "dbg.h"

void displayresult(double a, double b, char operator)
{
	printf("Peforming the requested arithmetic:\n");
	printf("  %f\n", a);
	printf("%c %f\n", operator, b);
	printf("-----------------------------\n");
	printf("  %f\n", result);
}


