/**
 * 使用时间复杂度O(NlogN)的算法解决该问题
 *
 * 写的两个无论是数组还是链表都是使用书上给的最简单的思路，时间复杂度为O(N²)，
 * 要想时间复杂度降低到O(NlogN)，我想就只有排序了吧。。。
 */

// 看了一下答案，果然答案也是要求排序的。。。排序算法我都写过好多个，这里就不写了
// 直接调用系统的qsort函数吧

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 比较函数
 */
int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void deleteEle(int arr[], int len, int j) {
    memcpy(arr + j, arr + j + 1,
           (len - 1 - j) * sizeof(int)); // 后面的覆盖前面的元素
}

/**
 * 时间复杂度变成了O(N)
 * 
 * 总的时间复杂度就是O(NlogN)
*/
int duplicateRemove(int arr[], int len) {
    if (len < 2) {
        return len;
    }
    int i, j;
    for (i = 0, j = 1; j < len;) {
        if (arr[i] == arr[j]) {
            deleteEle(arr, len--, j);
        } else { // 只有不删除的时候才往后移动
            i++;
            j++;
        }
    }
    return len;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 3, 2, 6, 1, 4, 2, 7, 3, 8, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);
    // 调用系统的快速排序算法，时间复杂度O(NlogN)
    qsort(arr, n, sizeof(int), cmp);
    printArr(arr, n);
    int len = duplicateRemove(arr, n);
    printArr(arr, len);
    getchar();
    return 0;
}
