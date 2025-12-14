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

int main()
{
    DoubleLinkedList list;
    list.dummyHead.pPrev = NULL; 
    list.dummyHead.pNext = NULL;


    return 0;
}