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
bool array2DPrint2(Array2D* pArray);
bool array2DPrint3(Array2D* pArray);

int array2DFindMax(Array2D* pArray);
int array2DFindMin(Array2D* pArray);

int array2DFindMax2(Array2D* pArray);
int array2DFindMin2(Array2D* pArray);

int array2DFindMax3(Array2D* pArray);
int array2DFindMin3(Array2D* pArray);

int array2DFindMax4(Array2D* pArray);
int array2DFindMin4(Array2D* pArray);

int array2DFindMax5(Array2D* pArray);
int array2DFindMin5(Array2D* pArray);

bool array2DInsertAt(Array2D* pArray, int rowAt, int colAt, int newElement);
bool array2DInsertAtBeginning(Array2D* pArray, int newElement);
bool array2DInsertAtEnd(Array2D* pArray, int newElement);

bool array2DInsertAt2(Array2D* pArray, int rowAt, int colAt, int newElement);
bool array2DInsertAtBeginning2(Array2D* pArray, int newElement);
bool array2DInsertAtEnd2(Array2D* pArray, int newElement);

bool array2DInsertAt3(Array2D* pArray, int rowAt, int colAt, int newElement);
bool array2DInsertAtBeginning3(Array2D* pArray, int newElement);
bool array2DInsertAtEnd3(Array2D* pArrray, int newElement);

bool array2DDeleteAt(Array2D* pArray, int rowAt, int colAt);
bool array2DDeleteAtBeginning(Array2D* pArray);
bool array2DDeleteAtEnd(Array2D* pArray);

bool array2DIsFull(Array2D* pArray)
{
    assert(NULL != pArray);

    return (ROW_LENGTH * COL_LENGTH <= pArray->numOfItems);
}

bool array2DIsEmpty(Array2D* pArray)
{
        assert(NULL != pArray);

    return (pArray->numOfItems > 0);
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

bool array2DPrint2(Array2D* pArray)
{
    assert(NULL != pArray);

    for (int i = 0; i < ROW_LENGTH;  i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            printf("%d\t", pArray->items[i][j]);
        }
        printf("\n");
    }

    return true;
}

bool array2DPrint3(Array2D* pArray)
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

    return true;
}

int array2DFindMax(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
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

    for (int i = 0; i < pArray->numOfItems / COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int j = 0; j < pArray->numOfItems % COL_LENGTH; j++)
    {
        if (min > pArray->items[pArray->numOfItems / COL_LENGTH][j])
        {
            min = pArray->items[pArray->numOfItems / COL_LENGTH][j];
        }
    }

    return min;
}

int array2DFindMax2(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (max < pArray->items[i][j])
            {
                max = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems% COL_LENGTH; i++)
    {
        if (max < pArray->items[pArray->numOfItems/COL_LENGTH][i])
        {
            max = pArray->items[pArray->numOfItems/COL_LENGTH][i];
        }
    }

    return max;
}

int array2DFindMin2(Array2D* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int j = 0; j < pArray->numOfItems % COL_LENGTH; j++)
    {
        if (min > pArray->items[pArray->numOfItems / COL_LENGTH][j])
        {
            min = pArray->items[pArray->numOfItems / COL_LENGTH][j];
        }
    }

    return min;
}

int array2DFindMax3(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems / COL_LENGTH; i++)
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

int array2DFindMin3(Array2D* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems / COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems % COL_LENGTH; i++)
    {
        if (min > pArray->items[pArray->numOfItems/COL_LENGTH][i])
        {
            min = pArray->items[pArray->numOfItems/COL_LENGTH][i];
        }
    }

    return min;
}

int array2DFindMax4(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
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

int array2DFindMin4(Array2D* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems % COL_LENGTH; i++)
    {
        if (min > pArray->items[pArray->numOfItems/COL_LENGTH][i])
        {
            min = pArray->items[pArray->numOfItems/COL_LENGTH][i];
        }
    }

    return min;
}

