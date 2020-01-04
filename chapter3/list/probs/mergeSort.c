/**
 * 归并排序的数组实现，归并排序使用的是分治的思想。
 * 将数组一分为2，2分为4，分到最后只有一个，对他们分别进行排序。
 *
 * 这个算法到底是什么意思呢？其实和我们的化归思想还是有点儿像的。
 * 比如有如下的数组 1 7 6 3 9 2 4 8
 * 经过分之后变成了八个数组 1, 7, 6, 3, 9, 2, 4,
 * 8（事实上我们并没有对数组进行分割） 那么这有什么用呢？
 * 当数组中只有一个元素的时候，他必定是有序的。将两个有序的数组合并成一个有序的数组我想这是很简单的问题。
 * 1 7, 3 6, 2 9, 4 8
 * 合并之后的四个数组都是有序的，我们可以继续合并
 * 1 3 6 7, 2 4 8 9
 * 然后再合并 1 2 3 4 6 7 8 9 排序成功
 * 可见，我们始终在做一件事情，那就是将两个有序数组合并成一个有序数组
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
 * 使用异或交换两个整数
 */
void swap(int arr[], int i, int j) { arr[i] ^= arr[j] ^= arr[i] ^= arr[j]; }

void copy(int arr[], int ai, int aj, int *temp) {
    int i = ai;
    while (ai <= aj) {
        arr[ai] = temp[ai];
        ai++;
    }
}

/**
 * 将两个有序的部分合并成为一个有序的部分
 * @param mid 包含在左面的部分中
 */
void merge(int arr[], int left, int mid, int right, int *temp) {
    // 需要一个额外的数组空间，这样合并的更加省事, 不过为了不每次都创建这个东西
    // 可以只在开始的时候创建，然后每次调用的时候传参进行来
    int i = left, j = mid + 1;
    int pos = left;
    while (pos <= right) {
        if (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[pos++] = arr[i++];
            } else {
                temp[pos++] = arr[j++];
            }
        } else { // 其中一个部分没有数据了
            while (i <= mid) {
                temp[pos++] = arr[i++];
            }
            while (j <= right) {
                temp[pos++] = arr[j++];
            }
            break;
        }
    }
    // 将临时数组中的内容拷贝当当前数组中来。
    copy(arr, left, right, temp);
}

/**
 * 上面是合并的操作现在是分的操作，然后合并
 */
void mergeSortHelper(int arr[], int start, int end, int *temp) {
    int mid;
    if (start < end) {
        mid = (start + end) >> 1; // 找到中间的位置
        mergeSortHelper(arr, start, mid, temp); // 分左面的部分
        mergeSortHelper(arr, mid+1, end, temp); // 分右面的部分
        merge(arr, start, mid, end, temp); // 左右的部分合并
    }
}

void mergeSort(int arr[], int len){
    int* temp = malloc(len*sizeof(int));
    mergeSortHelper(arr, 0, len-1, temp);
    free(temp);
}

int main() {
    int arr[20];
    randArr(arr, 20);
    printArr(arr, 20);
    mergeSort(arr, 20);
    printArr(arr, 20);
    return 0;
}