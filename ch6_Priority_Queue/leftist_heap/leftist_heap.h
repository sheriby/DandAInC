#ifndef _LEFTIST_HEAP_H_
#define _LEFTIST_HEAP_H_

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
typedef int ElementType;
typedef int bool;

/**
 * Minimal set of priority queue operation.
 * Note that nodes will be shared among serveral
 * leftist heaps after a merge.
 * The user must make suer to not use the old leftist heaps
 */

PriorityQueue initialize(void);
void destory(PriorityQueue p);
ElementType findMin(PriorityQueue p);
PriorityQueue merge(PriorityQueue p1, PriorityQueue p2);

#define insert(e, p) (p = insert1((e), p))
#define deleteMin(p) (p = deleteMin1(p))

PriorityQueue insert1(ElementType e, PriorityQueue p);
PriorityQueue deleteMin1(PriorityQueue p);

bool isEmpty();

#endif // _LEFTIST_HEAP_H_