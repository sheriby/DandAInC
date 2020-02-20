/**
 * P66 习题 3-2， 给定两个升序的链表L, R，实现printLots(L, R)
 * 打印L中需要为R中元素的值
 *
 * 难度系数 0
 */

#include "..\list.h"
#include <stdio.h>

void endl() { printf("\n"); }

void printLots(List l, List r) {
    int lcot = 0;
    Position lp = l;
    Position rp = r;
    int pos = 0;
    lp = advance(lp);
    rp = advance(rp);
    while (rp) {
        pos = retrieve(rp);
        while (lcot < pos) {
            lp = advance(lp);
            if (!lp){
                printf("Error!\n");
                return;
            }
            lcot++;
        }
        printf("%d ", retrieve(lp));
        rp = advance(rp);
    };
    endl();
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int pos[] = {0, 1, 5};
    List l = arrayTolist(arr, 5);
    List r = arrayTolist(pos, 3);

    printLots(l, r);

    printList(l);
    printList(r);
    return 0;
}
