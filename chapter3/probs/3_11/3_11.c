#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randArr(int arr[], int len) {
    srand((unsigned int)time(NULL));

    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % len; // 0~0xffff
    }
}

Position findEleNoRecursion(ElementType ele, List list) {
    Position p = advance(list);
    while (p) {
        if (retrieve(p) == ele) {
            return p;
        }
        p = advance(p);
    }
    return NULL;
}

Position findEleByRecursion(ElementType ele, List list) {
    Position firstEle = first(list);
    if (!firstEle) {
        return NULL;
    }
    if (retrieve(firstEle) == ele) {
        return firstEle;
    } else {
        return findEleByRecursion(ele, firstEle);
    }
}

int main() {
    int arr[300000];
    randArr(arr, 300000);
    time_t start, end;
    Position p;

    List list = arrayTolist(arr, 300000);

    start = clock();
    p = findEleNoRecursion(16666, list);
    end = clock();
    printf("no recursion result => %d\n", retrieve(p));
    printf("Running Time: %dms\n", (end - start));

    start = clock();
    p = findEleByRecursion(16666, list);
    end = clock();
    printf("recursion result => %d\n", retrieve(p));
    printf("Running Time: %dms\n", (end - start));

    return 0;
}