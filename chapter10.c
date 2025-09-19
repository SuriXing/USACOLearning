#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int binaryFindNumberOfXInReachableDescendingArray(int* array, int length, int x)
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
            int sum = 1;    // mid is 1
            int temp = mid-1;
            while ((temp >= 0) && array[temp] == x)
            {
                sum += 1;
            }

            temp = mid+1;
            while ((temp <= length-1) && array[temp] == x)
            {
                sum += 1;
            }

            return sum;
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

    return 0;
}

int binaryFindNumberOfXInReachableAscendingArray(int* array, int length, int x)
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
            int sum = 1;    // mid is 1
            int temp = mid-1;
            while ((temp >= 0) && array[temp] == x)
            {
                sum += 1;
            }

            temp = mid+1;
            while ((temp <= length-1) && array[temp] == x)
            {
                sum += 1;
            }

            return sum;
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

    return 0;
}

int binaryFindFirstXInDescendingReachableArray(int* array, int length, int x)
{
    assert(array != NULL);
    assert(length > 0);

    int startIndex = 0;
    int endIndex = length;

    while (endIndex > startIndex)
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

int binaryFindFirstXInAscendingArray(int* array, int length, int x) // array has to be ascending
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

int binaryFindfirstXInReachableDescendingArray(int* array, int length, int x)
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
            for (int i = mid -1; i > 0; i--)
            {
                if (array[mid - 1] == x)
                {
                    return mid -1;
                }
            }
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

int binaryFindfirstXInReachableAscendingArray(int* array, int length, int x)
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
            for (int i = mid -1; i > 0; i--)
            {
                if (array[mid - 1] == x)
                {
                    return mid -1;
                }
            }
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

int binaryFindXDescendingReachable(int* array, int length, int x)
{
    assert(array != NULL);
    assert(length > 0);

    int startIndex = 0;
    int endIndex = length;

    while (endIndex > startIndex)
    {
        int mid = (startIndex + endIndex)/2;

        if (mid == x)
        {
            return mid;
        }
        else if (array[mid] < x)
        {
            endIndex = mid - 1;
        }
        else
        {
            startIndex = mid;
        }
    }

    return -1;
}

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

void runTestAscendingArray(int* array, int length, int x, const char* description)
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

void runTestDescendingArray(int* array, int length, int x, const char* description)
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
    printf("Now are Ascending arrays:\n\n");//AscendingNow:

    int arr1[] = {2, 4, 6, 8, 10};
    runTestAscendingArray(arr1, 5, 6, "Ascending array, target exists");

    int arr2[] = {1, 3, 5, 7, 9};
    runTestAscendingArray(arr2, 5, 4, "Ascending array, target missing");

    int arr3[] = {5, 2, 9, 1, 7};
    runTestAscendingArray(arr3, 5, 9, "Unsorted array, target exists");

    int arr4[] = {10, 20, 30, 40, 50};
    runTestAscendingArray(arr4, 5, 10, "Target at left boundary");

    int arr5[] = {0, 5, 10, 15, 20};
    runTestAscendingArray(arr5, 5, 20, "Target at right boundary");

    int arr6[] = {1, 2, 3, 4, 6};
    runTestAscendingArray(arr6, 5, 2, "Duplicate elements");

    printf("Now To Descending arrays:\n\n");//DescendingNow:

    int arr7[] = {13, 12, 8, 3, 5, 2};
    runTestDescendingArray(arr7, 6, 5, "Descending array, target exsits");

    int arr8[] = {25, 24, 12, 5, 3, 1};
    runTestDescendingArray(arr8, 6, 2, "Descending array, target does not exists");

    int arr9[] = {12, 11, 8, 6, 3, 2};
    runTestDescendingArray(arr9, 6, 2, "Descending array, target exists");

    int arr10[] = {46, 23, 12, 11, 8, 6};
    runTestDescendingArray(arr10, 6, 6, "Descending array, target exists");
    
    int arr11[] = {666, 88, 66, 8, 6, 2};
    runTestDescendingArray(arr11, 6, 8, "Descending array, target exists");

    int arr12[] = {888, 666, 88, 66, 8, 6};
    runTestDescendingArray(arr12, 6, 4, "Descending array, target does not exists");

    //Now to duplicate

    int arr13[] = {1, 2, 2, 2, 2, 2, 6};
    int result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);

    int arr14[] = {888, 666, 88, 66, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);

    int arr15[] = {888, 666, 88, 66, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);

    int arr16[] = {888, 666, 88, 66, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);

    int arr17[] = {888, 666, 88, 66, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);
    
    int arr18[] = {888, 666, 88, 66, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);
    
    int arr19[] = {8888, 6666, 868, 686, 8, 6};
    result = binaryFindfirstXInReachableAscendingArray(arr13, 7, 2);
    printf("%d\n", result);

    return 0;
}