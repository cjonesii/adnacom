// Check input if power of 2

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool is_power_of_two(int n)
{
	if ((n > 0) && ((n & (n - 1)) == 0))
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	printf("%d is %s\n", n, is_power_of_two(n) ? "a power of two" : "not a power of two");
}