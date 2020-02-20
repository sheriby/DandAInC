#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int less(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void insertElement(int arr[], int k, int *ele) {
    int i;
    for (i = 0; i < k; i++) {
        if (arr[i] > *ele) {
            // move after element
            while (k > i + 1) {
                arr[k - 1] = arr[k - 2];
                k--;
            }
            arr[i] = *ele;
            break;
        }
    }
}

int findKthMinElement(int arr[], int len, int k) {
    int i;
    qsort(arr, k, sizeof(int), less); // sort k element
    for (i = k; i < len; i++) {
        if (arr[i] < arr[k - 1]) {
            insertElement(arr, k, arr + i);
        }
    }
    return arr[k - 1];
    return 0;
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
