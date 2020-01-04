#include <stdio.h>
#include <stdlib.h>

// 第二种算法，减少了一个for循环，将算法的时间复杂度降低到了O(N^2)
// 这个算法同样也是我们最容易想到的算法
int maxSubSum(const int A[], int N) {
    int i, j, k;
    int maxSum = 0;
    int thisSum;
    for (i = 0; i < N; i++) {
        thisSum = 0;
        for (j = i; j < N; j++) {
            thisSum += A[j];
        
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