#include <stdio.h>

int main(int argc, char *argv[])
{

char letters[4];		/* delcare arrays of size 4 */
char numbers[4];		


letters[0] = 'K';		/* an array of chars, each assigned a char */
letters[1] = 'T';
letters[2] = 'H';
letters[3] = '\0';

// print the letters
printf("1. %c%c%c%c\n", letters[0], letters[1], letters[2], letters[3]);

// an easier way to print them as a string
printf("2. %s\n", letters);

/* remember, chars are just small int types */
numbers[0] = 75;		/* an array of char numbers */
numbers[1] = 84;
numbers[2] = 72;
numbers[3] = 0;

printf("3. %s\n", letters);

// we can also do math on the char array
printf("4. %c%c%c%c\n", letters[0]+32, letters[1]+32, letters[2]+32, letters[3]);

// we can delare the whole array at once using a string literal
char strarray[] = "KTH";
printf("5. %s\n", strarray);

// the easiest way is to declare a pointer to a char array and provide the string literal
char *strptr = "KTH";
printf("6. %s\n", strptr);

return 0;
}