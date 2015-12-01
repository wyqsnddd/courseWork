#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	// declare a file pointer f
	FILE *f;

	/* initialize a file stream, "w" means we can write
	   to file.txt. The file pointer should point to a
	   file given as a command line argument (in argv) */	
	f= fopen(argv[1], "w");

	// check if we have successfully opened the file
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);		// stdlib contains exit
	}

	/* print some text to the file */
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);

	/* print integers and floats to the file */
	int i = 1;
	float pi = 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, pi);

	/* printing single chatacters to the file */
	char c = 'A';
	fprintf(f, "A character: %c\n", c);

	// close the file stream when we are finished
	fclose(f);

	return 0;
}