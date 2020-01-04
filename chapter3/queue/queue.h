#ifndef _QUEUE_H_
#define _QUEUE_H_

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int isEmpty(Queue q);
int isFull(Queue q);
int size(Queue q);
Queue createQueue(int capacity);
void disposeQueue(Queue q);
void makeEmpty(Queue q);
void enqueue(ElementType ele, Queue q);
void dequeue(Queue q);
ElementType front(Queue q);
ElementType frontAndDeQueue(Queue q);
void forEach(Queue q);


#endif