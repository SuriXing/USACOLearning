#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    /*
    int result = sumOf2int();
    printf("The sum of the two integers is: %d\n", result);
    */

    int stepResult = sumOf2int_stepversion();
    printf("The sum of the two integers in step version is: %d\n", stepResult);

    return 0;
}