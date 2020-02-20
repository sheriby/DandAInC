#include "binary_heap.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define MIN_PQ_SIZE (1 << 3)

struct HeapStruct {
    ElementType *elements;
    int size;
    int capacity;
};

static void ERROR(const char *func, const char *info) {
    printf("ERROR OCCURS in Function [%s]:\t%s\n", func, info);
    exit(-1); // kill this program!
}

PriorityQueue initialize(int maxElements) {
    PriorityQueue p;

    if (maxElements < MIN_PQ_SIZE) {
        maxElements = MIN_PQ_SIZE;
    }
    p = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    p->elements =
        (ElementType *)malloc(sizeof(ElementType) * (maxElements + 1));
    // Why set the element[0] to minimum value of integer?
    // It will make it easy for us to insert element or delete element.
    p->elements[0] = INT_MIN;
    p->size = 0;
    p->capacity = maxElements;

    return p;
}

void destory(PriorityQueue p) {
    free(p->elements); // free the elements array
    // Here we don't free the Elements insides, because I know that
    // I use integer as ElementType....
    free(p); // free priority queue
}

void makeEmpty(PriorityQueue p) { p->size = 0; }

/**
 * Insert a new elemnet.
 * Use "Percolate Up" strategy here.
 */
void insert(ElementType e, PriorityQueue p) {
    int i;
    if (isFull(p)) { // queue is full, cannot insert element into.
        ERROR("insert", "This Priority Queue is Full!");
    }
    // Here i = ++p->size, so i is in next insert position where there are
    // no element now. Then we try to insert element e in that position, if e is
    // less than the value of its father node. => OK, that is correct position.
    // If not, swap their position, and keep doing these procedure until make
    // it. The worst situation is that new element e is the minest element among
    // them. But, do you remember it? We set the element[0] = INT_MIN. So
    // whatever, this new node shall be the right position!

    // i/2 is the father node of i
    // for example, node with index 1 is the father of node with index 2 and 3.
    // Among them, 2 is the left child and 3 is the right node.
    for (i = ++p->size; p->elements[i / 2] > e; i /= 2) {
        p->elements[i] = p->elements[i / 2];
    }
    p->elements[i] = e;
}

/**
 * Delete the minimum element. => (the root node)
 * Use "Percolate Down" strategy here.
 */
ElementType deleteMin(PriorityQueue p) {
    int i, child;
    ElementType minElement, lastElement;

    if (isEmpty(p)) {
        ERROR("deleteMin", "This Priority Queue is Empyt!");
    }
    minElement = p->elements[1]; // save the root element as return value
    lastElement =
        p->elements[p->size--]; // the last element.(which will be removed.)
    for (i = 1; i * 2 <= p->size; i = child) {
        // Find smaller child
        // i * 2 is the left child, and i * 2 + 1 is the right child.
        child = i * 2;

        // Why child != p->size?
        // Beacuse if the size is even number, the last node will not have
        // right child, so we need to judge.
        if (child != p->size && p->elements[child + 1] < p->elements[child]) {
            child++; // change to right child
        }

        // percolate one level
        if (lastElement > p->elements[child]) {
            p->elements[i] = p->elements[child]; // i is the father node.
        } else {
            break;
        }
    }
    p->elements[i] = lastElement;
    return minElement;
}

// The easiest function
ElementType findMin(PriorityQueue p) {
    if (isEmpty(p)) {
        ERROR("findMin", "This Priority Queue is Empyt!");
    }
    return p->elements[1]; // => It is the root of this binary heap.
}

int isEmpty(PriorityQueue p) { return p->size == 0; }
int isFull(PriorityQueue p) { return p->size == p->capacity; }
