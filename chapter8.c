#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>


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
	return 0;
}
