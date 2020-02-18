#include "hash_sep.h"
#include <stdio.h>

void test(){
    const char* a = "hello";
    const char* b = "world";
    const char* c = "helloworld";

    HashTable h = initializeTable(10);
    insert(a, h);
    insert(b, h);
    insert(c, h);

    printf("=%s=\n", retrieve(find(a, h)));
    printf("=%s=\n", retrieve(find(b, h)));
    printf("=%s=\n", retrieve(find("hello", h)));
    printf("=%s=\n", retrieve(find("helloWorld", h)));
    printf("=%s=\n", retrieve(find("hello orld", h)));
}

int main(int argc, char const *argv[]) {
    test();
    return 0;
}
