/**
 * 对链表进行快速排序
 */
#include "../list.h"
#include <stdio.h>

void swap(int *p, int *q) {
    if (p == q) {
        return;
    }
    *q ^= *p ^= *q ^= *p;
}

/**
 * 链表的快速排序
 * 思路和普通的数组的快速排序是一样的。
*/
void quickSortListPart(Position begin, Position end, List list) {
    if (begin == end ||
        advance(begin) == end) { // 链表中只有一个元素或者没有元素的时候
        return;
    }
    Position p = begin, q = begin;
    int baseVal = retrieve(p);
    while (q != end) {
        if (retrieve(q) < baseVal) {
            p = advance(p);
            if (p != q) {
                swap(elementAddr(p, list), elementAddr(q, list));
            }
        }
        q = advance(q);
    }

    swap(elementAddr(p, list), elementAddr(begin, list));

    quickSortListPart(begin, p, list);
    quickSortListPart(advance(p), end, list);
}

void quickSortList(List list){
    quickSortListPart(advance(list), NULL, list);
}

int main(void) {
    int arr[] = {9, 3, 6, 2, 7, 8, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    List list = arrayTolist(arr, len);
    printList(list);
    quickSortList(list);
    printList(list);
}