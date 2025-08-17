#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

void printStringAscendingRepeat(const char* str)
{
    assert(NULL != str);

    int arr[256] = {0};
    
    const char* pCur = str;

    while (*pCur != '\0')
    {
        arr[*pCur] += 1;

        pCur++;
    }

    printf("printStringAscending\n");
    printf("Original String: %s\n", str);
    printf("After Ascending sort:");

    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = 0; j < arr[i]; j++)
            {
                printf("%c", (char)i);
            }
        }
    }

    printf("\n");
}

void printStringAscending(const char* str)
{
    assert(NULL != str);

    int arr[256] = {0};
    
    const char* pCur = str;

    while (*pCur != '\0')
    {
        arr[*pCur] = 1;

        pCur++;
    }

    printf("printStringAscending\n");
    printf("Original String: %s\n", str);
    printf("After Ascending sort:");

    for(int i = 0; i < 256; i++)
    {
        if (arr[i] == 1)
        {
            printf("%c", (char)i);
        }
    }

    printf("\n");
}

void printStringDescending(const char* str)
{
    assert(NULL != str);

    int arr[256] = {0};
    
    const char* pCur = str;

    while (*pCur != '\0')
    {
        arr[*pCur] = 1;

        pCur++;
    }

    printf("printStringDescending\n");
    printf("Original String: %s\n", str);
    printf("After Descending sort:");

    for(int i = 256; i > 0; i--)
    {
        if (arr[i] == 1)
        {
            printf("%c", (char)i);
        }
    }

    printf("\n");
}

float sumOfFraction(int n)
{
    float count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += 1.0/i;
    }
    return count;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int findSmallestNum(int* array, int start, int end)
{
    int smallestNum = start;
    for (int i = start + 1; i < end; i++)
    {
        if (array[i] < array[smallestNum])
        {
            smallestNum = i;
        }
    }
    return smallestNum;
}

void selectArrange(int* array, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int smallestNum = findSmallestNum(array, i, rows);
        
        // Swap the found smallest element with the first element of the unsorted part
        int temp = array[i];
        array[i] = array[smallestNum];
        array[smallestNum] = temp;
    }
}

void printRectangleOfAstrics(int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printRhombusOfAstrics(int side)
{
    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void printSquareOfAstrics(int side)
{
    for (int i = 1; i <= side; i++)
    {
        for (int j = 1; j <= side; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

#define MINMULTIPLIER 1
#define MAXMULTIPLIER 9
void printMultiplicationTable__81()
{
    for (int i = MINMULTIPLIER; i <= MAXMULTIPLIER; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%d * %d=%-2d  ", j, i, i * j);
        }
        printf("\n");
    }
}

void printCenteredPascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        int count = rows - i;
        while(count > 0)
        {
            printf(" ");
            count --;
        }
        printf("\n");
    }
}

void printPascalTriangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        printf("\n");
    }
}

void printPascalTriangle_easierversion(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", number);
            number = (number * (i - j)) / (j + 1);
        }
        printf("\n");
    }
}

void printDiagnolTriangle(int rows)
{
    int current = 1;
    int diagnol = 1;
    
    for (int i = 0; i < rows; i++)
    {
        int num = current;
        int step = diagnol;
        
        for (int j = 0; j < rows - i; j++)
        {
            printf("%d ", num);
            num += step;
            step++;
        }
        
        printf("\n");
        current += diagnol;
        diagnol++;
    }
}

/*
Problem:
The Merry Milk Makers company has N (1 ≤ N ≤ 5000) farmers, each with a certain amount of milk to sell at a certain price. The company wants to buy at least M (1 ≤ M ≤ 2,000,000) units of milk, spending the least amount of money possible.

Given:

N farmers, each with a price per unit (in cents) and maximum amount they can sell
M = total units needed

Output:
The minimum cost to buy at least M units of milk
*/

typedef struct {
    int price;
    int amount;
} Farmer;

int compareFarmers(const void *a, const void *b)
{
    return ((Farmer*)a)->price - ((Farmer*)b)->price;
}

int mixMilk(int N, int M, Farmer farmers[])
{
    qsort(farmers, N, sizeof(Farmer), compareFarmers);
    int cost = 0, remaining = M;
    
    for (int i = 0; i < N && remaining > 0; i++) {
        int take = remaining < farmers[i].amount ? remaining : farmers[i].amount;
        cost += take * farmers[i].price;
        remaining -= take;
    }
    
    return cost;
}

// problem solved//

void simpleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printCenteredReversedTriangle(int rows) 
{
    int start_num = (rows * (rows + 1)) / 2;
    int num = start_num;
    
    for (int i = 1; i <= rows; i++)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            printf("  ");
        }
        
        for (int j = 1; j <= i; j++)
        {
            printf("%-2d ", num--);
        }
        printf("\n");
    }
}

int returnGreaterNum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int abvalue(int num)
{
    return (num > 0) ? num : (-num);
}

int strLength(const char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int countNotSpaceChars(const char* str)
{
    int count = 0;
    while (*str != '\0')
    {
        if ((*str != ' ') && (*str != '\n') && (*str != '\r')) 
        {
            count++;
        }
        str++;
    }
    return count;
}

int main()
{
    // test for printStringDescending
    printStringDescending("kjhgtfrertyujhgv");
    printStringDescending("opqrstuvwxyz");
    printStringDescending("pkhgvdrh");
    
    // test for printStringAscending
    printStringAscending("qwerty");
    printStringAscending("fghjujuhygtfr");
    printStringAscending("nmlkjihgfedcba");

    return 0;
}
