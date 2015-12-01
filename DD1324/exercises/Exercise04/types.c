#include <stdio.h>			// provides printf()
#include <limits.h>			// provides INT_MAX, INT_MIN, UINT_MAX, SHRT_MAX,...
#include <float.h>    		// provides FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX

int main()
{
	printf("The ranges and memory consumption for data types on my computer\n");

	// chars are guaranteed to be 1 byte
	char y_char = 'y'; // Char literals are quoted with '' (ASCII code for y is 121)
	char max_c = CHAR_MAX;
	char min_c = CHAR_MIN;
	unsigned char max_uc = UCHAR_MAX;
	printf("char           %c=%d (%lu bytes)\n", y_char, (int) y_char, sizeof(y_char));
	printf("char           [%c %c]\n", min_c, max_c);
	printf("unsigned char  [%c %c]\n\n", 0, max_uc);

	// shorts are usually 2 bytes
	short an_s = 121;
	short max_s = SHRT_MAX;
	short min_s = SHRT_MIN;
	unsigned short max_us = USHRT_MAX;
	printf("short          %hi (%lu bytes)\n", an_s, sizeof(an_s));
	printf("short          [%hi %hi]\n", min_s, max_s);
	printf("unsigned short [%hu %hu]\n\n", 0, max_us);

	// ints are usually 4 bytes
	int an_i = 121;
	int max_i = INT_MAX;
	int min_i = INT_MIN;
	unsigned int max_ui = UINT_MAX;
	printf("int            %d (%lu bytes)\n", an_i, sizeof(an_i));
	printf("int            [%d %d]\n", min_i, max_i);
	printf("unsigned int   [%u %u]\n\n", 0, max_ui);

	// longs are often 4 to 8 bytes; 
	long an_l = 121;
	long max_l = LONG_MAX;
	long min_l = LONG_MIN;
	unsigned long max_lu = ULONG_MAX;
	printf("a long         %li (%lu bytes)\n", an_l, sizeof(max_l));
	printf("long           [%li %li]\n", min_l, max_l);
	printf("unsigned long  [%lu %lu]\n\n", (unsigned long) 0, max_lu);


	// floats are usually 32-bit floating point numbers
	float an_f = 121.0f;        // 'f' suffix here denotes floating point literal
	float max_f = FLT_MAX;
	float min_f = FLT_MIN;
	printf("float          %f (%lu bytes)\n", an_f, sizeof(max_f));
	printf("float          [%f %f]\n\n", min_f, max_f);

	// doubles are usually 64-bit floating-point numbers
	double an_d = 121.0;        // real numbers without any suffix are doubles
	double max_d = DBL_MAX;
	double min_d = DBL_MIN;
	printf("double         %f (%lu bytes)\n", an_d, sizeof(max_d));
	printf("double         [%f %f]\n\n", min_d, max_d);

	return 0;
}