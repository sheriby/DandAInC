#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int greater(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int findKthMaxElement(int arr[], int len, int k) {
    /*
        [qsort] in <stdlib.h>
        void qsort(void* base, size_t nitems, size_t size,
            int(*compare)(const void*, const void*))
    */
    qsort(arr, len, sizeof(int), greater);
    return arr[k - 1];
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
