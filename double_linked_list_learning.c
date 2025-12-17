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
bool doubleLinkedListDeleteItem(DoubleLinkedList* pList, int deletedItem);

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

bool doubleLinkedListDeleteItem(DoubleLinkedList* pList, int deletedItem)
{
    assert(NULL != pList);

    if (doubleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pCurrent = pList->dummyHead.pNext;

    while (NULL != pCurrent)
    {
        if (pCurrent->item == deletedItem)
        {
            pCurrent->pPrev->pNext = pCurrent->pNext;

            Node* pNext = pCurrent->pNext;
            if (NULL != pNext)
            {
                pCurrent->pNext->pPrev = pCurrent->pPrev;
            }

            free(pCurrent);

            pCurrent = pNext;
        }
        else
        {
            pCurrent = pCurrent->pNext;
        }
    }

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

    //delete
    int deletedItem = 1;
    printf("Double Linked List delete %d from list:\n", deletedItem);
    doubleLinkedListDeleteItem(&list, deletedItem);
    doubleLinkedListPrint(&list);

    return 0;
}