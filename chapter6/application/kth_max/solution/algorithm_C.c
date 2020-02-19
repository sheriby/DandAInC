#include "../../../binary_heap/binary_heap.h"
#include <stdio.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findKthMinElement(int arr[], int len, int k) {
    int i, res;
    PriorityQueue p = initialize(len);
    for (i = 0; i < len; i++) {
        insert(arr[i], p);
    }
    for (i = 0; i < k - 1; i++) {
        deleteMin(p);
    }
    res = findMin(p);
    destory(p);
    return res;
}

int findKthMaxElement(int arr[], int len, int k) {
    return findKthMinElement(arr, len, len - k + 1);
}

void test() {
    int arr[] = {3, 5, 2, 1, 4, 7, 6, 8, 9, 0};
    int len = sizeof(arr) / sizeof(*arr);
    int res;

    printArr(arr, len);
    res = findKthMaxElement(arr, len, 4);
    printArr(arr, len);

    printf("result => %d\n", res);
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
