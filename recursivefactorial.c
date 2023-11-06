#include <stdlib.h>
#include <stdio.h>

int factorial(int num)
{
	int f = 0;
	if (num == 1)
		return 1;
	f = num * factorial(num - 1);
	return f;
}

int main(int argc, char *argv[])
{
	int fact = 0;
	if (argc < 2)
		exit(-1);
	int num = atoi(argv[1]);
	fact = factorial(num);
	printf("%d! = %d\n", num, fact);
	return 0;
}