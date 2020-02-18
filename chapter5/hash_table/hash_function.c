#include <stdio.h>
/*
    simple hash function for int, float, double, long long, and char*.
*/

typedef unsigned int Index;

Index hash_int(int val) { return val; }

Index hash_ll(long long val) { return (val >> 32) ^ val; }

Index hash_float(float val) {
    unsigned int c;
    c = ((unsigned int *)&val)[0];
    return c;
}

Index hash_double(double val) {
    unsigned long long c;
    c = ((unsigned long long *)&val)[0];
    return (c >> 32) ^ c; // hash_ll()
}

Index hash_str(const char *val) {
    int hash = 0;
    while (*val) {
        hash = (hash << 5) - hash + *val; // => 31*hash + *val
        // why 31?? Because 31 is prime number, and multiply 32 is easy in binary.
        val++;
    }
    return hash;
}

int main(int argc, char const *argv[]) {
    printf("%u\n", hash_int(1213812138));
    printf("%u\n", hash_ll(121381213812138l));
    printf("%u\n", hash_float(1.51f));
    printf("%u\n", hash_double(1.51));
    printf("%u\n", hash_str("Hello World!"));
    printf("%u\n", hash_str("Hello World"));
    return 0;
}
