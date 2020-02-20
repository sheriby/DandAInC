/**
 * 给定两个已经排好序的的链表L1，L2, 求解L1, L2中元素的并集
 *
 * 难度系数： 0
 */

#include "..\list.h"

List unionSet(List l1, List l2) {
    List res = createList();
    Position pres = res;
    Position p1 = advance(l1);
    Position p2 = advance(l2);
    int val1, val2;
    while (p1 && p2) // 当两个链表都不为空的时候
    {
        val1 = retrieve(p1), val2 = retrieve(p2);
        if (val1 == val2) { // 相等的话就放到链表中去
            insert(val1, res, pres);
            pres = advance(pres);
            p1 = advance(p1);
            p2 = advance(p2);
        } else if (val1 < val2) {
            p1 = advance(p1);
            insert(val1, res, pres);
            pres = advance(pres);
        } else {
            p2 = advance(p2);
            insert(val2, res, pres);
            pres = advance(pres);
        }
    }

    // 其中有一个是空表，将非空的表直接加入到结果表中就行了，就很耐斯！
    while (p1) {
        insert(retrieve(p1), res, pres);
        pres = advance(pres);
        p1 = advance(p1);
    }

    while (p2) {
        insert(retrieve(p2), res, pres);
        pres = advance(pres);
        p2 = advance(p2);
    }

    return res;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {1, 3, 5, 7, 9, 11};
    List list1 = arrayTolist(a, 6);
    List list2 = arrayTolist(b, 6);
    printList(list1);
    printList(list2);
    List res = unionSet(list1, list2);
    printList(res);
}