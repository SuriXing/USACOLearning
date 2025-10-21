#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _Array2D
{
    int items[66][66];
    int rowLength;
    int colLength;
} Array2D;

bool array2DPrint(Array2D* pArray);

bool array2DPrint(Array2D* pArray)
{
    assert(NULL != pArray);

    for (int i = 0; i < pArray->rowLength; i++)
    {
        for (int j = 0; j < pArray->colLength; j++)
        {
            printf("%d ", pArray->items[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return true;
}

int main()
{
    Array2D testArray =
    {
        {
            { 1, 2, 5, 6 }, 
            { 2, 4, 5, 6 }
        },
        2,
        4
    };

    array2DPrint(&testArray);

    return 0;
}