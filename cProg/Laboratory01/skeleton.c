#include <stdio.h>
#define SIZE 3000 		/* Max file or string size */
/* Add other libraries or headers here (dbg.h, etc) */

int main(int argc, char *argv[])
{
	// declare your local variables
	FILE *FilePtr;	 	/* A pointer to an input file.
						   Use it with fopen() to open
						   and read a file */
	long length;		/* You can find the length of 
						   a file using ftell, fseek,
						   SEEK_END, SEEK_SET */
	char input[SIZE];	/* put the input string or 
	                       text file contents in here
	                       and then translate it */


	/* Handle the options in argv. If a text file is
	   given, read it and store it in input. If a string
	   is given, store it in input */

	/* Generate a lookup table to translate the text. It
	   is probably good to write the functions in another
	   file and call them here.*/   

	/* Perform the actual translation of the text. It
	   is probably good to write the functions in another
	   file and call them here. */


	/* Display the output as requested. It is probably 
	   good to write the functions in another file and 
	   call them here. */

	return 0;
}