/**
 * 链表的归并排序
 * 和数组的归并排序一样，链表的归并排序一直在在做的一个问题就是讲两个有序的链表合并
 * 成为一个有序的链表，这个事情，似乎我们之前已经做过了。
 *
 */
#include "../list.h"
#include <stdio.h>


/**
 * 使用快慢指针将一个链表一分为二。
*/
Position midSeparate(List list){
    Position fast = advance(list);
    Position slow = advance(list);
    Position prev = list;

    while (fast && advance(fast))
    {
        fast = advance(advance(fast));
        slow = advance(slow);
        prev = advance(prev);
    }

    setNext(prev, NULL, list);
    List newlist = createList();
    setNext(newlist, slow, newlist);
    return newlist;
}

Position midSeparate2(List list){
    Position mid = findMid(list);
    Position next = advance(mid);

    setNext(mid, NULL, list); // 切断原先的链表

    List newlist = createList();
    setNext(newlist, next, newlist);
    return newlist;
}


/**
 * 将两个有序的链表进行合并操作
 * @return 返回合并之后的链表的头部
 */
Position merge(List list1, List list2) {
    Position p = advance(list1), q = advance(list2);
    List temp = list1; // 随便选取一个作为表头
    Position pos = temp;

    while (p && q) {
        // 将较小的节点放到链表的后面去
        if (retrieve(p) < retrieve(q)) {
            setNext(pos, p, temp);
            p = advance(p);
            pos = advance(pos);
        } else {
            setNext(pos, q, temp);
            q = advance(q);
            pos = advance(pos);
        }
    }
    // 将非空的链表插入
    if (p) {
        setNext(pos, p, temp);
    }
    if (q) {
        setNext(pos, q, temp);
    }

    return temp;
}

void mergeSort(List list){
    // 递归的终止条件，链表中需要有至少两个数据才进行排序。
    if (!list || !advance(list) || !advance(advance(list))){
        return;
    }

    List head1 = list;
    List head2 = midSeparate(list);
    // printList(head1);
    // printList(head2);
    mergeSort(head1);
    mergeSort(head2);
    list = merge(head1, head2);
}

int main() {
    int arr[] = {111, 3, 14, 77, 110, 216, 27};
    int len = sizeof(arr) / sizeof(arr[0]);
    List list = arrayTolist(arr, len);
    printList(list);
    // List list2 = midSeparate2(list);
    // printList(list);
    // printList(list2);
    // List list3 = merge(list, list2);
    // printList(list3);
    mergeSort(list);
    printList(list);
    return 0;
}
