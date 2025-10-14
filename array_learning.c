#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _Array
{
    int items[66];
    int length;
} Array;

bool arrayInsertAt(Array* pArray, int at, int newElement);
bool arrayInsertAtBeginning(Array* pArray, int newElement);
bool arrayInsertAtEnd(Array* pArray, int newElement);
bool arrayDeleteFromBeginning(Array* pArray);
bool arrayDeleteFromEnd(Array* pArray);
bool arrayDeleteAt(Array* pArray);
bool arrayFindMax(Array* pArray);
bool arrayFindMin(Array* pArray);
bool arraySort(Array* pArray);
bool arrayTraversal(Array* pArray);
bool arrayPrint(Array* pArray);

bool arrayPrint(Array* pArray)
{
    assert(NULL != pArray);
    for (int i = 0; i < pArray->length; i++)
    {
        printf("%d ", pArray->items[i]);
    }

    printf("\n");
    return true;
}

int main()
{
	return 0;
}

