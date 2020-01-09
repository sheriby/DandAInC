#include <stdio.h>

/**
 * 第四种算法，时间复杂度为O(N)
 * 非常的简洁，但是算法的思路还是非常的清晰的我感觉
 */
int maxSubSum(const int A[], int N) {
    int maxSum = 0, thisSum = 0;
    int i;
    for (i = 0; i < N; i++) {
        thisSum += A[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) { // 如果此时子序和都已经小于零了，那就重新开始就完事了
            thisSum = 0;
        }
    }
    return maxSum;
}

int main() {
    const int A[] = {-5, 14, 3, -10, 14, -100};
    int N = sizeof(A) / sizeof(A[0]);
    printf("The max sub sum is %d\n", maxSubSum(A, N));

    getchar();
    return 0;
}