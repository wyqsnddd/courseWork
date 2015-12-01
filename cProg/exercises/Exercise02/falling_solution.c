/* falling.c
   DD1324 KTH */
#include <stdio.h> 				/* preproceeing directives */
#include <stdlib.h>
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

		speed = fallOneSec(speed); 				/* call the function for updating the fall */
		printf("Current height (%ds): %fm\n", t, height);   /* print current height */
		t++;									/* increment time by 1 s */
	}
	hitTheGround();								/* call the function for hitting the ground */
	printf("Program should never get here!");
	return 0;
}

/* definition of fallOneSec */
float fallOneSec(float speed)
{
	height = height - speed;		/* update the height after 1 s */
	speed = speed + GRAVITY;		/* update the speed after 1 s */

	if(speed > TERMINAL_VELOCITY) { /* limit the speed */

		speed = TERMINAL_VELOCITY;
	}

	/* if we don't check this, it is possible to have negative height */
	if (height < 0.0) {

		hitTheGround();
	}
	return speed;
}

/* definition of hitTheGround */
void hitTheGround(void)
{
	printf("Splat!\n");				/* print "splat" and exit the program */
	exit(0);
}