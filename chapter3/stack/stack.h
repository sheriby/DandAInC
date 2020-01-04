#ifndef _STACK_H_
#define _STACK_H_

struct Node;
typedef struct Node *Position;
typedef Position PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int isEmpty(Stack s);
Stack createStack(void);
void disposeStack(Stack s);
void makeEmpty(Stack s);
void push(ElementType ele, Stack s);
void pop(Stack s);
ElementType top(Stack s);

#endif //_STACK_H_

