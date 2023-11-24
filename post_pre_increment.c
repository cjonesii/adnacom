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
    return 0;
}