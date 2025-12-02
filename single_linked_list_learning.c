#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _Node
{
    int item;
    struct _Node* pNext;
} Node;

typedef struct _SingleLinkedList
{
    Node dummyHead;
    int length;
} SingleLinkedList;

bool singleLinkedListPrint(SingleLinkedList* pList);
bool singleLinkedListIsEmpty(SingleLinkedList* pList);

int singleLinkedListFindMax(SingleLinkedList* pList);
int singleLinkedListFindMin(SingleLinkedList* pList);

bool singleLinkedListIsEmpty(SingleLinkedList* pList)
{
    assert(NULL != pList);

    return (pList->length == 0);
}

bool singleLinkedListPrint(SingleLinkedList* pList)
{
    assert(NULL != pList);

    if (singleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pCurrent = pList->dummyHead.pNext;

    while (NULL != pCurrent)
    {
        printf("%d", pCurrent->item);

        if (NULL != pCurrent->pNext)
        {
            printf("->");
        }

        pCurrent = pCurrent->pNext;
    }

    printf("\n");

    return true;
}

int singleLinkedListFindMax(SingleLinkedList* pList)
{
    assert(NULL != pList);

    if (singleLinkedListIsEmpty(pList))
    {
        return -1;
    }

    Node* pCurrent = pList->dummyHead.pNext;
    int maxValue = pCurrent->item;

    while (NULL != pCurrent)
    {
        if (maxValue < pCurrent->item)
        {
            maxValue = pCurrent->item;
        }

        pCurrent = pCurrent->pNext;
    }

    return maxValue;
}

int singleLinkedListFindMin(SingleLinkedList* pList)
{
    assert(NULL != pList);

    if (singleLinkedListIsEmpty(pList))
    {
        return -1;
    }

    Node* pCurrent = pList->dummyHead.pNext;
    int minValue = pCurrent->item;

    while (NULL != pList)
    {
        if (minValue > pCurrent->item)
        {
            minValue = pCurrent->item;
        }

        pCurrent = pCurrent->pNext;
    }

    return minValue;
}

int main()
{
    SingleLinkedList list;

    list.dummyHead.pNext = NULL;
    list.length = 0;

    return 0;
}