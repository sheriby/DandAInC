#include <stdio.h>
#include <string.h>
#include "BigInteger.h"

int main() {
    // const char* a = "412243923";
    // const char* b = "98321";
    // BigInteger i1 = string2Integer(a);
    // BigInteger i2 = string2Integer(b);
    // printInteger(i1);
    // printInteger(i2);
    // BigInteger res = addInteger(i1, i2);
    // printInteger(res);
    BigInteger i = string2Integer("11");
    printInteger(i);
    // BigInteger j = string2Integer("10");
    // printInteger(j);
    // BigInteger r = mulInteger(i, j);
    BigInteger r = powInteger(i, 666);
    printInteger(r);
    printf("length => %d", lenInteger(r));
    return 0;
}