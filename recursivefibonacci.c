#include <stdio.h>
#include <stdlib.h>

void print_t3(int num)
{
    static int t1 = 0;
    static int t2 = 1;
    static int t3 = 0;

    if (num > 0) {
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
        printf("%d ", t3);
        print_t3(num - 1);
    }
}

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    printf("Fibonacci sequence for %d elements:\n", num);
    printf("0 1 ");
    print_t3(num - 2);
    printf("\n");
    return 0;
}