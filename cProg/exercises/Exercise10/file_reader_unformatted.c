#include <stdio.h>
#include <stdlib.h>

int main()
{
	int length, line;
	char * buffer;		// porinter to store input stream
	size_t result;		// memory size of buffer
	char * file_name;	// pointer to file name
	char name[30];		// string to store th names
	float value;		// float to store the values
	FILE * fp1, * fp2;	// file pointers


	/* reading every character of a file without
	   any formatting */
	file_name = "constants.txt";
	fp1 = fopen(file_name,"r"); // read mode

	// check if we have successfully opened the file
	if( fp1 == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	printf("The contents of %s read\nline-by-line formatted:\n", file_name);
	
	/* read each line */
	line = 0;
	while (fscanf(fp1, "%s %f", name, &value) != EOF) {
		printf("%d: %s\t%f\n", line, name, value);
		line++;
	}

	// close the file pointer
	fclose(fp1);





	/* reading every character of a file without
	   any formatting */
	file_name = "constants.txt";
	fp2 = fopen(file_name,"r"); // read mode

	// check if we have successfully opened the file
	if( fp2 == NULL )
	{
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}

	/* move the file pointer to the end of file
		using constant SEEK_END, get the length
		using ftell, move the file pointer back to
		the beginning (SEEK_SET) and read the
		whole file */
	fseek(fp2, 0, SEEK_END);  		// move to file end
	length = ftell(fp2);			// get length of file
	fseek(fp2, 0, SEEK_SET);		// move back to beginning

	/* allocate memory to buffer of the necessary size,
	   read into buffer, and check that the correct size
	   was read */
	buffer = (char*) malloc(sizeof(char) * length);	// allocate memory
	result = fread(buffer, 1, length, fp2);			// read into buffer
	if (result != length) {							// check it is correct
		fputs("Reading error", stderr); 
		exit(3);
	}


	//print the unformatted file contents
	printf("\nContents of %s read\nas an unformatted string:\n", file_name);
	printf("%s", buffer);

	// free the memory you used for buffer
	free(buffer);

	// close the file pointer
	fclose(fp2);


	return 0;
}

// http://stackoverflow.com/questions/174531/easiest-way-to-get-files-contents-in-c?lq=1