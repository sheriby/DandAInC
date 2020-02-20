#include "leftist_heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PriorityQueue arr2PriorityQueue(int arr[], int len) {
    int i;
    PriorityQueue p = initialize();
    for (i = 0; i < len; i++) {
        insert(arr[i], p);
    }
    return p;
}

void randArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

void printArr(int arr[], int len, const char *name) {
    int i;
    printf("%s: [", name);
    for (i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len - 1]);
}

void test() {
    int arr1[10], arr2[10];
    srand((unsigned int)time(NULL));
    randArr(arr1, 10);
    randArr(arr2, 10);
    printArr(arr1, 10, "Array1");
    printArr(arr2, 10, "Array2");
    PriorityQueue p1 = arr2PriorityQueue(arr1, 10);
    PriorityQueue p2 = arr2PriorityQueue(arr2, 10);
    printf("minimun in p1 => %d\n", findMin(p1));
    printf("minimun in p2 => %d\n", findMin(p2));
    PriorityQueue m = merge(p1, p2);
    printf("minimun when merging p1 and p2 => %d\n", findMin(m));
    deleteMin(m);
    printf("minimum value => %d\n", findMin(m));
    deleteMin(m);
    printf("minimum value => %d\n", findMin(m));
    deleteMin(m);
    printf("minimum value => %d\n", findMin(m));
    deleteMin(m);
    printf("minimum value => %d\n", findMin(m));
    insert(-1, m);
    printf("minimum value => %d\n", findMin(m));
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
