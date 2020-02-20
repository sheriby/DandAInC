#ifndef _STACK_ARR_H_
#define _STACK_ARR_H_
#include "bstree.h"
struct StackRecord;
typedef struct StackRecord *Stack;
typedef Position ElementTypes;

int isEmpty(Stack s);
int isFull(Stack s);
Stack createStack(int capacity);
void disposeStack(Stack s);
// void makeEmpty(Stack s);
void push(ElementTypes ele, Stack s);
void pop(Stack s);
ElementTypes top(Stack s);
ElementTypes topAndPop(Stack s);

#endif // _STACK_ARR_H_