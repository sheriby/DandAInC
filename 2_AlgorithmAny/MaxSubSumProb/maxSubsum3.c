#include <stdio.h>
#include <stdlib.h>

/**
 * 返回三种值中的最大的值
 */
int max3(int a, int b, int c) {
    return a < b ? (b < c ? c : b) : (a < c ? c : a);
}

// 第三种算法，采用递归。算法的时间复杂度为 O(NlogN)
// 算法的主要思路是采用分治的思想，将原来的数组一分为二，将最大的子序和分为了一下的三种情况
// 1. 完全位于左面的数组中
// 2. 完全位于右面的数组中
// 3. 一部分位于左面，另一部分位于右面。（包含左面的结束并且包含右面的开始）
/**
 * @param A 需要进行计算的数组
 * @param left 范围的左边界（包含）
 * @param right 范围的右边界（包含）
 *
 * @return 计算出来的最大子序和
 */
int maxSubSum(const int A[], int left, int right) {
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightborderSum;
    int leftBorderSum, rightBorderSum;
    int center, i;

    if (left == right) { // 处理最基本的情况（递归的基准情形）
        if (A[left] > 0) {
            return A[left];
        } else {
            return 0;
        }
    }

    center = (left + right) >> 1;
    maxLeftSum =
        maxSubSum(A, left, center); // 递归算出第一种情况下的最大的子序和
    maxRightSum =
        maxSubSum(A, center + 1, right); // 递归算出第二种情况下的最大的子序和

    // 算出第三种情况下的最大的子序和
    // 计算包含左面的结束的最大子序和
    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (i = center; i >= left; i--) {
        leftBorderSum += A[i];
        if (leftBorderSum > maxLeftBorderSum) {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    // 计算包含右面开始的最大的子序和
    maxRightborderSum = 0;
    rightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {
        rightBorderSum += A[i];
        if (rightBorderSum > maxRightborderSum) {
            maxRightborderSum = rightBorderSum;
        }
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightborderSum);
}

int maxSubSeqSum(const int A[], int N) { return maxSubSum(A, 0, N - 1); }

int main(void) {
    const int A[] = {-5, 14, 3, -10, 14, -100};
    int N = sizeof(A) / sizeof(A[0]);
    printf("The max sub sum is %d\n", maxSubSeqSum(A, N));

    system("pause");
    return 0;
}