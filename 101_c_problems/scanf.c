#include <stdio.h>

int main()
{
	int i;
	printf("Input a number: ");
	scanf("%d", &i);
	printf("%d\n", i);

	// To resolve the error presented in *, introduce a fflush(stdin) before the second scanf
	// fflush(stdin); // joke lang, didn't work

	// To resolve the error presented in *, add "\n" in the first scanf
	// scanf("%d\n", &i); // didn't work as expected. waited for the letter input without printing the instruction

	// To resolve the error presented in *, add a space before the string formatter in the first scanf
	// scanf(" %d\n", &i); // didn't work 

	// To resolve the error presented in *, add a space before the string formatter in the second scanf
	// scanf(" %c\n", &a);

	char a;
	printf("Input a letter: ");
	// scanf("%c", &a); // *At this code flow, this instance of scanf is getting the Enter key from the first input processing.
	scanf(" %c", &a); // the fix, put a leading space before the string formatter. why does this work?
					  // Answer from StackOverflow: Whitespace in the scanf format string matches "any amount of whitespace, including none, in the input"
	printf("%c\n", a);

	return 0;
}