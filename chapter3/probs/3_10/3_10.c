#include "circle_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
// 直接使用之前定义的链表，只有将尾节点指向头节点，就可以成为单链表了

int singleEle(List list) {
    if (isEmpty(list)) {
        return 0;
    }
    return advance(advance(list)) == list;
}

int josephus(int m, int n) {
    int *arr = malloc(m * sizeof(int));
    int i;
    for (i = 0; i < m; i++) {
        arr[i] = i + 1;
    }

    List list = arrayTolist(arr, m);
    Position p = list;

    int cot = 0;
    int k = 10;
    while (!singleEle(list)) {
        if (cot == n) { // 去掉后面的那个人
            deleteNext(p, list);
            cot = 0;
            continue;
        }
        p = next(p, list);
        cot++;
    }
    return retrieve(advance(list));
}

int main() {
    clock_t start, end;
    start = clock();
    int res = josephus(20000, 1000);
    end = clock();
    printf("winner is %d\n", res);
    printf("Running Time: %dms\b", (end - start));
    return 0;
}