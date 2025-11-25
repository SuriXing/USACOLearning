#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ROW_LENGTH 5
#define COL_LENGTH 5

typedef struct _Array2D
{
    int items[ROW_LENGTH][COL_LENGTH];
    int numOfItems;
} Array2D;

bool array2DIsFull(Array2D* pArray);

bool array2DIsEmpty(Array2D* pArray);

bool array2DPrint(Array2D* pArray);

int array2DFindMax(Array2D* pArray);

int array2DFindMin(Array2D* pArray);

bool array2DIsFull(Array2D* pArray)
{
    assert(NULL != pArray);

    return (ROW_LENGTH * COL_LENGTH <= pArray->numOfItems);
}

bool array2DIsEmpty(Array2D* pArray)
{
    assert(NULL != pArray);

    return (pArray->numOfItems == 0);
}


bool array2DPrint(Array2D* pArray)
{
    assert(NULL != pArray);

    for (int i = 0; i < ROW_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            printf("%d\t", pArray->items[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return true;
}


int array2DFindMax(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < ROW_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (max < pArray->items[i][j])
            {
                max = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems % COL_LENGTH; i++)
    {
        if (max < pArray->items[pArray->numOfItems/COL_LENGTH][i])
        {
            max = pArray->items[pArray->numOfItems/COL_LENGTH][i];
        }
    }

    return max;
}

int array2DFindMin(Array2D* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0][0];

    for (int i = 0; i < ROW_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems%COL_LENGTH; i++)
    {
        if (min > pArray->items[pArray->numOfItems/COL_LENGTH][i])
        {
            min = pArray->items[pArray->numOfItems/COL_LENGTH][i];
        }
    }

    return min;
}

int main()
{
    Array2D testArray =
    {
        {
            { 1, 2, 5, 6, 8 }, 
            { 2, 4, 5, 6, 10 }
        },
        10
    };

    array2DPrint(&testArray);

    printf("array find max: %d\n", array2DFindMax(&testArray));
    printf("array find min: %d\n", array2DFindMin(&testArray));

    return 0;
}