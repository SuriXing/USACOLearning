#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

void abcd()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int h = 0; h < 10; h++)
                {
                    if ((((10*i + j) * (10*k + h)) == 1000*i + 100*j + 10*k + h))
                    {
                        printf("%d\n", (1000*i + 100*j + 10*k +h));
                    }
                }
            }
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("\n");
}

void makeArraySmallToBig(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int averageOfArray(int array[], int n)
{
    int sum;

    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }

    return sum/n;
}

void printAstrics(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
}

int changeValue(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

void returnCommentToGrades()
{
    char grade;
    printf("Enter your grade (A, B, C, D, F): \n");
    scanf(" %c", &grade);
    switch (grade) {
        case 'A':
            printf("Excellent work!\n");
            break;
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("You passed.\n");
            break;
        case 'D':
            printf("You need to improve.\n");
            break;
        case 'F':
            printf("You failed. Please try again.\n");
            break;
        default:
            printf("Invalid grade entered.\n");
    }
}

void twoIntegersCalculation() {
    char operation;
    int a, b;
    
    printf("Enter two integers and the operation you want at the end\n");
    scanf("%d %d %c", &a, &b, &operation);

    if (operation == '+') {
        printf("The sum of %d and %d is: %d\n", a, b, a + b);
    }
    else if (operation == '-') {
        printf("The difference of %d and %d is: %d\n", a, b, a - b);
    }
    else if (operation == '*') {
        printf("The product of %d and %d is: %d\n", a, b, a * b);
    }
    else if (operation == '/') {
        if (b != 0) {
            printf("The division of %d by %d is: %.2f\n", a, b, (double)a / b);
        }
        else {
            printf("Division by zero is not allowed.\n");
        }
    }
    else {
        printf("Invalid operation. Please use +, -, *, or /.\n");   
    }
}

bool determineTriangle(int a, int b, int c)
{
    if ((a+b > c) && (a+c > b) && (b+c > a))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool determineLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true; // It's a leap year
    }
    else
    {
        return false; // It's not a leap year
    }
}

int main()
{
	return 0;
}