int array2DFindMax5(Array2D* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
    {
        for (int j= 0; j < COL_LENGTH; j++)
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

int array2DFindMin5(Array2D* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0][0];

    for (int i = 0; i < pArray->numOfItems/COL_LENGTH; i++)
    {
        for (int j = 0; j < COL_LENGTH; j++)
        {
            if (min > pArray->items[i][j])
            {
                min = pArray->items[i][j];
            }
        }
    }

    for (int i = 0; i < pArray->numOfItems % COL_LENGTH; i++)
    {
        if (min > pArray->items[pArray->numOfItems / COL_LENGTH][i])
        {
            min = pArray->items[pArray->numOfItems / COL_LENGTH][i];
        }
    }

    return min;
}

bool array2DInsertAt(Array2D* pArray, int rowAt, int colAt, int newElement)
{
    assert(NULL != pArray);
    assert((rowAt >= 0) && (rowAt < ROW_LENGTH));
    assert((colAt >= 0) && (colAt < COL_LENGTH));

    if (array2DIsFull(pArray))
    {
        return false;
    }

    // == means insert at the end of the array
    if ((rowAt * COL_LENGTH + colAt) > pArray->numOfItems)
    {
        return false;
    }

    int numOfElementsNeedMove = (pArray->numOfItems - (rowAt * COL_LENGTH + colAt));    // Calculate how many items need move
    /* 
        Pointer to the insert position, but I force type cast to one dimension integer array.
        Because I know two dimension arrray is actually continously in memory (just like one dimension array)
    */
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

bool array2DInsertAt2(Array2D* pArray, int rowAt, int colAt, int newElement)
{
    assert(NULL != pArray);
    assert((rowAt >= 0) && (rowAt < ROW_LENGTH));
    assert((colAt >= 0) && (rowAt < COL_LENGTH));

    if (array2DIsFull(pArray))
    {
        return false;
    }

    // == means insert at the end of the array
    if ((rowAt * COL_LENGTH + colAt) > pArray->numOfItems)
    {
        return false;
    }

    int numOfElementsNeedMove = (pArray->numOfItems - (rowAt * COL_LENGTH + colAt));

    int* pInsertAt = (int*) (&pArray->items[rowAt][colAt]);

    while (numOfElementsNeedMove >= 0)
    {
        pInsertAt[numOfElementsNeedMove +1] = pInsertAt[numOfElementsNeedMove];

        numOfElementsNeedMove--;
    }

    *pInsertAt = newElement;

    pArray->numOfItems++;

    return true;
}

bool array2DInsertAtBeginning2(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    array2DInsertAt2(pArray, 0, 0, newElement);

    return true;
}

bool array2DInsertAtEnd2(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    int rowAt = pArray->numOfItems / COL_LENGTH;
    int colAt = pArray->numOfItems % COL_LENGTH;

    array2DInsertAt2(pArray, rowAt, colAt, newElement);

    return true;
}

bool array2DInsertAt3(Array2D* pArray, int rowAt, int colAt, int newElement)
{
    assert(NULL != pArray);
    assert((rowAt >= 0) && (rowAt < ROW_LENGTH));
    assert((colAt >= 0) && (colAt < COL_LENGTH));

    if (array2DIsFull(pArray))
    {
        return false;
    }

    if ((rowAt * COL_LENGTH + colAt) > pArray->numOfItems)
    {
        return false;
    }

    int numOfElementsNeedMove = (pArray->numOfItems - (rowAt * COL_LENGTH + colAt));

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

bool array2DInsertAtBeginning3(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    return array2DInsertAt(pArray, 0, 0, newElement);
}

bool array2DInsertAtEnd3(Array2D* pArray, int newElement)
{
    assert(NULL != pArray);

    int rowAt = pArray->numOfItems / COL_LENGTH;
    int colAt = pArray->numOfItems % COL_LENGTH;

    return array2DInsertAt(pArray, rowAt, colAt, newElement);
}

bool array2DDeleteAt(Array2D* pArray, int rowAt, int colAt)
{
    assert(NULL != pArray);
    assert((rowAt >= 0) && (rowAt < ROW_LENGTH));
    assert((colAt >= 0) && (colAt < COL_LENGTH));

    if (array2DIsEmpty(pArray))
    {
        return false;
    }

    if ((rowAt * COL_LENGTH + colAt) >= pArray->numOfItems)
    {
        return false;
    }

    int numOfElementsNeedMove = (pArray->numOfItems - (rowAt * COL_LENGTH + colAt)) - 1;    // Calculate how many items need move

    int *pDeleteAt = (int*)(&pArray->items[rowAt][colAt]);
    for (int i = 0; i < numOfElementsNeedMove; i++)
    {
        pDeleteAt[i] = pDeleteAt[i+1];
    }

    pArray->numOfItems--;

    return true;    
}

bool array2DDeleteAtBeginning(Array2D* pArray)
{
    assert(NULL != pArray);

    array2DDeleteAt(pArray, 0, 0);

    return true;
}

bool array2DDeleteAtEnd(Array2D* pArray)
{
    assert(NULL != pArray);

    int rowAt = pArray->numOfItems / COL_LENGTH;
    int colAt = pArray->numOfItems % COL_LENGTH;

    array2DDeleteAt(pArray, rowAt, colAt);

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

    printf("array find max2: %d\n", array2DFindMax(&testArray));
    printf("array find min3: %d\n", array2DFindMin2(&testArray));
    
    printf("array find max3: %d\n", array2DFindMax3(&testArray));
    printf("array find min4: %d\n", array2DFindMin4(&testArray));

    printf("\nStart: array2DInsertAt(&testArray, 0, 0, 100);\n");
    array2DInsertAt(&testArray, 0, 0, 100);
    array2DPrint2(&testArray);
    printf("End: array2DInsertAt(&testArray, 0, 0, 100);\n");

    array2DInsertAtBeginning(&testArray, 66);
    array2DPrint3(&testArray);
    printf("End: array2DInsertAtBeginning(&testArray, 66);\n");

    printf("\nStart: array2DInsertAtEnd(&testArray, 66);\n");
    array2DInsertAtEnd(&testArray, 66);
    array2DPrint(&testArray);
    printf("End: array2DInsertAtEnd(&testArray, 66);\n");

    printf("\nStart: array2DInsertAt2(&testArray, 0, 0, 100);\n");
    array2DInsertAt2(&testArray, 0, 0, 100);
    array2DPrint2(&testArray);
    printf("End: array2DInsertAt2(&testArray, 0, 0, 100);\n");

    printf("\nStart: array2DInsertAtBeginning2(&testArray, 101);\n");
    array2DInsertAtBeginning2(&testArray, 101);
    array2DPrint3(&testArray);
    printf("End: array2DInsertAtBeginning2(&testArray, 101);\n");

    printf("\nStart: array2DInsertAtEnd2(&testArray, 102);\n");
    array2DInsertAtEnd2(&testArray, 102);
    array2DPrint(&testArray);
    printf("End: array2DInsertAtEnd2(&testArray, 102);\n");

    printf("\nStart: array2DInsertAtEnd3(&testArray, 66);\n");
    array2DInsertAtEnd3(&testArray, 66);
    array2DPrint(&testArray);
    printf("End: array2DInsertAtEnd3(&testArray, 66);\n");

    printf("\nStart: array2DDeleteAtEnd(&testArray);\n");
    array2DDeleteAtEnd(&testArray);
    array2DPrint(&testArray);
    printf("End: array2DDeleteAtEnd(&testArray);\n");

    printf("\nStart: array2DInsertAtBeginning3(&testArray, 55);\n");
    array2DInsertAtBeginning3(&testArray, 55);
    array2DPrint3(&testArray);
    printf("End: array2DInsertAtBeginning3(&testArray, 55);\n");

    printf("\nStart: array2DDeleteAtBeginning(&testArray);\n");
    array2DDeleteAtBeginning(&testArray);
    array2DPrint(&testArray);
    printf("End: array2DDeleteAtBeginning(&testArray);\n");

    return 0;
}