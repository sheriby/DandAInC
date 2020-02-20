#include "stack.h"
// #include "stack.c"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    PtrToNode next;
};

void forEachList(Stack s){
    s = s->next;
    while (s){
        printf("%d ",s->element);
        s = s->next;
    }
    printf("\n");

}

int main() {
    Stack s = createStack();
    push(1, s);
    push(2, s);
    push(3, s);
    pop(s);

    push(5, s);
    // push(8, s);
    push(8, s);
    pop(s);
    pop(s);
    // printf("%d\n", top(s));

    forEachList(s);
    // getchar();
    return 0;
}
