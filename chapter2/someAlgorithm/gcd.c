#include <stdio.h>

/**
 * 欧几里得算法，用来求解两个数的最大公约数，时间复杂度O(logN)
 */
unsigned int gcd(unsigned int m, unsigned int n) {
    unsigned int rem;
    // if (m < n) { // 后面的操作需要 m >= n。可以直接进行交换也可以使用递归。
    //     return gcd(n, m);
    // }
    if (m < n) {
        m ^= n ^= m ^= n; // 使用异或的方式可以简单的将两个整型变量交换。
    }
    if (n) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

int main() {
    printf("the result is %d\n", gcd(5, 15));
    getchar();
    return 0;
}