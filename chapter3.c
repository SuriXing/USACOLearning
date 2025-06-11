#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    if (a>b)
    {
        return a;
    }
    else if (a == b)
    {
        return a;
    }
    else
    {
        return b;
    }
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

int selfcheck_PlusOrMinus()
{
    int a, b, c;
    printf("Enter two integers that are separated by a comma & enter 0 if you want to find their sum and 1 if you want to find their difference: \n");
    scanf("%d, %d, %d", &a, &b, &c);
    if (c == 0)
    {
        printf("The sum of %d and %d is: %d\n", a, b, a + b);
    }
    else if (c == 1)
    {
        printf("The difference of %d and %d is: %d\n", a, b, a - b);
    }
    else
    {
        printf("Invalid input for operation. Please enter 0 for sum or 1 for difference.\n");
    }
    return 0;
}

int sumOf2int()
{
    int a, b;
    printf("Enter two integers in the form of integer a, integer b: \n");
    scanf("%d, %d", &a, &b);

    return a+b;
}

int sumOf2int_stepversion()
{
    int a, b;
    printf("Enter two integers in the form of integer a, integer b: \n");
    scanf("%d, %d", &a, &b);

    int sum = a + b;

    printf("You entered: %d and %d\n", a, b);
    printf("Calculating the sum... %d\n", sum);

    return a + b;
}

int main()
{

    int array[5] = {12, 33, 12, 41, 1};

    int grades[10] = {37, 90, 100, 90, 40 , 25, 18, 59, 1, 10};

    /*
    int resultForSum = sumOf2int();
    printf("The sum of the two integers is: %d\n", result);

    int stepResult = sumOf2int_stepversion();
    printf("The sum of the two integers in step version is: %d\n", stepResult);

    int selfcheckResult = selfcheck_PlusOrMinus();

    bool result = determineLeapYear(2020);
    if (result == 1)
    {
        printf("2020 is a leap year.\n");
    }
    else
    {
        printf("2020 is not a leap year.\n");
    }

    int triangleResult = determineTriangle(3, 4, 12);
    printf("The triangle side length is %s\n", triangleResult ? "valid" : "not valid");

    twoIntegersCalculation();
    
    returnCommentToGrades();

    printAstrics(7);

    printArray(array, 5);

    makeArraySmallToBig(array, 5);

    printArray(array, 5);

    abcd();

    int sum = evenNumSum(4);
    printf("%d\n", sum);

    int gcd = gcdOfTwoNum(17, 25);
    printf("The gcd of 17 & 25 is %d\n", gcd);

    int count = howManyLowerThanAverage(grades);
    printf("%d\n", count);
    
    returnSquare(5);
    */

    int lcm = findLcmOfTwoInt(12, 18);
    printf("%d\n", lcm);

    return 0;
}