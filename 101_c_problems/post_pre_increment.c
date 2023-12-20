#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    printf("Pre: %d\n", ++num);
    num = 0;
    printf("Post: %d\n", num++);
    num = 0;
    // printf("Pre&Post: %d\n", ++num++); // invalid. cannot increment an rvalue.
    // printf("%d\n", 5++); // to explain line #10, the command is like this
    int i = 0, j = 0;
    j = i++ + ++i; // predict the output without running the code
    // i++ is post incremented, meaning value of i is assigned to an intermediate storage
    // then i's value is incremented
    // ++i pre incremented, meaning i's value is incremented then assigned
    // prior to this stage, i's value is already 1 because of the earlier operation
    // therefore i's value will become 2, and j's value will also be 2
    printf("%d, %d\n", i, j);
    return 0;
}