/**
 * 使用一个数组实现两个栈。
 */
#include <malloc.h>
#include <stdio.h>

typedef int ElementType;
typedef struct {
    ElementType *element;
    int capacity;
    int topLeft;  // 左面的栈的顶部
    int topRight; // 右面的栈的顶部
} StackNode, *Stack;

Stack createStack(int capacity) {
    Stack s = malloc(sizeof(StackNode));
    s->element = malloc(capacity * sizeof(ElementType));
    s->capacity = capacity;

    s->topLeft = -1;
    s->topRight = capacity; // 将这两个栈都置为空
}

void freeStack(Stack s) {
    free(s->element);
    free(s);
}

int isEmptyLeft(Stack s) { return s->topLeft == -1; }

int isEmptyRight(Stack s) { return s->topRight == s->capacity; }

int isFull(Stack s) { return s->topLeft + 1 == s->topRight; }

int pushLeft(ElementType ele, Stack s) {
    if (isFull(s)) {
        return 0;
    }

    s->element[++s->topLeft] = ele;
    return 1;
}

int pushRight(ElementType ele, Stack s) {
    if (isFull(s)) {
        return 0;
    }

    s->element[--s->topRight] = ele;
    return 1;
}

int popLeft(Stack s) {
    if (isEmptyLeft(s)) {
        return 0;
    }

    s->topLeft--;
    return 1;
}

int popRight(Stack s) {
    if (isEmptyRight(s)) {
        return 0;
    }

    s->topRight++;
    return 1;
}

ElementType topLeft(Stack s) {
    if (isEmptyLeft(s)) {
        return 0;
    }

    return s->element[s->topLeft];
}

ElementType topRight(Stack s) {
    if (isEmptyRight(s)) {
        return 0;
    }

    return s->element[s->topRight];
}

ElementType topAndPopLeft(Stack s) {
    if (isEmptyLeft(s)) {
        return 0;
    }

    return s->element[s->topLeft--];
}

ElementType topAndPopRight(Stack s) {
    if (isEmptyRight(s)) {
        return 0;
    }

    return s->element[s->topRight++];
}

void printStack(Stack s) {
    int i;
    for (i = 0; i < s->capacity; i++) {
        printf("%d ", s->element[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    Stack s = createStack(5);
    pushLeft(3, s);
    pushLeft(2, s);
    // pushLeft(1, s);

    pushRight(5, s);
    pushRight(7, s);
    pushRight(7, s);
    printStack(s); // 测试OK
    return 0;
}
