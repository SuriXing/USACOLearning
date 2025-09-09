#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

#define CHESS_ROW 5
#define CHESS_COLUMN 5
#define MIN(x,y) (x < y ? x : y)

int isASeven(int chess[][CHESS_COLUMN], int i, int j, int x)
{
    for (int k=j; k<j+x; k++)
    {
        if (k >= CHESS_COLUMN) // over
        {
            return 0;
        }

        if (chess[i][k] == 0)
        {
            return 0;
        }
    }

    for (int n=i+1; n<i+x+1; n++)
    {
        if (n >= CHESS_ROW)
        {
            return 0;
        }

        if (chess[n][j+x-1] == 0)
        {
            return 0;
        }
    }

    return 1;
}

void chessMakeSeven()
{
    int chess[CHESS_ROW][CHESS_COLUMN] = {0};
    chess[0][0] = chess[0][1] = chess[0][2] = chess[0][3] = chess[0][4] = 1;
    chess[1][0] = chess[1][1] = chess[1][2] = chess[1][3] = chess[1][4] = 1;
    chess[2][0] = chess[2][1] = chess[2][2] = chess[2][3] = chess[2][4] = 1;
    chess[3][0] = chess[3][1] = chess[3][2] = chess[3][3] = chess[3][4] = 1;
    chess[4][0] = chess[4][1] = chess[4][2] = chess[4][3] = chess[4][4] = 1;

    int count = 0;

    for (int i = 0; i < CHESS_ROW; i++)
    {
        for (int j = 0; j < CHESS_COLUMN; j++)
        {
            for (int x = 2; x <= MIN(CHESS_COLUMN - j, CHESS_ROW - i - 1); x++)
            {
                count += isASeven(chess, i, j, x);
            }
        }

    }

    printf("%d\n", count);
}

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
    printf("The solution is x = %.2f\n", x);

    int sumOfFourLeafClover = fourleafCloverNum(1634);
    printf("The sum of the four-leaf clover number is: %d\n", sumOfFourLeafClover);
    */

    chessMakeSeven();

	return 0;
}
