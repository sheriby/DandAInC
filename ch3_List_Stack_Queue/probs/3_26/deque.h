#ifndef _DEQUE_H_
#define _DEQUE_H_

struct DequeRecord;
typedef struct DequeRecord *Deque;
typedef int ElementType;

int isEmpty(Deque q);
int isFull(Deque q);
int size(Deque q);
Deque createDeque(int capacity);
void disposeDeque(Deque q);
void makeEmpty(Deque q);

void inject(ElementType ele, Deque q);
ElementType eject(Deque q);
void push(ElementType ele, Deque q);
void pop(Deque q);

ElementType front(Deque q);
ElementType frontAndDeDeque(Deque q);
void forEach(Deque q);

#endif