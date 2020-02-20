#include "stack.h"
#include <stdlib.h>
// ===========栈的链表实现==================

/**
 * 栈——是基本数据结构的一种，主要的特定是FILO（First Input Last Output）。
 * 栈结构就像是一个杯子，我们下放入杯子中的东西将一直在杯子的底部，我们新放入的结构将位于杯子的顶部。
 * 我们只可以从顶部获取数据而不能从顶部获取数据。
 *
 * 栈可以当作是列表的一种特殊的形式（事实上通过列表可以很简单的实现栈结构,
 * 比如之前使用C++是数据结构的时候，
 * 直接引用几百行ArrayList的代码加上一点儿自己的代码就可以做出一个完美的栈，但是列表的很多API对于栈来是都是多余了。）
 */

struct Node {
    ElementType element;
    PtrToNode next;
};

/**
 * 返回栈是否为空
 */
int isEmpty(Stack s) { return s->next == NULL; }

/**
 * 创建一个栈
 */
Stack createStack(void) {
    Stack s = malloc(sizeof(struct Node));
    s->next = NULL;
}

/**
 * 彻底删除一个栈
 */
void disposeStack(Stack s) {
    makeEmpty(s);
    free(s);
}

/**
 * 将一个栈置空
 */
void makeEmpty(Stack s) {
    Position pos = s->next, next;
    while (pos) {
        next = pos->next;
        free(pos);
        pos = next;
    }
}

/**
 * 向栈中加入一个元素（加入栈顶）放到链表的最后面
 */
void push(ElementType ele, Stack s) {
    while (s->next) {
        s = s->next;
    }
    Position newNode = malloc(sizeof(struct Node));
    newNode->element = ele;
    newNode->next = NULL;
    s->next = newNode;
}

/**
 * 从栈中删除一个元素(删除栈顶的元素) 删除链表最后面的元素
 */
void pop(Stack s) {
    if (!isEmpty(s)) {
        while (s->next && s->next->next) { // 返回倒数第二个元素
            s = s->next;
        }
        Position top = s->next;
        s->next = NULL;
        free(top);
    }
}

/**
 * 取出栈顶的元素，不删除。 返回链表最后面的元素
 */
ElementType top(Stack s) {
    if (!isEmpty(s)) {
        while (s->next) {
            s = s->next;
        }
        return s->element;
    }
}
