#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

void printArray(int* array, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d,", array[i]);
    }
    printf("\n\n");
}

void selectSortAscending(int* array, int length)
{
    int temp = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectSortDescending(int * array, int length)
{
    int temp = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (array[j] < array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

/*
int bubbleSortAscending(int* array, int length)
{
    int temp = 0;

    for (int i = 0; i < length; i++)
    {
        for ()
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
            }
        }
    }
}
*/

/*
You have a sorted list of N distinct integers (1 ≤ N ≤ 100,000).
Your task is to answer Q queries where each query asks: 
"Find the number in the list that is closest to X. If there are two numbers equally close, choose the smaller one."
*/

int findClosestNumInArrayToXless(int* array, int n, int x)
{
    assert(NULL != array);
    assert(n >= 0);

    int closestValue = abs(array[0] - x);
    int closestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (closestValue > abs(array[i] - x))
        {
            closestIndex = i;
        }
    }

    return array[closestIndex];
}

int findClosestNumInArrayToXGreater(int* array, int n, int x)
{
    assert(NULL != array);
    assert(n >= 0);

    int closestValue = abs(array[0] - x);
    int closestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (closestValue < abs(array[i] - x))
        {
            closestIndex = i;
        }
    }

    return array[closestIndex];
}

int findClosestNumInArrayToX2(int* array, int n, int x)
{
    assert(NULL != array);
    assert(n >= 0);
    int closestValue = abs(array[0] - x);
    int closestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (closestValue > abs(array[i] - x))
        {
            closestIndex = i;
        }
    }

    return array[closestIndex];
}

/*
int findClosestNumInArrayToXBinary(int* array, int n, int x)
{

}
*/

/*
You have a sorted list of N integers (1 ≤ N ≤ 1,000). Your task is to answer Q queries where each query asks: "How many numbers in the list are less than or equal to X?"
*/

int numLessThanOrEqualToX(int n, int* array, int x)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] <= x)
        {
            num ++;
        }
    }

    return num;
}

int numGreaterOrEqualToX(int n, int* array, int x)
{
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] >= x)
        {
            num ++;
        }
    }

    return num;
}

int waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(int num)
{
    assert(num > 0);

    const int numOrder[4] = {0, 1, 1, 2};

    if (num <= 4)
    {
        return numOrder[num - 1];
    }

    return waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 2) + waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 3) + waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 4);
}

int waysToGetUpTheStairWithTwoOrThreeOrFourRecursivePractice(int num)
{
    assert(num > 0);

    const int numOrder[4] = {0, 1, 1, 2};

    if (num <= 4)
    {
        return numOrder[num - 1];
    }

    return waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 2) + waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 3) + waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(num - 4);
}

int waysToGetUpTheStairWithOneOrTwoOrThreeRecursiveSmart(int num)
{
    assert(num > 0);

    const int numOrder[3] = {1, 1, 2};

    if (num <= 3)
    {
        return numOrder[num - 1];
    }

    return waysToGetUpTheStairWithOneOrTwoOrThreeRecursiveSmart(num - 1) + waysToGetUpTheStairWithOneOrTwoOrThreeRecursiveSmart(num - 2) + waysToGetUpTheStairWithOneOrTwoOrThreeRecursiveSmart(num - 3);
}

int waysToGetUpTheStairWithOneOrTwoOrThreeRecursive(int num)
{
    assert(num > 0);
    if (num ==1)
    {
        return 1;
    }
    else if (num == 2) 
    {
        return 1;
    }
    else if (num == 3)
    { 
        return 2;
    }

    return waysToGetUpTheStairWithOneOrTwoOrThreeRecursive(num -1) + waysToGetUpTheStairWithOneOrTwoOrThreeRecursive(num -2) + waysToGetUpTheStairWithOneOrTwoOrThreeRecursive(num -3);
}

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
    int result = 0;
    int array1[5] = {1, 124, 35, 13, 24};
    int array2[6] = {6, 8, 3, 5, 2, 5};
    int array3[8] = {1, 56, 3, 3, 74, 2, 66, 88};

    for (int i=1; i<=10; i++)
    {
        printf("%d\t", findFibonacci(i));
    }
    printf("\n\n");

    for (int i=1; i<=10; i++)
    {
        printf("%d\t", recursiveFindFibonacci(i));
    }
    printf("\n\n");

   for (int i = 1; i <= 10; i++)
   {
        printf("%d\t", waysToGetUpTheStairWithOneOrTwo(i));
   }

   printf("\n\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\t", waysToGetUpTheStairWithOneOrTwoRecursive(i));
    }
   
   printf("\n\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\t", waysToGetUpTheStairWithOneOrTwoOrThreeRecursive(i));
    }
    
    printf("\n\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\t", waysToGetUpTheStairWithTwoOrThreeOrFourRecursive(i));
    }
    
    printf("\n\n");

    result = numLessThanOrEqualToX(5, array1, 25);//3
    printf("%d\n", result);

    result = numGreaterOrEqualToX(5, array1, 25);//2
    printf("%d\n", result);

    result = findClosestNumInArrayToXless(array1, 5, 6); //1
    printf("%d\n", result);

    result = findClosestNumInArrayToXless(array1, 5, 24); //24
    printf("%d\n", result);

    //sortings:
    printArray(array1, 5);
    selectSortAscending(array1, 5);
    printArray(array1, 5);

    printArray(array1, 5);
    selectSortDescending(array1, 5);
    printArray(array1, 5);

    return 0;
}