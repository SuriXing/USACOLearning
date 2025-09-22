#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

// 1, 1, 2, 3, 5, 8, 13, 21
int findFibonacci(int n)
{
    assert(n > 0);

    int array[n];
    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i < n; i++)
    {
        array[i] = array[i-1] + array[i-2];
    }

    return array[n-1];
}

int recursiveFindFibonacci(int n)
{
    assert(n > 0);
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return recursiveFindFibonacci(n-1) + recursiveFindFibonacci(n-2);
}

int main()
{
    for (int i=1; i<=10; i++)
    {
        printf("%d\t", findFibonacci(i));
    }
    printf("\n");

    for (int i=1; i<=10; i++)
    {
        printf("%d\t", recursiveFindFibonacci(i));
    }
    printf("\n");

    return 0;
}