/* Given an array and an array size, determine the lowest number higher than 0 
 * than does not appear in the array 
 */
#include <stdio.h>

int test( int arr[], int sz )
{
    __uint8_t swap = 0;
    __uint8_t result = 0;
    __uint8_t tmp = 0;

    // sort
    do {
        swap = 0;
        for ( __uint8_t i = 0; i < sz-1; i++ ) {
            if ( arr[i] > arr[i+1] ) {
                // Swap by using extra mem (stack) space
                // tmp = arr[i + 1];
                // arr[i + 1] = arr[i];
                // arr[i] = tmp;
                // Swap using one liner bitwise operation
                arr[i + 1] ^= arr[i] ^= arr[i + 1] ^= arr[i];
                swap = 1;
            }
        }
    } while( swap );

    // find gap
    for ( __uint8_t i = 0; i < sz-1; i++ ) {
        if( (arr[i+1] - arr[i]) > 1 ) {
            result = arr[i] + 1;
            break;
        }
        else {
            result = arr[i+1] + 1;
        }
    }

    // early exit
    if (( result <= 0 ) || 
        ( arr[0] >= 2 )) {
        result = 1;
    }

    return result;
}

int main()
{
    int res;
    int testset1[10] = {0,0,0,1,2,4,5,6,7,8};
    res = test(testset1,10);
    printf("result %d\n", res);
    return 0;
}
