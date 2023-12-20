#include <stdio.h>

int main()
{
	// Both printf and putc displays characters to the screen, how are they different?
	// printf - prints multiple characters
	//			has string formatter functionality (value to ascii, ascii to value, decimal places, etc)
	//			null character terminated
	// putc		prints one character
	//			no string formatter
	printf("Hello World!\n");
	putc(65, stdout);
	printf("\n");
	putchar(65);
	printf("\n");
	printf("ASCII value of 'A' is %d\n", 'A');
	printf("ASCII character of 65 is %c\n", 65);
	printf("%c%c%c%c%c\n", 104, 101, 108, 108, 111);

	int a = 23, b = 32;
	printf("Int promoted to float %.2f\n", (a + b)/2.33);
	printf("Same but in 4 decimal places %.4f\n", (a + b)/2.33);
	printf("Int %u\n", (a + b)/2);
	printf("Same but in hex 0x%X\n", (a + b)/2);
	return 0;
}
