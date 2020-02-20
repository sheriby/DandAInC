/**
 * a stack => push pop and findMid
 */

#include "stackArr.h"
#include <malloc.h>
#include <stdio.h>

typedef int ElementType;
typedef struct {
    Stack element;
    Stack min;
} FStackRecord, *FStack;

FStack createFStack(int capacity) {
    FStack s = malloc(sizeof(FStackRecord));
    s->element = createStack(capacity);
    s->min = createStack(capacity);
}

void Fpush(ElementType ele, FStack s) {
    if (isFull(s->element)) {
        return;
    }

    if (isEmpty(s->min) || ele <= top(s->min)) {
        push(ele, s->min);
    }
    push(ele, s->element);
}

void Fpop(FStack s) {
    if (isEmpty(s->element)) {
        return;
    }

    if (top(s->element) == top(s->min)) {
        pop(s->element);
        pop(s->min);
    } else {
        pop(s->element);
    }
}

ElementType findMin(FStack s) { return top(s->min); }

int main(int argc, char const *argv[])
{
    FStack s = createFStack(10);
    Fpush(10, s);   
    Fpush(7, s);   
    Fpush(4, s);   
    Fpush(8, s);   
    printf("min => %d\n", findMin(s));   
    Fpush(1, s);   
    Fpush(5, s);
    printf("min => %d\n", findMin(s)); 
    Fpop(s);  
    Fpop(s);  
    printf("min => %d\n", findMin(s)); 
    Fpop(s);  
    Fpop(s);  
    Fpop(s);  
    printf("min => %d\n", findMin(s)); 
    // 测试OK
    return 0;
}
