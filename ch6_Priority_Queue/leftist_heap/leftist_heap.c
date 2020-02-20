#include "leftist_heap.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * #define ture 1
 * #define false 0
 */
static const int true = 1;
static const int false = 0;

struct TreeNode {
    ElementType element;
    PriorityQueue left;
    PriorityQueue right;
    int npl;
};
/**
 * NPL is the short of Null Path Length.
 * NPL(X) is defined as the length from node X
 * to its child node which doesn't have two child node.
 *
 * Thus, NPL of node that has 0 or 1 node is 0, and we
 * defined that NPL(NULL) is -1.
 *
 * Note that the NPL of each node is one more the minimum NPL
 * of its child node.(including those which has two less child node)
 */

static void ERROR(const char *func, const char *info) {
    printf("ERROR OCCURS in Function [%s]:\t%s\n", func, info);
    exit(-1); // kill this program!
}

PriorityQueue initialize(void) { return NULL; }

void destory(PriorityQueue p) {
    if (!p) {
        return;
    }
    if (p->left) {
        destory(p->left);
    }
    if (p->right) {
        destory(p->right);
    }
    free(p);
}

ElementType findMin(PriorityQueue p) {
    if (!p) {
        ERROR("findMin", "The Priority Queue is Empty!");
    }
    return p->element;
}

/**
 * Swap the lfet child and right child of a tree
 */
static void swapChildren(PriorityQueue p) {
    PriorityQueue right = p->right;
    p->right = p->left;
    p->left = right;
}

/**
 * The implement of merge two leftist heaps
 * @param p1 which is not NULL
 * @param p2 which is not NULL
 * From the function merge, we know that p1->element is less than p2->element;
 * @return the merged leftist heap
 */
static PriorityQueue merge1(PriorityQueue p1, PriorityQueue p2) {
    /*p1->left = NULL => p1->right = NULL, so it is single node.*/
    if (!p1->left) {
        p1->left = p2;
    } else {
        p1->right = merge(p1->right, p2);
        if (p1->left->npl < p1->right->npl) {
            swapChildren(p1);
        }

        p1->npl = p1->right->npl + 1;
    }
    return p1;
}

/**
 * Merge two leftist heap.
 */
PriorityQueue merge(PriorityQueue p1, PriorityQueue p2) {
    if (!p1) {
        return p2;
    }
    if (!p2) {
        return p1;
    }

    if (p1->element < p2->element) {
        return merge1(p1, p2);
    } else {
        return merge1(p2, p1);
    }
}

/**
 * Insert is equivalent to merge a single node.
 */
PriorityQueue insert1(ElementType e, PriorityQueue p) {
    PriorityQueue singleNode;
    singleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
    if (!singleNode) {
        ERROR("insert", "Malloc New Node Fail!");
    } else {
        singleNode->element = e;
        singleNode->left = singleNode->right = NULL;
        p = merge(singleNode, p);
    }
    return p;
}

bool isEmpty(PriorityQueue p) {
    if (p) {
        return false;
    }
    return true;
}

PriorityQueue deleteMin1(PriorityQueue p) {
    PriorityQueue leftHeap, rightHeap;

    if (isEmpty(p)) {
        ERROR("deleteMin", "The Priority Queue is Empty!");
    }
    leftHeap = p->left;
    rightHeap = p->right;
    free(p);
    return merge(leftHeap, rightHeap);
}
