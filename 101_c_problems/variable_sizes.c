#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
	int i = 0;
	char a = 1;
	int *j = &i;
	short sh = 0;
	long lo = 0;
	double dou = 0;
	float fl = 0;

	printf("size of int %ld bytes\n", sizeof(i));
	printf("size of char %ld bytes\n", sizeof(a));
	printf("size of pointer to int %ld bytes\n", sizeof(j));
	printf("size of short %ld bytes\n", sizeof(sh));
	printf("size of long %ld bytes\n", sizeof(lo));
	printf("size of double %ld bytes\n", sizeof(dou));
	printf("size of float %ld bytes\n", sizeof(fl));

	struct padding1 {
		char a_mem;	// since second member is 4bytes, the compiler aligned the first member allocation to 4 bytes too
		int i_mem;
	};
	struct padding1 struct_a;
	printf("size of 'struct a' %ld bytes\n", sizeof(struct_a));

	struct padding2 {
		char a2_mem; // members are of same size, so struct size is only 2 char sizes
		char a3_mem;
	};
	struct padding2 struct_b;
	printf("size of 'struct b' %ld bytes\n", sizeof(struct_b));

	struct bit_assigned { // Common technique in translating Status and Control Register bits into structure
		int i1 : 1; // LSB
		int i2 : 2;
		int i3 : 1;
		int i4 : 8;
		int i5 : 4; // MSB
	};
	struct bit_assigned struct_c; // although 5 integers are declared, the total size of the struct is still one int size
	printf("size of 'struct c' %ld bytes\n", sizeof(struct_c));

	union union_sample { // Common technique in converting the structure to one int value
		struct bit_assigned ba;
		int inta;
	};

	union union_sample ua;
	ua.inta = 0; // initialize the biggest union member to init the union
	ua.ba.i1 = 1;
	printf("value of 'union_sample' when i1(LSB) is changed 0x%x\n", ua.inta);
	ua.inta = 0;
	ua.ba.i5 = 1;
	printf("value of 'union_sample' when i5(MSB) is changed 0x%x\n", ua.inta);
}