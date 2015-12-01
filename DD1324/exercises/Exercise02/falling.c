/* falling.c
   DD1324 KTH */
#include <stdio.h> 				/* preproceeing directives */
// A library needed to call exit() is missing
#define GRAVITY 9.8 			/* accelration due to gravity (m/s^2) */				
#define TERMINAL_VELOCITY 56    /* human free fall velocity (m/s) */

float height; 					/* declare a global variable to store the altitute */
								/* NOTE: using global variables are BAD PRACTICE. */
								/* This is just an example, don't use globals! */
float fallOneSec(float speed);  /* function prototypes */
void hitTheGround(void);

int main(void) 					/* the main function */
{
	float speed = 0.0f;  		/* local variables for speed */
	int t = 0;					/* local variable for time */

	printf("Type height to fall from (m): ");  	/* prompt the user */
	scanf("%f", &height); 						/* get keyboard input, asssing to height */

	while (height > 0.0) {						/* keep looping until we hit the ground */

		// insert your code here
	}

	// insert your code here
	return 0;
}

/* definition of fallOneSec */
float fallOneSec(float speed)	/* the function for updating the fall */
{
	// insert your code here
	return speed;
}

/* definition of hitTheGround */
void hitTheGround(void)			/* call the function for hitting the ground */
{
	// insert your code here
	exit(0);
}