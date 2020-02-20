/**
 * 在单链表的基础上修改使其变成单环链表
 */
#include "circle_list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};

/**
 * 打印整个列表
 */
void printList(List list) {
    Position pos = list->next;
    printf("list: [");
    while (pos->next != list) {
        printf("%d, ", pos->element);
        pos = pos->next;
    }
    printf("%d]\n", pos->element);
}

List createList() {
    List list = malloc(sizeof(struct Node));
    list->next = list; // 一开始也就是一个环
}

/**
 * 将c数组转为链表
 */
List arrayTolist(ElementType arr[], int len) {
    List list = createList();
    Position pos = list;
    int i;
    for (i = 0; i < len; i++) {
        insert(arr[i], list, pos);
        pos = advance(pos);
    }
    pos->next = list;
    return list;
}

/**
 * 将列表变成空列表，删除列表中的所有内容。
 */
List makeEmpty(List list) {
    PtrToNode temp = list->next;
    PtrToNode next = NULL;
    while (temp != list) { // 释放后面的空间
        next = temp->next;
        free(temp);
        temp = next;
    }
    list->next = list;
    return list;
}

/**
 * 列表是否为空
 */
int isEmpty(List list) { return list->next == list; }

/**
 * 节点是否为最后一个节点，第二个参数没有使用。
 */
int isLast(Position pos, List list) {
    return !isEmpty(list) && pos->next == list;
}

/**
 * 按顺序找到第一个等于指定的值的位置
 */
Position find(ElementType x, List list) {
    Position pos = list->next;
    while (pos && pos->element != x) {
        pos = pos->next;
    }
    return pos;
}

/**
 * 获取目标节点的前一个节点，可用于删除这个节点
 */
Position findPrevious(ElementType x, List list) {
    Position pos = list;
    while (pos && pos->next->element != x) {
        pos = pos->next;
    }
    return pos;
}

Position findPreviousByAddr(Position pos, List list) {
    Position tmp = advance(list);
    if (tmp && advance(tmp) != pos) {
        tmp = advance(tmp);
    }
    return tmp;
}

/**
 * 找到链表的中间的节点。
 * 使用快慢指针的形式，快指针每次两个位置，慢指针每次走一个位置。
 */
Position findMid(List list) {
    Position fast = list->next;
    Position slow = list->next;

    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * 在目标位置的后面插入元素 参数list没有被使用到
 */
void insert(ElementType x, List list, Position pos) {
    Position temp = (Position)malloc(sizeof(struct Node));
    if (!temp) {
        // 内存不足，分配失败
    }
    temp->element = x;
    temp->next = pos->next;
    pos->next = temp;
}

void deleteNext(Position pos, List list) {
    if (isEmpty(list)) {
        return;
    }
    if (!pos->next) {
        return;
    }
    Position del;
    if (pos->next == list) {
        del = list->next;
        list->next = list->next->next;
        free(del); // 释放空间
    } else {
        del = pos->next;
        pos->next = pos->next->next;
        free(del);
    }
}

/**
 * 删除列表，和置空列表不一样，这次连头结点都删除了
 */
void deleteList(List list) {
    list = makeEmpty(list);
    free(list);
}

/**
 * 返回表头
 */
Position header(List list) { return list; }

/**
 * 返回表的第一个节点
 */
Position first(List list) {
    if (isEmpty(list)) {
        return NULL;
    } else {
        return list->next;
    }
}

/**
 * 返回下一个位置，跳过头节点的。
 */
Position next(Position pos, List list) {
    if (isEmpty(list)) {
        return NULL;
    }
    Position res = pos->next;
    if (res == list) {
        return res->next;
    }
    return res;
}

/**
 * 单纯的返回下一个节点
 */
Position advance(Position pos) { return pos->next; }

/**
 * 返回位置中的值。
 */
ElementType retrieve(Position p) { return p->element; }

ElementType *elementAddr(Position p, List list) { return &(p->element); }

/**
 * 为当前的位置设置next指针的指向
 */
void setNext(Position p, Position next, List list) { p->next = next; }
