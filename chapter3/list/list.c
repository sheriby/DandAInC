#include "list.h"
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
    while (pos->next) {
        printf("%d, ", pos->element);
        pos = pos->next;
    }
    printf("%d]\n", pos->element);
}

List createList(){
    List list = malloc(sizeof(struct Node));
    list->next = NULL;
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
    return list;
}

/**
 * 将列表变成空列表，删除列表中的所有内容。
 */
List makeEmpty(List list) {
    PtrToNode temp = list->next;
    PtrToNode next = NULL;
    while (temp) { // 释放后面的空间
        next = temp->next;
        free(temp);
        temp = next;
    }
    list->next = NULL;
    return list;
}

/**
 * 列表是否为空
 */
int isEmpty(List list) { return list->next == NULL; }

/**
 * 节点是否为最后一个节点，第二个参数没有使用。
 */
int isLast(Position pos, List list) { return pos->next == NULL; }

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

Position findPreviousByAddr(Position pos, List list){
    Position tmp = advance(list);
    if (tmp && advance(tmp) != pos){
        tmp = advance(tmp);
    }
    return tmp;
}


/**
 * 删除列表中从左到右第一个指定的值
 */
void delete(ElementType x, List list) {
    Position pos, temp;
    pos = findPrevious(x, list);
    if (!isLast(pos, list)) { //事实上这肯定不是最后一个节点
        temp = pos->next;
        pos->next = pos->next->next;
        free(temp);
    }
}

/**
 * 在目标位置的后面插入元素 参数list没有被使用到
*/
void insert(ElementType x, List list, Position pos){
    Position temp = (Position)malloc(sizeof(struct Node));
    if (!temp){
        // 内存不足，分配失败
    }
    temp->element = x;
    temp->next = pos->next;
    pos->next = temp;
}

/**
 * 删除列表，和置空列表不一样，这次连头结点都删除了
*/
void deleteList(List list){
    list = makeEmpty(list);
    free(list);
}

/**
 * 返回表头
*/
Position header(List list){
    return list;
}

/**
 * 返回表的第一个节点
*/
Position first(List list){
    return list->next;
}

/**
 * 返回下一个位置
*/
Position advance(Position pos){
    return pos->next;
}

/**
 * 返回位置中的值。
*/
ElementType retrieve(Position p){
    return p->element;
}

ElementType* elementAddr(Position p, List list){
    return &(p->element);
}

/**
 * 为当前的位置设置next指针的指向
*/
void setNext(Position p, Position next, List list){
    p->next = next;
}
