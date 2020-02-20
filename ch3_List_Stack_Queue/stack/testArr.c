#include <stdio.h>
#include "stackArr.h"

struct StackRecord {
    int capacity;   // =>栈的最大容量
    int topOfStack; // => 栈顶的位置，默认是-1表示栈中没有数据
    ElementType *elements; // => 存放栈元素的数组
};

void forEach(Stack s){
    int i;
    for (i=0; i<=s->topOfStack;i++){
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}

int main(){
    Stack s = createStack(10);
    push(3, s);
    push(2, s);
    pop(s);
    printf("%d===\n", top(s));
    push(1, s);
    push(5, s);
    pop(s);
    push(6, s);

    forEach(s);
    printf("%d*******\n", topAndPop(s));
    forEach(s);
    return 0;
}