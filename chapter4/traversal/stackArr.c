#include "stackArr.h"
#include <stdlib.h>
#define EMPTY -1

// ===========栈的数组实现==================

struct StackRecord {
    int capacity;   // =>栈的最大容量
    int topOfStack; // => 栈顶的位置，默认是-1表示栈中没有数据
    ElementTypes *elements; // => 存放栈元素的数组
};

int isEmpty(Stack s) { return s->topOfStack == EMPTY; }

int isFull(Stack s) { return s->topOfStack == s->capacity - 1; }

/**
 * 创建一个栈的时候需要对栈的三个部分进行相应的初始化。
*/
Stack createStack(int capacity) {
    Stack s = malloc(sizeof(struct StackRecord));
    // 初始化栈结构
    s->capacity = capacity;
    s->topOfStack = EMPTY;
    s->elements = malloc(capacity * sizeof(ElementType));

    return s;
}

void disposeStack(Stack s) {
    if (s) {
        free(s->elements);
        free(s);
    }
}

/**
 * 将栈结构置空，需要注意的是，这里我们置空这个栈的时候，没有必要删除存放数据的数组。
 * 只需要将栈顶置为-1就行了
 */
// void makeEmpty(Stack s) {
//     if (s) {
//         s->topOfStack = EMPTY;
//     }
// }

/**
 * 由数组实现的栈可能会出现栈满的情况，需要对此进行一定的判断。
*/
void push(ElementTypes ele, Stack s) {
    if (!isFull(s)) {
        s->elements[++(s->topOfStack)] = ele;
    }
}

void pop(Stack s) {
    if (!isEmpty(s)) {
        s->topOfStack--;
    }
}

ElementTypes top(Stack s){
    if (!isEmpty(s)){
        return s->elements[s->topOfStack];
    }
}

ElementTypes topAndPop(Stack s){
    if (!isEmpty(s)){
        return s->elements[s->topOfStack--];
    }
}