#ifndef __STACK_SINGLE_LINKED_LIST_H__
#define __STACK_SINGLE_LINKED_LIST_H__

#include "single_linked_list.h"

typedef struct _StackSingleLinkedList
{
    SingleLinkedList list;
} StackSingleLinkedList;

bool stackPush(StackSingleLinkedList* pStack, int item);
int stackPop(StackSingleLinkedList* pStack);
int stackTop(StackSingleLinkedList* pStack);
int stackSize(StackSingleLinkedList* pStack);
bool stackIsEmpty(StackSingleLinkedList* pStack);
bool stackPrint(StackSingleLinkedList* pStack);
bool stackClear(StackSingleLinkedList* pStack);

#endif  // __STACK_SINGLE_LINKED_LIST_H__