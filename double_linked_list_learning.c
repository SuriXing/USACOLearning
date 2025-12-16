#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _Node
{
    int item;
    struct _Node* pNext;
    struct _Node* pPrev;
} Node;

typedef struct _DoubleLinkedList
{
    Node dummyHead;
//    int length;
} DoubleLinkedList;

bool doubleLinkedListPrint(DoubleLinkedList* pList);
bool doubleLinkedListIsEmpty(DoubleLinkedList* pList);

int doubleLinkedListFindMax(DoubleLinkedList* pList);
int doubleLinkedListFindMin(DoubleLinkedList* pList);

bool doubleLinkedListAddItem(DoubleLinkedList* pList, int newItem);

bool doubleLinkedListIsEmpty(DoubleLinkedList* pList)
{
    assert(NULL != pList);

    return (pList->dummyHead.pNext == NULL);
}

bool doubleLinkedListPrint(DoubleLinkedList* pList)
{
    assert(NULL != pList);

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

int doubleLinkedListFindMax(DoubleLinkedList* pList)
{
    assert(NULL != pList);

    if (doubleLinkedListIsEmpty(pList))
    {
        return 0;
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

int doubleLinkedListFindMin(DoubleLinkedList* pList)
{
    assert(NULL != pList);

    if(doubleLinkedListIsEmpty(pList))
    {
        return 0;
    }

    Node* pCurrent = pList->dummyHead.pNext;
    int minValue = pCurrent->item;

    while (NULL != pCurrent)
    {
        if (minValue > pCurrent->item)
        {
            minValue = pCurrent->item;
        }

        pCurrent = pCurrent->pNext;
    }

    return minValue;
}

bool doubleLinkedListAddItem(DoubleLinkedList* pList, int newItem)
{
    assert(NULL != pList);

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if (NULL == pNewNode)
    {
        return false;
    }
    pNewNode->item = newItem;
    pNewNode->pNext = NULL; 
    pNewNode->pPrev = NULL; 

    Node* pCurrent = &pList->dummyHead;
    while (NULL != pCurrent->pNext)
    {
        pCurrent = pCurrent->pNext;
    }

    pCurrent->pNext = pNewNode;
    pNewNode->pPrev = pCurrent;
    
    return true;
}

int main()
{
    DoubleLinkedList list;
    list.dummyHead.pPrev = NULL; 
    list.dummyHead.pNext = NULL;

    doubleLinkedListAddItem(&list, 6);
    doubleLinkedListAddItem(&list, 6);
    doubleLinkedListAddItem(&list, 8);
    doubleLinkedListAddItem(&list, 8);
    doubleLinkedListAddItem(&list, 8);
    doubleLinkedListAddItem(&list, 1);
    
    //print
    doubleLinkedListPrint(&list);

    //max
    printf("Double Linked List find Max:\n");
    printf("Max value: %d\n", doubleLinkedListFindMax(&list));

    //min
    printf("Double Linked List find Min:\n");
    printf("Min value: %d\n", doubleLinkedListFindMin(&list));

    return 0;
}