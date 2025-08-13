#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int sumOfConsecutiveNum(int num)
{
    assert(num > 0);
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    return sum;
}

#define HWGRADE 5.0
#define EXAMGRADE (3.0/10)
#define TESTGRADE 2.0

int grade(int hwGrade, int examGrade, int testGrade)
{
    assert(hwGrade > 0);
    assert(examGrade > 0);
    assert(testGrade > 0);
    return (hwGrade/HWGRADE) + (examGrade* EXAMGRADE) + (testGrade/TESTGRADE);
}

int sumOfNumOnEdgeOfRectangle(int n, int m, int matrix[][m])
{
    assert(n > 0);
    assert(m > 0);
    assert(matrix != NULL);

    int sum = 0;

       for (int j = 0; j < m; j++)
    {
        sum += matrix[0][j];
        if (n > 1)
        {
            sum += matrix[n - 1][j];
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        sum += matrix[i][0];
        if (m > 1)
        {
            sum += matrix[i][m - 1];
        }
    }

    return sum;
}

void matrixAdd(int n, int m, int A[][m], int B[][m], int C[][m])
{
    assert(n > 0);
    assert(m > 0);
    assert(A != NULL);
    assert(B != NULL);
    assert(C != NULL);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void selectionSort(int arr[], int n)
{
    assert(n > 0);
    assert(arr != NULL);
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printCenteredNumberTriangle(int rows)
{
    assert(rows > 0);
    int current_num = 1;
    for (int i = 1; i <= rows; i++) 
    {
        int leading_spaces = (rows - i) * 2;
        for (int s = 0; s < leading_spaces; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("%-3d", current_num++);
        }
        printf("\n\n");
    }
}

void printCenteredNumberTriangle2(int rows)
{
    assert(rows > 0);
    int current_num = 1;
    for (int i = 1; i <= rows; i++) 
    {
        int leading_spaces = (rows - i) * 2;
        for (int s = 0; s < leading_spaces; s++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("%-3d", current_num++);
        }
        printf("\n\n");
    }
}

void printTriangle(int rows)
{
    assert(rows > 0);
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", num++);
        }
        printf("\n");
    }
}

void printReversedTriangle(int rows) 
{
    assert(rows > 0);
    int start_num = (rows * (rows + 1)) / 2;
    int num = start_num;
    
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", num--);
        }
        printf("\n");
    }
}

void printMultiplicationTable()
{
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%d * %d=%-2d  ", j, i, i * j);
        }
        printf("\n");
    }
}

int absoluteValue(int n)
{
    return (n < 0) ? -n : n;
}

bool containsSeven(int num)
{
    while (num > 0)
    {
        int digit = num % 10;
        if (digit == 7)
        {
            return true;
        }
        num /= 10;
    }
    return false;
}

int sumOfSquares_seven(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 7 != 0 && !containsSeven(i))
        {
            sum += i * i;
        }
    }
    return sum;
}

void returnSquare(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n-1)
            {
                printf("*\n");
            }
            else
            {
                printf("*");
            }
        }
    }
}

int howManyLowerThanAverage(int grades[10])
{
    assert(grades != NULL);
    int sum;
    int count;

    for (int i = 0; i <= 10; i++)
    {
        sum += grades[i];
    }

    for (int i = 0; i <= 10; i++)
    {
        if (grades[i] < sum/10)
        {
            count += 1;
        }
    }

    return count;
}

int gcdOfTwoNum(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findLcmOfTwoInt(int a, int b)
{
    if ((a <= 0) || (b <= 0))
    {
        return 0;
    }

    return (a * b)/gcdOfTwoNum(a, b);
}

int whichOneIsBigger(int a, int b)
{
    return (a >= b) ? a : b;
}

int evenNumSum(int n)
{
    int sum = 0;

    for (int i = 2; i <= n; i += 2)
    {
        sum += i;
    }

    return sum;
}

int main()
{
	return 0;
}
