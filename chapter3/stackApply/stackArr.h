#ifndef _STACK_ARR_H_
#define _STACK_ARR_H_

struct StackRecord;
typedef struct StackRecord *Stack;
typedef char ElementType;

int isEmpty(Stack s);
int isFull(Stack s);
Stack createStack(int capacity);
void disposeStack(Stack s);
void makeEmpty(Stack s);
void push(ElementType ele, Stack s);
void pop(Stack s);
ElementType top(Stack s);
ElementType topAndPop(Stack s);

#endif // _STACK_ARR_H_