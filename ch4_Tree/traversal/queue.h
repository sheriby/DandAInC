#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "bstree.h"
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef Position ElementTypeq;

int isEmpty(Queue q);
int isFull(Queue q);
int size(Queue q);
Queue createQueue(int capacity);
void disposeQueue(Queue q);
// void makeEmpty(Queue q);
void enqueue(ElementTypeq ele, Queue q);
void dequeue(Queue q);
ElementTypeq front(Queue q);
ElementTypeq frontAndDeQueue(Queue q);
void forEach(Queue q);


#endif