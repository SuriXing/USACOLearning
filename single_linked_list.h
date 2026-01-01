#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

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

int singleLinkedListFindMax(SingleLinkedList* pList);
int singleLinkedListFindMin(SingleLinkedList* pList);

bool singleLinkedListAddItem(SingleLinkedList* pList, int newItem);
bool singleLinkedListDeleteItem(SingleLinkedList* pList, int deletedItem);
bool singleLinkedListFindItem(SingleLinkedList* pList, int item);

bool singleLinkedListReverse(SingleLinkedList* pList);

SingleLinkedList  singleLinkedListClone(SingleLinkedList* pList);
bool singleLinkedListIsSame(SingleLinkedList* pList1, SingleLinkedList* pList2);
int singleLinkedListCompare(SingleLinkedList* pList1, SingleLinkedList* pList2);

int singleLinkedListFindFirstItem(SingleLinkedList* pList);
int singleLinkedListFindLastItem(SingleLinkedList* pList);

#endif // __SINGLE_LINKED_LIST_H__