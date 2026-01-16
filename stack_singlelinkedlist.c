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

bool stackClear(StackSingleLinkedList* pStack)
{
    Node *pCurrent = pStack->list.dummyHead.pNext;
    
    while (NULL != pCurrent)
    {
        Node *pNext = pCurrent->pNext;
        
        free(pCurrent);
        pCurrent = pNext;
    }

    pStack->list.dummyHead.pNext = NULL;

    return true;
}

int stackTest()
{
    printf("=== Simple Stack Test ===\n");
    
    StackSingleLinkedList myStack;
    myStack.list.dummyHead.pNext = NULL;  
    // Test 1: Push and pop
    printf("1. Push 10: ");
    bool pushed = stackPush(&myStack, 10);
    printf("%s\n", pushed ? "OK" : "FAILED");
    
    printf("   Pop: %d (should be 10)\n", stackPop(&myStack));
    
    // Test 2: Multiple pushes
    printf("\n2. Pushing 1, 2, 3\n");
    stackPush(&myStack, 1);
    stackPush(&myStack, 2);
    stackPush(&myStack, 3);
    
    printf("   Stack size: %d\n", stackSize(&myStack));
    printf("   Top item: %d (should be 3)\n", stackTop(&myStack));
    printf("   Pop: %d (should be 3)\n", stackPop(&myStack));
    printf("   Pop: %d (should be 2)\n", stackPop(&myStack));
    printf("   Pop: %d (should be 1)\n", stackPop(&myStack));
    
    printf("   Stack size now: %d (should be 0)\n", stackSize(&myStack));
    
    printf("=== Test Complete ===\n");

    return 0;
}