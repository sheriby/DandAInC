#ifndef _STACK_ARR_H_
#define _STACK_ARR_H_

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
typedef int ElementType2;

struct TreeNode {
    ElementType2 element;
    Tree left;
    Tree right;
};

struct StackRecord;
typedef struct StackRecord *Stack;
typedef PtrToNode ElementType;

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