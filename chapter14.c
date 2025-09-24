#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int waysToGetUpTheStairWithTwoOrThreeRecursive(int num)
{
    assert(num > 0);
    if (num == 2) 
    {
        return 1;
    }
    else if (num == 3)
    { 
        return 1;
    }

    return waysToGetUpTheStairWithTwoOrThreeRecursive(num - 2) + waysToGetUpTheStairWithTwoOrThreeRecursive(num - 3);
}

int waysToGetUpTheStairWithTwoOrThree(int num)
{
    assert(num > 0);
    if (num == 2) 
    {
        return 1;
    }
    else if (num == 3)
    { 
        return 1;
    }

    int array[num];
    array[0] = 0;
    array[1] = 0;
    array[2] = 1;
    array[3] = 1;
    for (int i = 4; i <= num; i++)
    {
        array[i] = array[i-2] + array[i-3];
    }

    return array[num - 1];
}

int waysToGetUpTheStairWithOneOrTwoRecursive(int num)
{
    assert(num > 0);
    if (num == 1) 
    {
        return 1;
    }
    else if (num == 2)
    { 
        return 2;
    }

    return waysToGetUpTheStairWithOneOrTwoRecursive(num - 1) + waysToGetUpTheStairWithOneOrTwoRecursive(num - 2);
}

int waysToGetUpTheStairWithOneOrTwo(int num)
{
    assert(num > 0);
    if (num == 1) 
    {
        return 1;
    }
    else if (num == 2)
    { 
        return 2;
    }

    int array[num];
    array[0] = 1;
    array[1] = 2;
    for (int i = 2; i <= num; i++)
    {
        array[i] = array[i-1] + array[i-2];
    }

    return array[num - 1];
}

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

   for (int i = 1; i <= 10; i++)
   {
        printf("%d\t", waysToGetUpTheStairWithOneOrTwo(i));
   }

   printf("\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\t", waysToGetUpTheStairWithOneOrTwoRecursive(i));
    }
   
   printf("\n");

    return 0;
}