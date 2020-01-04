#include <stdio.h>
#include <stdlib.h>

// 第一种最简单的算法，时间复杂度为 O(N^3)
int maxSubSum(const int A[], int N) {
    int i, j, k;
    int maxSum = 0;
    int thisSum;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            thisSum = 0;
            for (k = i; k <= j; k++) {
                thisSum += A[k];
            }

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int main(void) {
    const int A[] = {-5, 14, 3, -10, 14, -100};
    printf("The max sub sum is %d\n", maxSubSum(A, 5));

    system("pause");
    return 0;
}