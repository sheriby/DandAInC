/**
 * 试分析2^2000中0-9的分布情况
 */
#include "BigInteger.h"
#include <stdio.h>

void analyze(BigInteger b, int exp) {
    BigInteger res = powInteger(b, exp);
    int counter[10] = {0};
    Bit p = res;
    while (*p) {
        counter[*(p++) - '0']++;
    }

    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ==> %d\n", i, counter[i]);
    }

    /*
    Result:
        0 ==> 62
        1 ==> 57
        2 ==> 65
        3 ==> 59
        4 ==> 60
        5 ==> 59
        6 ==> 65
        7 ==> 49
        8 ==> 71
        9 ==> 56
    */
}

int main(void) {
    BigInteger b = string2Integer("2");
    int exp = 2000;
    analyze(b, exp);

    return 0;
}