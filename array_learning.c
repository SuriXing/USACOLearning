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
bool arrayDeleteAt(Array* pArray, int at);
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

bool arrayInsertAt(Array* pArray, int at, int newElement)
{
    assert(NULL != pArray);
    assert(at <= pArray->length); //abcdefghijklmnopqrstuvwxyz
    assert(at >= 0);
    
    if (pArray->length >= sizeof(pArray->items)/sizeof(pArray->items[0]))
    {
        return false;
    }

    for (int i = pArray->length-1; i >= at; i--)
    {
        pArray->items[i+1] = pArray->items[i];
    }

    pArray->items[at] = newElement;
    pArray->length = pArray->length+1;

    return true;
}

bool arrayInsertAtBeginning(Array* pArray, int newElement)
{
    assert(NULL != pArray);
    
    return arrayInsertAt(pArray, 0, newElement);
}

bool arrayInsertAtEnd(Array* pArray, int newElement)
{
    assert(NULL != pArray);

    Array theArray = *pArray;

    return arrayInsertAt(pArray, theArray.length, newElement);
}

bool arrayDeleteAt(Array* pArray, int at)
{
    assert(NULL != pArray);
    assert(at >= 0);

    if (at >= pArray->length)
    {
        return false;
    }

    for (int i = at; i < pArray->length-1; i++)
    {
        pArray->items[i] = pArray->items[i+1];
    }

    pArray->length = pArray->length-1;

    return true;
}

int main()
{
    Array testArray = 
    {
        { 0 },
        0
    };

    arrayPrint(&testArray);

    arrayInsertAtBeginning(&testArray, 15);

    arrayPrint(&testArray);

    arrayInsertAtEnd(&testArray, 3);

    arrayPrint(&testArray);

	return 0;
}

