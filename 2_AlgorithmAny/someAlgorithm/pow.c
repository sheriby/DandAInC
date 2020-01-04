#include <stdio.h>

/**
 * 快速取幂算法，时间复杂度为 O(logN)
 * @param x 底数
 * @param n 指数
 * @return 计算出来的结果
*/
long long pow(long int x, unsigned int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    if (n & 1) { // 使用位与运算表示n是一个奇数(二进制的最后一位为0就是奇数)
        return pow(x * x, n / 2) * x;
    } else {
        return pow(x * x, n / 2);
    }
}

int main() {
    printf("the result is %lld\n", pow(3, 30));

    getchar();
    return 0;
}