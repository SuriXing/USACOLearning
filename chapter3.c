#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

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

    int lcm = findLcmOfTwoInt(12, 18);
    printf("%d\n", lcm);

    int sumOfSquare = sumOfSquares_seven(21);
    printf("Result: %d\n", sumOfSquare);
    
    int arr[] = {5, 2, 9, 1, 5, 6};
    bubbleSort(arr, 6);
    
    int numberInStr = countNotSpaceChars("ABCD123 674");//10
    printf("%d\n", numberInStr);
    
    printLeftToRightTriangle(6);
    
    printMultiplicationTable_81();

    printCenteredPascalTriangle(7);

    printRectangleOfAstrics(3,5);

    printScalableStar(5);

    fourleafCloverNum(1634);

    findTreasure(5, 6);

    fenceProblem();
    
    printLeftToRightTriangle(6);
    return 0;
    */
    nlanterns(6);
}