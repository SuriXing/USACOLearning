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

