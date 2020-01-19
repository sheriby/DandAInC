#include "queue.h"
#include <malloc.h>
#include <stdio.h>

struct QueueRecord {
    int capacity;
    int front;
    int rear;
    int size;
    ElementTypeq *elements;
};

int isEmpty(Queue q) { return q->size == 0; }

int isFull(Queue q) { return q->capacity == q->size; }

int size(Queue q) { return q->size; }

void endl() { printf("\n"); }

Queue createQueue(int capacity) {
    Queue q = malloc(sizeof(struct QueueRecord));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    // 如果想要队列中可以放capacity个数组，我们需要申请capacity + 1大小，
    // 因为不放任何东西的队列也是属于一个状态。
    q->elements = malloc((capacity + 1) * sizeof(ElementTypeq));
}

void disposeQueue(Queue q) {
    free(q->elements);
    free(q);
}

// void makeEmpty(Queue q) {
//     q->size = 0;
//     q->front = 0;
//     q->rear = 0;
//     q->size = 0;
// }

/**
 * 向右移动，如果到最后了则回到原点 方向 =>
 */
int forward(int val, Queue q) {
    if (val == q->capacity) {
        return 0;
    }
    return val + 1;
}

/**
 * 入队的操作
 * 这里我设置的队尾所指向的位置是不包含的。而队头指向的元素是包含的。
 * 当队头和队尾指向的是同一个元素的时候
 *
 * 入队操作，队尾处放置值，队尾向右移动 方向 =>
 */
void enqueue(ElementTypeq ele, Queue q) {
    if (!isFull(q)) {
        q->elements[q->rear] = ele;
        q->rear = forward(q->rear, q);
        q->size++;
    }
}
/**
 * 出队的操作
 * 队头向后移动
 */
void dequeue(Queue q) {
    if (!isEmpty(q)) {
        q->front = forward(q->front, q);
        q->size--;
    }
}
ElementTypeq front(Queue q) {
    if (!isEmpty(q)) {
        return q->elements[q->front];
    }
}
ElementTypeq frontAndDeQueue(Queue q) {
    if (!isEmpty(q)) {
        ElementTypeq temp = q->elements[q->front];
        q->front = forward(q->front, q);
        q->size--;
        return temp;
    }
}

void forEach(Queue q) {
    if (!isEmpty(q)) {
        int temp = q->front;
        while (temp != q->rear) {
            printf("%d ", q->elements[temp]);
            temp = forward(temp, q);
        }
        endl();
    } else {
        printf("Empty Queue!\n");
    }
}
