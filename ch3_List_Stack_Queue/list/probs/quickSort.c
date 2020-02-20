/**
 * 数组的快速排序算法。
 * 算法思路，选取值作为基准值（一般是数组的第一个元素），将数组分为左右两个部分
 * 左边都比基准值小，右边都比基准值大
 * 然后分别对左面还有右面进行同样方式的排序
 *
 * 时间复杂度 O(NlogN)
 */
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randArr(int arr[], int len) {
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }
}

/**
 * 对数组的i和j（都包含）部分的内容进行排序
 * 使用移位法而不是交换法
 */
void quickSortPartion(int arr[], int start, int end) {
    if (end - start < 1) { // 数组的元素的个数需要大于等于2
        return;
    }
    int i = start, j = end;
    int base = arr[i]; // 保存基准值
    while (i < j) {
        // 从右面找比基准值小的值
        while (arr[j] >= base) {
            if (j == i) {
                break;
            }
            j--;
        }

        // 找到了覆盖左面的基准值
        arr[i] = arr[j];

        // 从左面找比基准值大的值
        while (arr[i] <= base) {
            if (i == j) {
                break;
            }
            i++;
        }

        // 找到了覆盖右面的值
        arr[j] = arr[i];
    }
    arr[i] = base;
    quickSortPartion(arr, start, i - 1);
    quickSortPartion(arr, i + 1, end);
}

void quickSort(int arr[], int len) { quickSortPartion(arr, 0, len - 1); }

void swap(int *p, int *q) {
    if (p == q) {
        return;
    }
    *p ^= *q ^= *p ^= *q;
}
/**
 * 快速排序的交换法实现
 * 两个指针都从数组的起点开始走
 */
void quickSortPartion2(int arr[], int start, int end) {
    if (end - start < 1) {
        return;
    }
    int baseVal = arr[start];
    int i = start, j = start;
    while (j <= end) {
        if (arr[j] < baseVal) {
            i++; // 在i及其之前的位置都是小于基准值的
            if (i != j) {
                swap(arr + i, arr + j);
            }
        }
        j++;
    }
    swap(arr + i, arr + start); // 将基准值放到中间去，此时i就是基准值的位置
    // printArr(arr, 20);

    quickSortPartion2(arr, start, i - 1);
    // printArr(arr, 20);

    quickSortPartion2(arr, i + 1, end);
}

void quickSort2(int arr[], int len) { quickSortPartion2(arr, 0, len - 1); }

int main() {
    int arr[20];
    randArr(arr, 20);
    printArr(arr, 20);
    quickSort2(arr, 20);
    printArr(arr, 20);
    return 0;
}