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


    return 0;
}