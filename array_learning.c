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

bool arrayInsertAt2(Array* pArray, int at, int newElement);
bool arrayInsertAtBeginning2(Array* pArray, int newElement);
bool arrayInsertAtEnd2(Array* pArray, int newElement);

bool arrayDeleteFromBeginning(Array* pArray);
bool arrayDeleteFromEnd(Array* pArray);
bool arrayDeleteAt(Array* pArray, int at);

bool arrayDeleteFromBeginning2(Array* pArray);
bool arrayDeleteFromEnd2(Array* pArray);
bool arrayDeleteAt2(Array* pArray, int at);

int arrayFindMax(Array* pArray);
int arrayFindMin(Array* pArray);
int arrayFindMax2(Array* pArray);
int arrayFindMin2(Array* pArray);

bool arraySort(Array* pArray);

bool arrayTraversal_slow(Array* pArray);

bool arrayPrint(Array* pArray);
bool arrayPrint2(Array* pArray);

bool arrayPrint2(Array* pArray)
{
    assert(NULL != pArray);

    if (NULL == pArray)
    {
        return false;
    }

    for (int i = 0; i < pArray->length; i++)
    {
        printf("%d ", pArray->items[i]);
    }

    printf("\n");

    return true;
}

int arrayFindMax2(Array* pArray)
{
    assert(NULL != pArray);

    if (NULL == pArray)
    {
        return 0;
    }

    int max = pArray->items[0];

    for (int i = 0; i < pArray->length; i++)
    {
        if (pArray->items[i] > max)
        {
            max = pArray->items[i];
        }
    }

    return max;
}

int arrayFindMin2(Array* pArray)
{
    assert(NULL != pArray);

    if (NULL == pArray)
    {
        return 0;
    }

    int min = pArray->items[0];

    for (int i = 0; i < pArray->length; i++)
    {
        if (pArray->items[i] < min)
        {
            min = pArray->items[i];
        }
    }

    return min;
}

bool arrayDeleteAt2(Array* pArray, int at)
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

bool arrayDeleteFromBeginning2(Array* pArray)
{
    assert(NULL != pArray);
    assert(pArray->length >= 1);

    return arrayDeleteAt2(pArray, 0);
}

bool arrayDeleteFromEnd2(Array* pArray)
{
    assert(NULL != pArray);
    assert(pArray->length >= 1);

    return arrayDeleteAt2(pArray, pArray->length-1);
}

bool arrayInsertAt2(Array* pArray, int at, int newElement)
{
    assert(NULL != pArray);
    assert(at <= pArray->length);
    assert(at >= 0);

    if (pArray->length > sizeof(pArray->items)/sizeof(pArray->items[0]))
    {
        return false;
    }

    for (int i = pArray->length - 1; i >= at; i--)
    {
        pArray->items[i+1] = pArray->items[i];
    }

    pArray->items[at] = newElement;
    pArray->length = pArray->length+1;

    return true;
}

bool arrayInsertAtBeginning2(Array* pArray, int newElement)
{
    assert(NULL != pArray);
    
    return arrayInsertAt2(pArray, 0, newElement);
}

bool arrayInsertAtEnd2(Array* pArray, int newElement)
{
    assert(NULL != pArray);

    return arrayInsertAt2(pArray, pArray->length-1, newElement);
}

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

bool arrayDeleteFromBeginning(Array* pArray)
{
    assert(NULL != pArray);

    return arrayDeleteAt(pArray, 0);
}

bool arrayDeleteFromEnd(Array* pArray)
{
    assert(NULL != pArray);
    assert(pArray->length >= 1);

    return arrayDeleteAt(pArray, pArray->length-1);
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

int arrayFindMax(Array* pArray)
{
    assert(NULL != pArray);

    int max = pArray->items[0];

    for (int i = 0; i<pArray->length; i++)
    {
        if (max < pArray->items[i])
        {
            max = pArray->items[i];
        }
    }

    return max;
}

int arrayFindMin(Array* pArray)
{
    assert(NULL != pArray);

    int min = pArray->items[0];

    for (int i = 0; i<pArray->length; i++)
    {
        if (min > pArray->items[i])
        {
            min = pArray->items[i];
        }
    }

    return min;
}


bool arrayTraversal_slow(Array* pArray)
{
    assert(NULL != pArray);

    int arrayCopy[pArray->length];

    for (int i = 0; i < pArray->length; i++)
    {
        arrayCopy[i] = pArray->items[pArray->length-i-1];
    }

    for (int i = 0; i < pArray->length; i++)
    {
        pArray->items[i] = arrayCopy[i];
    }

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

	printf("arrayFindMax: %d\n", arrayFindMax(&testArray));
	printf("arrayFindMin: %d\n", arrayFindMin(&testArray));

    arrayDeleteFromBeginning(&testArray);

    arrayPrint(&testArray);

    arrayDeleteFromEnd(&testArray);

    arrayPrint(&testArray);

    // second versions testing ares:
    printf("Second version tests:\n");

        Array testArray2 = 
    {
        {1, 3, 5, 7, 8, 4, 3},
        3
    };

    printf("arrayFindMax: %d\n", arrayFindMax2(&testArray2));
	printf("arrayFindMin: %d\n", arrayFindMin2(&testArray2));

    arrayPrint2(&testArray2);

    arrayInsertAtBeginning2(&testArray2, 15);

    arrayPrint2(&testArray2);

    arrayInsertAtEnd2(&testArray2, 6);

    arrayPrint2(&testArray2);

	printf("arrayFindMax: %d\n", arrayFindMax2(&testArray2));
	printf("arrayFindMin: %d\n", arrayFindMin2(&testArray2));

    arrayDeleteFromBeginning2(&testArray2);

    arrayPrint2(&testArray2);

    arrayDeleteFromEnd2(&testArray2);

    arrayPrint2(&testArray2);

    arrayTraversal_slow(&testArray2);

    arrayPrint2(&testArray2);
	
    return 0;
}

