#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int fourthPower(int num)
{
    return num * num * num * num;
}

int fourleafCloverNum(int num)
{
    assert(num >= 1000 && num <= 9999);
    
    int thousands = num / 1000;
    int hundreds = (num / 100) % 10;
    int tens = (num / 10) % 10;
    int units = num % 10;

    return (fourthPower(thousands)) + (fourthPower(hundreds)) + (fourthPower(tens)) + (fourthPower(units));
}

float fractionToDecimal(int numerator, int denominator)
{
    assert(numerator > 0);
    assert(100000 > denominator && denominator > 0);

    return (float)numerator / (float)denominator;
}

float algebraProblem()
{
    int a, b, c, d;
    char x;
    
    printf("Please enter the equation in the form of ax + b = cx + d: ");

    scanf("%dx + %d = %dx + %d", &a, &b, &c, &d);
    
    if (a == c)
    {
        if (b == d)
        {
            printf("Infinite solutions (all real numbers are solutions)\n");
        }
        else
        {
            printf("No solution (contradiction)\n");
        }
    }

    float result = (float)(d - b) / (a - c);
    return result;
}

void nlanterns(int n)
{
    assert(n > 0);

    for (int i = 1; i * i <= n; i++)//needs to be平方数because only square numbers has a odd number of divisors
    {
        printf("%d\n", i*i);
    }
}

int main()
{   
    /*    float x = algebraProblem();
    printf("The solution is x = %.2f\n", x);*/

    int sumOfFourLeafClover = fourleafCloverNum(1634);
    printf("The sum of the four-leaf clover number is: %d\n", sumOfFourLeafClover);

	return 0;
}
