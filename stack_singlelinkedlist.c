#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_singlelinkedlist.h"

bool stackPush(StackSingleLinkedList* pStack, int item)
{
    assert(NULL != pStack);
    return singleLinkedListAddItem(&pStack->list, item);
}

int stackPop(StackSingleLinkedList* pStack)
{
    assert(NULL != pStack);
    return singleLinkedListFindLastItem(&pStack->list);
}

int stackTop(StackSingleLinkedList* pStack)
{
    assert(NULL != pStack);
    return singleLinkedListFindLastItem(&pStack->list);
}

int stackSize(StackSingleLinkedList* pStack)
{
    assert(NULL != pStack);
    
    int count = 0;
    Node* current = pStack->list.dummyHead.pNext;
    
    while (current != NULL)
    {
        count++;
        current = current->pNext;
    }
    
    return count;
}

bool stackIsEmpty(StackSingleLinkedList* pStack)
{
    assert(NULL != pStack);

    Node* top = pStack->list.dummyHead.pNext;

    if (NULL == top)
    {
        return true;
    }

    return false;
}

bool stackPrint(StackSingleLinkedList* pStack)
{
    assert(NULL != pStack);

    Node* pCurrent = pStack->list.dummyHead.pNext;

    return singleLinkedListPrint(&pStack->list);
}
