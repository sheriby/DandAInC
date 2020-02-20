#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

PriorityQueue initialize(int maxElements);
void destory(PriorityQueue p);
void makeEmpty(PriorityQueue p);
void insert(ElementType e, PriorityQueue p);
ElementType deleteMin(PriorityQueue p);
ElementType findMin(PriorityQueue p);
int isEmpty(PriorityQueue p);
int isFull(PriorityQueue p);

#endif // _BINARY_HEAP_H_