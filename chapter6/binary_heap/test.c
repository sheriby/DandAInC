#include "binary_heap.h"
#include <stdio.h>

void test() {
    PriorityQueue p = initialize(1);
    insert(3, p);
    insert(5, p);
    insert(6, p);
    insert(2, p);
    insert(1, p);
    insert(7, p);
    insert(-3, p);
    printf("%d is the minimum element!\n", findMin(p));
    deleteMin(p);
    printf("%d is the minimum element!\n", findMin(p));
    deleteMin(p);
    printf("%d is the minimum element!\n", findMin(p));
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
