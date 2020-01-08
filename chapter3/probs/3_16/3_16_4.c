#include "list.h"
#include <stdio.h>

void swap(int *p, int *q) {
    if (p == q) { // 交换的时候一定要注意--两个变量的地址不能相同
        return;
    }
    *q ^= *p ^= *q ^= *p;
}

void quickSortParition(List list, Position begin, Position end) {
    if (begin == end ||
        advance(begin) == end) { // 如果只有一个元素，或者没有元素直接返回。
        return;
    }
    int base = retrieve(begin);
    Position p = begin;
    Position q = advance(begin);

    while (q != end) {
        if (retrieve(q) < base) {
            p = advance(p);
            swap(elementAddr(q, list), elementAddr(p, list));
        }
        q = advance(q);
    }

    swap(elementAddr(p, list), elementAddr(begin, list));

    quickSortParition(list, begin, p);
    quickSortParition(list, advance(p), end);
}

void quickSort(List list) { quickSortParition(list, advance(list), NULL); }

void duplicateRemove(List list) {
    Position pos = advance(list);
    Position pnext = advance(pos);
    while (pnext) {
        if (retrieve(pnext) == retrieve(pos)) {
            setNext(pos, advance(pnext), list);
            pnext = advance(pnext);
            continue;
        }
        pos = advance(pos);
        pnext = advance(pnext);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 4, 3, 2, 6, 1, 4, 2, 7, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    List list = arrayTolist(arr, n);
    printList(list); // list: [5, 4, 3, 2, 6, 1, 4, 2, 7, 3, 8, 1, 2]
    quickSort(list);
    printList(list); // list: [1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8]
    duplicateRemove(list);
    printList(list); // list: [1, 2, 3, 4, 5, 6, 7, 8]
    // 测试完成
    return 0;
}
