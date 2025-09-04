#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

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
    float x = algebraProblem();
    printf("The solution is x = %.2f\n", x);

	return 0;
}
