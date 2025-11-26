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


bool array2DInsertAt(Array2D* pArray, int rowAt, int colAt, int newElement);

bool array2DInsertAtBeginning(Array2D* pArray, int newElement);

bool array2DInsertAtEnd(Array2D* pArray, int newElement);

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


bool array2DInsertAt(Array2D* pArray, int rowAt, int colAt, int newElement)
{
    assert(NULL != pArray);
    assert(rowAt >= 0);
    assert(colAt >= 0);

    if (array2DIsFull(pArray))
    {
        return false;
    }

    if ((ROW_LENGTH * rowAt + colAt) > pArray->numOfItems)
    {
        return false;
    }

    int numOfElementsNeedMove = pArray->numOfItems - (COL_LENGTH * rowAt + colAt);

    int *pInsertAt = (int*)(&pArray->items[rowAt][colAt]);
    while (numOfElementsNeedMove >= 0)
    {
        pInsertAt[numOfElementsNeedMove+1] = pInsertAt[numOfElementsNeedMove];
        numOfElementsNeedMove--;
    }

    *pInsertAt = newElement;
    pArray->numOfItems++;

    return true;
}

bool array2DInsertAtBeginning(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    array2DInsertAt(pArray, 0, 0, newElement);

    return true;
}

bool array2DInsertAtEnd(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    int rowAt = pArray->numOfItems / COL_LENGTH;
    int colAt = pArray->numOfItems % COL_LENGTH;

    array2DInsertAt(pArray, rowAt, colAt, newElement);

    return true;
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


    printf("\nStart: array2DInsertAt(&testArray, 0, 0, 100);\n");
    array2DInsertAt(&testArray, 0, 0, 100);
    array2DPrint(&testArray);
    printf("End: array2DInsertAt(&testArray, 0, 0, 100);\n");

    printf("\nStart: array2DInsertAtEnd(&testArray);\n");
    array2DInsertAtEnd(&testArray, 6);
    array2DPrint(&testArray);
    printf("End: array2DDeleteAtEnd(&testArray);\n");

    printf("\nStart: array2DInsertAtBeginning(&testArray, 55);\n");
    array2DInsertAtBeginning(&testArray, 55);
    array2DPrint(&testArray);
    printf("End: array2DInsertAtBeginning(&testArray, 55);\n");
    
    return 0;
}