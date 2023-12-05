/* missing integer
 * important note: ignore value bigger than N
 * actually this seems like a different version
 * of lowest_num_not_in_arr.c
 */
#include <stdio.h>

int solution( int A[], int N )
{
    int map[N]; // Space complexity O(2n).. bad!
    int item = 0;

    for( int i = 0; i < N; i++ )
    {
        map[i] = 0;
    }
    for( int i = 0; i < N; i++ )
    {
        item = A[i];
        if( item < 1 || item > N ) // ignore values less than 1 or greater than N
        {
            continue;
        }
        map[item - 1] = 1;
    }
    for( int i = 0; i < N; i++ )
    {
        if( !map[i] ) // the minimum int value that is not found in the array
        {
            return i + 1; // because this is an index
        }
    }
    return N + 1; // all values is in the array, minimum int is the next value
}

int main( void )
{
    int res = 0;
    int a[1] = {50};
    res = solution(a,1);
    printf("result %d\n", res);
}