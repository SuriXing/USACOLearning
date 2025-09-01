#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Finds 4-digit numbers where product of first two and last two digits equals the number
void findSpecialNumbers()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int firstPair = 10 * i + j;
            for (int k = 0; k < 10; k++)
            {
                for (int h = 0; h < 10; h++)
                {
                    int secondPair = 10 * k + h;
                    int number = 1000 * i + 100 * j + 10 * k + h;
                    if (firstPair * secondPair == number)
                    {
                        printf("%d\n", number);
                    }
                }
            }
        }
    }
}

// Prints array elements separated by commas
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d%s", array[i], (i < size - 1) ? ", " : "");
    }
    printf("\n");
}

// Sorts array in ascending order using bubble sort
void sortArray(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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

// Calculates average of array elements
float calculateAverage(int array[], int size)
{
    if (size <= 0) return 0.0f;
    
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return (float)sum / size;
}

// Prints n asterisks
void printAsterisks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");
}

// Swaps values of two integers
void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Provides feedback based on grade input
void evaluateGrade()
{
    char grade;
    printf("Enter your grade (A, B, C, D, F): ");
    scanf(" %c", &grade);
    
    switch (grade)
    {
        case 'A': case 'a': printf("Excellent work!\n"); break;
        case 'B': case 'b': printf("Good job!\n"); break;
        case 'C': case 'c': printf("You passed.\n"); break;
        case 'D': case 'd': printf("You need to improve.\n"); break;
        case 'F': case 'f': printf("You failed. Please try again.\n"); break;
        default: printf("Invalid grade entered.\n");
    }
}

// Performs basic arithmetic operations
void calculator()
{
    int a, b;
    char operation;
    
    printf("Enter two integers and an operation (+, -, *, /): ");
    if (scanf("%d %d %c", &a, &b, &operation) != 3)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (operation)
    {
        case '+': printf("%d + %d = %d\n", a, b, a + b); break;
        case '-': printf("%d - %d = %d\n", a, b, a - b); break;
        case '*': printf("%d * %d = %d\n", a, b, a * b); break;
        case '/': 
            if (b != 0) {
                printf("%d / %d = %.2f\n", a, b, (float)a / b);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default: printf("Invalid operation.\n");
    }
}

// Checks if three sides can form a triangle
bool isTriangleValid(int a, int b, int c)
{
    return (a > 0 && b > 0 && c > 0) && 
           (a + b > c) && 
           (a + c > b) && 
           (b + c > a);
}

// Checks if a year is a leap year
bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int main()
{
    // Test cases
    findSpecialNumbers();
    
    int numbers[] = {5, 2, 8, 1, 4};
    const int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    printArray(numbers, size);
    
    sortArray(numbers, size);
    printf("Sorted array: ");
    printArray(numbers, size);
    
    printf("Average: %.2f\n", calculateAverage(numbers, size));
    printAsterisks(5);
    
    evaluateGrade();
    calculator();
    
    printf("Can form triangle (3,4,5)? %s\n", 
           isTriangleValid(3, 4, 5) ? "Yes" : "No");
    printf("Is 2024 a leap year? %s\n", 
           isLeapYear(2024) ? "Yes" : "No");
    
    return 0;
}