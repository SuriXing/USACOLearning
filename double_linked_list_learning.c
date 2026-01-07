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
bool doubleLinkedListAddItem2(DoubleLinkedList* pList, int newItem);

bool doubleLinkedListDeleteItem(DoubleLinkedList* pList, int deletedItem);
bool doubleLinkedListDeleteItem2(DoubleLinkedList* pList, int deletedItem);
bool doubleLinkedListDeleteItem3(DoubleLinkedList* pList, int deletedItem);

bool doubleLinkedListFindItem(DoubleLinkedList* pList, int item);
bool doubleLinkedListFindItem2(DoubleLinkedList* pList, int item);

bool doubleLinkedListReverse(DoubleLinkedList* pList);

DoubleLinkedList* doubleLinkedListClone(DoubleLinkedList* pList);

bool doubleLinkedListIsSame(DoubleLinkedList* pList1, DoubleLinkedList* pList2);
bool doubleLinkedListIsSame2(DoubleLinkedList* pList1, DoubleLinkedList* pList2);
bool doubleLinkedListIsSame3(DoubleLinkedList* pList1, DoubleLinkedList* pList2);

int doubleLinkedListCompare(DoubleLinkedList* pList1, DoubleLinkedList* pList2);
int doubleLinkedListCompare2(DoubleLinkedList* pList1, DoubleLinkedList* pList2);
int doubleLinkedListCompare3(DoubleLinkedList* pList1, DoubleLinkedList* pList2);
int doubleLinkedListCompare4(DoubleLinkedList* pList1, DoubleLinkedList* pList2);

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

bool doubleLinkedListAddItem2(DoubleLinkedList* pList, int newItem)
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

    Node* pCurrent = pList->dummyHead.pNext;
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

bool doubleLinkedListDeleteItem2(DoubleLinkedList* pList, int deletedItem)
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

bool doubleLinkedListDeleteItem3(DoubleLinkedList* pList, int deletedItem)
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

bool doubleLinkedListFindItem(DoubleLinkedList* pList, int item)
{
    assert(NULL != pList);

    if (doubleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pCurrent = pList->dummyHead.pNext;

    while (NULL != pCurrent)
    {
        if (item == pCurrent->item)
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

bool doubleLinkedListFindItem2(DoubleLinkedList* pList, int item)
{
    assert(NULL != pList);

    if (doubleLinkedListIsEmpty(pList))
    {
        return false;
    }

    Node* pCurrent = pList->dummyHead.pNext;

    while (NULL != pCurrent)
    {
        if (item == pCurrent->item)
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

bool doubleLinkedListIsSame(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
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

int doubleLinkedListCompare(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
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
        else if(pCurrent1->item > pCurrent2->item)
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

bool doubleLinkedListIsSame2(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
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

int doubleLinkedListCompare2(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
{
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
        else if (pCurrent1 > pCurrent2)
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

bool doubleLinkedListIsSame3(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
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

int doubleLinkedListCompare3(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
{
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
        else if (pCurrent1 > pCurrent2)
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

int doubleLinkedListCompare4(DoubleLinkedList* pList1, DoubleLinkedList* pList2)
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
        else if(pCurrent1->item > pCurrent2->item)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
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

    DoubleLinkedList list2;
    list2.dummyHead.pPrev = NULL;
    list2.dummyHead.pNext = NULL;

    doubleLinkedListAddItem(&list2, 6);
    doubleLinkedListAddItem(&list2, 6);
    doubleLinkedListAddItem(&list2, 8);
    doubleLinkedListAddItem(&list2, 8);
    doubleLinkedListAddItem(&list2, 8);
    doubleLinkedListAddItem(&list2, 8);
    doubleLinkedListAddItem(&list2, 8);
    doubleLinkedListAddItem(&list2, 8);

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

    //add (2)
    printf("Double Linked List Add 2 to list:\n");
    doubleLinkedListAddItem2(&list, 2);
    doubleLinkedListPrint(&list);

    //delete2
    deletedItem = 2;
    printf("Double Linked List 2.0 delete %d from list:\n", deletedItem);
    doubleLinkedListDeleteItem2(&list, deletedItem);
    doubleLinkedListPrint(&list);

    //add (3)
    printf("Double Linked List Add 3 to list:\n");
    doubleLinkedListAddItem2(&list, 3);
    doubleLinkedListPrint(&list);

    //delete3
    deletedItem = 3;
    printf("Double Linked List 3.0 delete %d from list:\n", deletedItem);
    doubleLinkedListDeleteItem3(&list, deletedItem);
    doubleLinkedListPrint(&list);

    //find1
    printf("Double Linked List Find 8 from list:\n");
    printf("%d\n",doubleLinkedListFindItem(&list, 8));

    //find2
    printf("Double Linked List Find 6 from list:\n");
    printf("%d\n",doubleLinkedListFindItem2(&list, 6));

    //same1
    printf("Double Linked List 1.0 is same:\n");
    printf("%d\n", doubleLinkedListIsSame(&list, &list2));

    //compare1
    printf("Double Linked List 1.0 compare:\n");
    printf("%d\n", doubleLinkedListCompare(&list, &list2));

    //same2
    printf("Double Linked List 2.0 is same:\n");
    printf("%d\n", doubleLinkedListIsSame2(&list, &list2));

    //compare2
    printf("Double Linked List 2.0 compare:\n");
    printf("%d\n", doubleLinkedListCompare2(&list, &list2));

    //same3
    printf("Double Linked List 3.0 is same:\n");
    printf("%d\n", doubleLinkedListIsSame3(&list, &list2));


    //compare3
    printf("Double Linked List 3.0 compare:\n");
    printf("%d\n", doubleLinkedListCompare3(&list, &list2));    

    return 0;
}