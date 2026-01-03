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
//  int length;
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

bool singleLinkedListFindItem(SingleLinkedList* pList, int item);

bool singleLinkedListReverse(SingleLinkedList* pList);
bool singleLinkedListReverse2(SingleLinkedList* pList);
bool singleLinkedListReverse3(SingleLinkedList* pList);

SingleLinkedList  singleLinkedListClone(SingleLinkedList* pList);
bool singleLinkedListIsSame(SingleLinkedList* pList1, SingleLinkedList* pList2);
int singleLinkedListCompare(SingleLinkedList* pList1, SingleLinkedList* pList2);

SingleLinkedList  singleLinkedListClone2(SingleLinkedList* pList);

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

bool singleLinkedListFindItem(SingleLinkedList* pList, int item)
{
    assert(NULL != pList);

    if (singleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pCurrent = pList->dummyHead.pNext;

    while (NULL != pList)
    {
        if (pCurrent->item == item)
        {
            return true;
        }
        else
        {
            pCurrent = pCurrent->pNext;
        }
    }

    return false;
}

bool singleLinkedListReverse(SingleLinkedList* pList)
{
    assert(NULL != pList);

    Node* pCurrent = pList->dummyHead.pNext;
    Node* pPrev = NULL; // very important, because first element will become last element, whose pNext should be NULL
    Node* pNext = NULL;
    
    while (NULL != pCurrent)
    {
        pNext = pCurrent->pNext;
     
        printf("%d\n", pCurrent->item);
        pCurrent->pNext = pPrev;
        
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    pList->dummyHead.pNext = pPrev;

    printf("%d\n", pList->dummyHead.pNext->item);

    return true;
}

bool singleLinkedListReverse2(SingleLinkedList* pList)
{
    assert(NULL != pList);

    Node* pCurrent = pList->dummyHead.pNext;
    Node* pPrev = NULL;
    Node* pNext = NULL;

    while (NULL != pCurrent)
    {
        pNext = pCurrent->pNext;

        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    pList->dummyHead.pNext = pPrev;

    return true;
}

bool singleLinkedListReverse3(SingleLinkedList* pList)
{
    assert(NULL != pList);

    Node* pCurrent = pList->dummyHead.pNext;
    Node* pPrev = NULL;
    Node* pNext = NULL;

    while (NULL != pCurrent)
    {
        pNext = pCurrent->pNext;

        pCurrent->pNext = pPrev;

        pPrev = pCurrent;
        pCurrent = pNext;
    }
    pList->dummyHead.pNext = pPrev;

    return true;
}

bool singleLinkedListIsSame(SingleLinkedList* pList1, SingleLinkedList* pList2)
{
    assert(NULL != pList1);
    assert(NULL != pList2);

    Node* pCurrent1 = pList1->dummyHead.pNext;
    Node* pCurrent2 = pList2->dummyHead.pNext;

    while ((NULL != pCurrent1) && (NULL != pCurrent2))
    {
        if (pCurrent1->item != pCurrent2->item)
        {
            return false;
        }

        pCurrent1 = pCurrent1->pNext;
        pCurrent2 = pCurrent2->pNext;
    }

    if ((NULL == pCurrent1) && (NULL == pCurrent2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int singleLinkedListCompare(SingleLinkedList* pList1, SingleLinkedList* pList2)
{
    //if list1 > list2, return 1
    //if list1 = list2, return 0
    //if list1 < list2, reutrn -1

    assert(NULL != pList1);
    assert(NULL != pList2);

    Node* pCurrent1 = pList1->dummyHead.pNext;
    Node* pCurrent2 = pList2->dummyHead.pNext;

    while ((NULL != pCurrent1) && (NULL != pCurrent2))
    {
        if (pCurrent1->item == pCurrent2->item)
        {
            pCurrent1 = pCurrent1->pNext;
            pCurrent2 = pCurrent2->pNext;
        }
        else if (pCurrent1->item > pCurrent2->item)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    if ((NULL == pCurrent1) && (NULL == pCurrent2))
    {
        return 0;
    }
    else if ((NULL != pCurrent1) && (NULL == pCurrent2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

SingleLinkedList singleLinkedListClone(SingleLinkedList* pList)
{
    assert(NULL != pList);

    SingleLinkedList newList;
    newList.dummyHead.item = 0;
    newList.dummyHead.pNext = NULL;

    Node* pCurrent = pList->dummyHead.pNext;
    Node* pNewCurrent = &newList.dummyHead;
    while (NULL != pCurrent)
    {
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->item = pCurrent->item;
        pNewNode->pNext = NULL;

        pNewCurrent->pNext = pNewNode;

        pNewCurrent = pNewCurrent->pNext;
        pCurrent = pCurrent->pNext;
    }

    return newList;
}

SingleLinkedList  singleLinkedListClone2(SingleLinkedList* pList)
{
    assert(NULL != pList);

    SingleLinkedList newList;
    newList.dummyHead.item = 0;
    newList.dummyHead.pNext = NULL;

    Node* pCurrent = pList->dummyHead.pNext;
    Node* pNewCurrent = &newList.dummyHead;
    while (NULL != pCurrent)
    {
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode->item = pCurrent->item;
        pNewNode->pNext = NULL;

        pNewCurrent->pNext = pNewNode;

        pNewCurrent = pNewCurrent->pNext;
        pCurrent = pCurrent->pNext;
    }

    return newList;
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

    SingleLinkedList list2;
    list2.dummyHead.pNext = NULL;

    singleLinkedListAddItem(&list2, 1);
    singleLinkedListAddItem(&list2, 2);
    singleLinkedListAddItem(&list2, 6);
    singleLinkedListAddItem(&list2, 8);
    
    printf("Linked list1: ");
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
  
    // Find
    int item = 8;
    printf("\nFind Whether %d is in the list:\n", item);
    printf("%d\n", singleLinkedListFindItem(&list, item));

    // Reverse1
    printf("\nReverse single linked list:\n");
    singleLinkedListReverse(&list);
    singleLinkedListPrint(&list);
    
    // Reverse2
    printf("\nReverse single linked list:\n");
    singleLinkedListReverse2(&list);
    singleLinkedListPrint(&list);

    // Reverse3
    printf("\nReverse single linked list:\n");
    singleLinkedListReverse3(&list);
    singleLinkedListPrint(&list);

    //same
    printf("Single Linked List 1.0 is same:\n");
    printf("%d\n", singleLinkedListIsSame(&list, &list2));

    //compare
    printf("Double Linked List 1.0 compare:\n");
    printf("%d\n", singleLinkedListCompare(&list, &list2));

    //clone
    SingleLinkedList newList = singleLinkedListClone(&list);
    printf("%d\n", singleLinkedListIsSame(&list, &newList));
    
    return 0;
}