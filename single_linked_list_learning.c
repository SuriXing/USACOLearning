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
//    int length;
} SingleLinkedList;

bool singleLinkedListPrint(SingleLinkedList* pList);
bool singleLinkedListIsEmpty(SingleLinkedList* pList);

bool singleLinkedListPrint2(SingleLinkedList* pList);

int singleLinkedListFindMax(SingleLinkedList* pList);
int singleLinkedListFindMin(SingleLinkedList* pList);

bool singleLinkedListAddItem(SingleLinkedList* pList, int newItem);
bool singleLinkedListAddItem2(SingleLinkedList* pList, int newItem);

bool singleLinkedListDeleteItem(SingleLinkedList* pList, int deletedItem);
bool singleLinkedListDeleteItem2(SingleLinkedList* pList, int deletedItem);

bool singleLinkedListIsEmpty(SingleLinkedList* pList)
{
    assert(NULL != pList);

    return (pList->dummyHead.pNext == NULL);
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

bool singleLinkedListPrint2(SingleLinkedList* pList)
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

bool singleLinkedListAddItem(SingleLinkedList* pList, int newItem)
{
    assert(NULL != pList);

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if (NULL == pNewNode)
    {
        return false;
    }
    pNewNode->item = newItem;
    pNewNode->pNext = NULL;

    Node* pCurrent = &pList->dummyHead;
    while (NULL != pCurrent->pNext)
    {
        pCurrent = pCurrent->pNext;
    }

    pCurrent->pNext = pNewNode;

    return true;
}

bool singleLinkedListAddItem2(SingleLinkedList* pList, int newItem)
{
    assert(NULL != pList);

    Node* pNewNode = (Node*)malloc(sizeof(Node));
    if (NULL == pNewNode)
    {
        return false;
    }

    pNewNode->item = newItem;
    pNewNode->pNext = NULL;

    Node* pCurrent = &pList->dummyHead;
    while (NULL != pCurrent->pNext)
    {
        pCurrent = pCurrent->pNext;
    }

    pCurrent->pNext = pNewNode;

    return true;
}

bool singleLinkedListDeleteItem(SingleLinkedList* pList, int deletedItem)
{
    assert(NULL != pList);
    
    if (singleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pPrev = &pList->dummyHead;
    Node* pCurrent = pPrev->pNext;

    while (NULL != pCurrent)
    {
        if (pCurrent->item == deletedItem)
        {
            pPrev->pNext = pCurrent->pNext;

            free(pCurrent);

            pCurrent = pPrev->pNext;
        }
        else
        {
            pCurrent = pCurrent->pNext;
            pPrev = pPrev->pNext;
        }
    }

    return true;
}

bool singleLinkedListDeleteItem2(SingleLinkedList* pList, int deletedItem)
{
    assert(NULL != pList);

    if (singleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pPrev = &pList->dummyHead;
    Node* pCurrent = pPrev->pNext;

    while (NULL != pCurrent)
    {
        if (pCurrent->item == deletedItem)
        {
            pPrev->pNext = pCurrent->pNext;

            free(pCurrent);

            pCurrent = pPrev->pNext;
        }
        else
        {
            pCurrent = pCurrent->pNext;
            pPrev = pPrev->pNext;
        }
    }

    return true;
}

int main()
{
    SingleLinkedList list;
    list.dummyHead.pNext = NULL;    
//  list.length = 0;
    
    singleLinkedListAddItem(&list, 1);
    singleLinkedListAddItem(&list, 2);
    singleLinkedListAddItem(&list, 6);

    singleLinkedListAddItem2(&list, 8);
    singleLinkedListAddItem2(&list, 8);
    singleLinkedListAddItem2(&list, 8);
    
    printf("Linked list: ");
    singleLinkedListPrint(&list);
    
    // Find Min
    printf("\nFind Min value in single linked list:\n");
    printf("Min value: %d\n", singleLinkedListFindMin(&list));

    // Find Max
    printf("\nFind Max value in single linked list:\n");
    printf("Max value: %d\n", singleLinkedListFindMax(&list));

    // Delete
    int deleteItem = 1;
    printf("\nDelete %d in single linked list:\n", deleteItem);
    singleLinkedListDeleteItem(&list, deleteItem);
    singleLinkedListPrint(&list);

    singleLinkedListAddItem(&list, 1);

    // Delete2
    printf("\nDelete %d in single linked list:\n", deleteItem);
    singleLinkedListDeleteItem(&list, deleteItem);
    singleLinkedListPrint(&list);
  
    return 0;
}