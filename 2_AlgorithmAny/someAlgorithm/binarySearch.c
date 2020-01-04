#include <stdio.h>
typedef int ElementType;
#define NOTFOUND -1

/**
 * 二分查找，又称对分查找或者折半查找，是一种对有序列表中的查找算法。时间复杂度O(logN)
 * @param A 有序的待查找数组
 * @param value 需要查找的值
 * @param N 数组的大小
 * @return 查找到的下标，如果没有找到则返回NOTFOUND（-1）
*/
int binarySearch(const ElementType A[], ElementType value, int N) {
    int left = 0, right = N - 1;
    int center;
    ElementType centerVal;
    while (left <= right) {
        center = (left + right) >> 1;
        centerVal = A[center];
        if (centerVal == value) {
            return center;
        } else if (centerVal < value) {
            left = center + 1;
        } else {
            right = center - 1;
        }
    }
    return NOTFOUND;
}

int main() {
    const ElementType A[] = {1, 3, 5, 7, 9};
    const int N = sizeof(A) / sizeof(A[0]);
    printf("the index is %d\n", binarySearch(A, 10, N));
    getchar();
    return 0;
}