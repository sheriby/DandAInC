/**
 * 使用链表实现自调整表。
 * 说实话这个还就应该使用链表来做，使用数组是真的有点脑瘫了~~
 */
#include "list.h"
#define NULL (void *)0

void insertSAL(List list, int val) { // 头插法将节点插入到链表的头部
    List next = advance(list);
    insert(val, list, list);
    setNext(advance(list), next, list);
}

Position findSAL(List list, int val) {
    Position pos = advance(list);
    Position prev = list;
    Position res = NULL;
    while (pos) {
        if (retrieve(pos) == val) {
            res = pos;
            break;
        }
        prev = advance(prev);
        pos = advance(pos);
    }

    if (res) {
        setNext(prev, advance(res), list); // 去除当前的节点
        Position next = advance(list);
        setNext(list, res, list);
        setNext(res, next, list); // 将当前的节点放到头部
    }
}

int main(int argc, char const *argv[]) {
    List list = createList();
    insertSAL(list, 1);
    insertSAL(list, 2);
    insertSAL(list, 3);
    insertSAL(list, 4);
    insertSAL(list, 5);
    printList(list); // list: [5, 4, 3, 2, 1]
    findSAL(list, 3);
    printList(list); // list: [3, 5, 4, 2, 1]
    // 测试OK
    return 0;
}
