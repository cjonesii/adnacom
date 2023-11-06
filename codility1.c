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
    do{
        swap = 0;
        for( __uint8_t i = 0; i < sz-1; i++ )
        {
            if( arr[i] > arr[i+1] ) 
            {
                tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
                swap = 1;
            }
        }
    } while( swap );

    // find gap
    for( __uint8_t i = 0; i < sz-1; i++ )
    {
        if( (arr[i+1] - arr[i]) > 1 )
        {
            result = arr[i] + 1;
            break;
        }
        else
        {
            result = arr[i+1] + 1;
        }
    }

    // early exit
    if( result <= 0 )
    {
        result = 1;
    }

    return result;
}

int main()
{
    int res;
    int testset1[3] = {0,2,0};
    res = test(testset1,3);
    printf("result %d\n", res);
    return 0;
}

1
2
3
4
5
6
7
8
9
10
11
	
def solution(A):
    seen = [False] * len(A)
    for value in A:
        if 0 < value <= len(A):
            seen[value-1] = True
 
    for idx in xrange(len(seen)):
        if seen[idx] == False:
            return idx + 1
 
    return len(A)+1

  function solution(a) {
  const length = a.length; // N
  const map = Array(length).fill(false); // create array, fill with false
  for (let i = 0; i < length; i++) {
    const item = a[i];
    if (item < 1 || item > length) {
      continue;
    }
    map[item - 1] = true; // wouldn't this go beyond scope? No because of the condition before this line
  }
  for (let i = 0; i < length; i++) {
    if (!map[i]) {
      return i + 1;
    }
  }
  return length + 1;
}

assert.strictEqual(solution([2, 4, 5]), 1);