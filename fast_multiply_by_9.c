int main(void)
{
	int a = 9, b = 0;
	b =  (a << 3) + a; // as compared to a * 9
	return 0;
}

// I tested this on godbolt and it generated exactly the same assembly code
// So perhaps this is no longer true in most modern compilers?