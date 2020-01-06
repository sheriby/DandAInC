#include "list.h"
#define NULL (void *)0

/**
 * 使用递归的方式反转链表
 *
 * 时间复杂度 O(N)
 * 空间复杂度 O(N)
 */
Position reverseListByRecursionHelper(Position pos) {
    Position head, p;
    if (advance(pos)) {
        head = reverseListByRecursionHelper(advance(pos));
        p = head;
        while (advance(p)) {
            p = advance(p);
        }
        setNext(p, pos, head);
        setNext(pos, NULL, head);
        return head;
    } else {
        return pos;
    }
}

void reverseListByRecursion(List list) {
    Position p = reverseListByRecursionHelper(advance(list));
    setNext(list, p, list);
}

/**
 * 上面使用递归的方式可谓是简单明了，下面来使用非递归的方式。
 *
 * 我的思路，
 * 链表其实就是特殊的数组，如果是数组进行反转的话，我会选择头尾两个指针，交换指针的值，然后指针同时前移。
 * (这里的指针不是狭义上的指针，使用下标也是可以的)
 *
 * 但是链表是无法向前移动的，所以这个方式是不行的。
 *
 * 于是我们需要换一个思路
 * 将链表 1->2->3->4->5 变成 5->4->3->2->1
 * 其实也就是变成 1<-2<-3<-4<-5
 * 也就是说每次到下一个节点的时候，我们只需要将其指向上一个节点就好了
 */

/**
 * 使用迭代的方式反转链表，代码简洁而优雅，不错不错~~
 *
 * 时间复杂度 O(N)
 * 空间复杂度 O(1)
 */
void reverseList(List list) {
    Position pre = NULL;
    Position cur = advance(list);
    Position next;
    while (cur) {
        next = advance(cur);
        setNext(cur, pre, list);
        pre = cur;
        cur = next;
    }
    setNext(list, pre, list);
}

int main(void) {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    List list = arrayTolist(arr, 9);

    printList(list);
    reverseList(list);
    printList(list);

    return 0;
}