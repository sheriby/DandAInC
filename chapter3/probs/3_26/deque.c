#include "deque.h"
#include <malloc.h>
#include <stdio.h>

struct DequeRecord {
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *elements;
};

int isEmpty(Deque q) { return q->size == 0; }

int isFull(Deque q) { return q->capacity == q->size; }

int size(Deque q) { return q->size; }

void endl() { printf("\n"); }

Deque createDeque(int capacity) {
    Deque q = malloc(sizeof(struct DequeRecord));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    // 如果想要队列中可以放capacity个数组，我们需要申请capacity + 1大小，
    // 因为不放任何东西的队列也是属于一个状态。
    q->elements = malloc((capacity + 1) * sizeof(ElementType));
}

void disposeDeque(Deque q) {
    free(q->elements);
    free(q);
}

void makeEmpty(Deque q) {
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

/**
 * 向右移动，如果到最后了则回到原点 方向 =>
 */
int forward(int val, Deque q) {
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
void inject(ElementType ele, Deque q) {
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
void pop(Deque q) {
    if (!isEmpty(q)) {
        q->front = forward(q->front, q);
        q->size--;
    }
}

// 像左移动 方向 <=
int backword(int val, Deque q) {
    if (val == 0) {
        return q->capacity;
    }
    return val - 1;
}

// 从队尾进行删除元素
ElementType eject(Deque q) {
    if (!isEmpty(q)) {
        ElementType val = q->elements[q->rear];
        q->rear = backword(q->rear, q);
        q->size--;
        return q->rear;
    }
}

/**
 * 像队头添加元素
 */
void push(ElementType ele, Deque q) {
    if (!isFull(q)) {
        q->front = backword(q->front, q);
        q->elements[q->front] = ele;
        q->size++;
    }
}

ElementType front(Deque q) {
    if (!isEmpty(q)) {
        return q->elements[q->front];
    }
}
ElementType frontAndDeDeque(Deque q) {
    if (!isEmpty(q)) {
        ElementType temp = q->elements[q->front];
        q->front = forward(q->front, q);
        q->size--;
    }
}

void forEach(Deque q) {
    if (!isEmpty(q)) {
        int temp = q->front;
        while (temp != q->rear) {
            printf("%d ", q->elements[temp]);
            temp = forward(temp, q);
        }
        endl();
    } else {
        printf("Empty Deque!\n");
    }
}
