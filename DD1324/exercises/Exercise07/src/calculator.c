#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "operations.h"
#include "display.h"


double result = 0.0;  // a global variable defined in "operations.h" we use to store the result


int main(int argc, char *argv[])
{
	float opa, opb;
	char operator;

	if (argc !=  4) {
		log_err("Expected 3 arguments (eg. ./calculator 4 + 5)");
	}

	// convert arguments 1 and 3 into float operators
	opa = atof(argv[1]);
	opb = atof(argv[3]);
	// get the operator as a char (argument 2)
	operator = *argv[2];

	// call a different function according to the operator
	switch (operator)
	{
		case '+':
			addition(opa,opb);
			break;
		case '-':
			subtraction(opa,opb);
			break;
		case '/':
			division(opa, opb);
			break;
		case 'x':
			multiplication(opa, opb);
			break;
		default:
			// if operator is not an expected character, make an error and exit
			log_err("Expected a mathematical operator for 2nd argument!");
			exit(1);
	}

	// print the result
	displayresult(opa, opb, operator);


	return 0;
}