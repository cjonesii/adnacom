#include <stdio.h>

int main(int argc, char *argv[])
{
    int num = 0;
    printf("Pre: %d\n", ++num);
    num = 0;
    printf("Post: %d\n", num++);
    num = 0;
    // printf("Pre&Post: %d\n", ++num++); // invalid. cannot increment an rvalue.
    // printf("%d\n", 5++);
    return 0;
}