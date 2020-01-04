#include "queue.h"

/**
 * 对队列的一些测试，经过检验，这个队列应该是合格的
*/
int main(){
    Queue q = createQueue(10);
    enqueue(10, q);
    enqueue(20, q);
    enqueue(30, q);
    enqueue(40, q);
    enqueue(50, q);
    enqueue(60, q);
    forEach(q);

    enqueue(60, q);
    enqueue(60, q);
    enqueue(60, q);
    enqueue(60, q);
    enqueue(60, q);
    enqueue(60, q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    forEach(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    forEach(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(60, q);

    

    forEach(q);
    return 0;
}