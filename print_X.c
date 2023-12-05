// Write a C program to print out an X shape of size and width n
// eg.
//
// X X   X X   X   X  X       X
//  X    XX     X X     X    X
// X X    XX     X       X   X
// n=3   X X    X X       X X
//       n=4   X   X       X
//               n=5       X X
//                        X   X
//                       X     X
//                      X       X
//                         n=9
//

#include <stdio.h>


void print_x(int n)
{
    int i = n;
    int j;
    while (i > 0) {
        j = n;
        while (j > 0) {
            if ((j == i) || j == ((n - i) + 1)) {
                printf("x");
            } else {
                printf(" ");
            }
            j--;
        }
        printf("\n");
        i--;
    }

}
 
int main()
{
 print_x(3);
 printf("\n");
 print_x(4);
 printf("\n");
 print_x(5);
 printf("\n");
 print_x(9);
 printf("\n");
 return 0;
}