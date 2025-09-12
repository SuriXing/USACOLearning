#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int binaryFindXDescending(int* array, int length, int x)
{
    assert(array != NULL);
    assert(length > 0);

    int startIndex = 0;
    int endIndex = length - 1;

    while (endIndex >= startIndex)
    {
        int mid = (startIndex + endIndex)/2;

        if (array[mid] == x)
        {
            return mid;
        }
        else if(array[mid] < x)
        {
            endIndex = mid - 1;
        }
        else
        {
            startIndex = mid + 1;
        }
    }

    return -1;
}

// 1, 3, 9, 13, 56, 256, 781, 1000
int binaryFindXAscending(int* array, int length, int x) // array has to be ascending
{
    assert(array != NULL);
    assert(length > 0);

    int startIndex = 0;
    int endIndex = length;

    while (startIndex < endIndex)
    {
        int mid = (startIndex + endIndex)/2;
    
        if (array[mid] == x)
        {
            return mid;
        }
        else if (array[mid] < x)
        {
            startIndex = mid + 1;
        }
        else
        {
            endIndex = mid;
        }
    }

    return -1;
}

int binaryFindXAscendingReachable(int* array, int length, int x)
{
    assert(array != NULL);
    assert(length > 0);

    int startIndex = 0;
    int endIndex = length-1;

    while (startIndex <= endIndex)
    {
        int mid = (startIndex + endIndex)/2;
        
        if (array[mid] == x)
        {
            return mid;
        }
        else if (array[mid] < x)
        {
            startIndex = mid + 1;
        }
        else 
        {
            endIndex = mid - 1;
        }
    }

    return -1;
}

int findX(int* array, int length, int x)
{
    assert(array != NULL);
    assert(length > 0);

    for (int i = 0; i < length; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
    }

    return -1;
}

void runTest(int* array, int length, int x, const char* description)
{
    printf("Test Case: %s\n", description);
    printf("Array: [");
    for (int i = 0; i < length; i++) {
        printf("%d%s", array[i], (i < length - 1) ? ", " : "");
    }
    printf("]\nTarget: %d\n", x);

    int resultBin = binaryFindXAscending(array, length, x);
    int resultLin = findX(array, length, x);

    printf("binaryFindXAscending: %d\n", resultBin);
    printf("findX:               %d\n", resultLin);
    printf("Result Match:        %s\n\n", (resultBin == resultLin) ? "✅" : "❌");
}

int main()
{
    int arr1[] = {2, 4, 6, 8, 10};
    runTest(arr1, 5, 6, "Ascending array, target exists");

    int arr2[] = {1, 3, 5, 7, 9};
    runTest(arr2, 5, 4, "Ascending array, target missing");

    int arr3[] = {5, 2, 9, 1, 7};
    runTest(arr3, 5, 9, "Unsorted array, target exists");

    int arr4[] = {10, 20, 30, 40, 50};
    runTest(arr4, 5, 10, "Target at left boundary");

    int arr5[] = {0, 5, 10, 15, 20};
    runTest(arr5, 5, 20, "Target at right boundary");

    int arr6[] = {1, 2, 2, 2, 3};
    runTest(arr6, 5, 2, "Duplicate elements");

    return 0;
}