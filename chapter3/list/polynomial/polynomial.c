#include "polynomia.h"
#include <malloc.h>
#include <stdio.h>

struct Node {
    int coefficient;
    int exponent;
    PtrToNode next;
};

Polynomial createPolynomial() {
    Polynomial temp = malloc(sizeof(struct Node));
    temp->next = NULL;
}

/**
 * 数组的格式是 系数 指数 系数 指数
 */
Polynomial array2Polynomial(int arr[], int len) {
    Polynomial res = createPolynomial();
    Polynomial pres = res;
    int i;
    for (i = 0; i < len; i += 2) {
        insert(arr[i], arr[i + 1], res, pres);
        pres = pres->next;
    }

    return res;
}

void printoneStart(int coe, int exp) {
    if (coe == -1) {
        printf("-");
    } else if (coe != 1) {
        printf("%d", coe);
    }
    printf("x");

    if (exp != 1) {
        printf("^%d", exp);
    }
}

void printoneNoStart(int coe, int exp) {
    if (coe > 0) {
        printf("+");
    }
    printoneStart(coe, exp);
}

void printList(Polynomial list) {
    printf("Polynomial: [");
    Position pos = list->next;
    printoneStart(pos->coefficient, pos->exponent);
    pos = pos->next;
    while (pos) {

        // printf("%dx^%d + ", pos->coefficient, pos->exponent);
        printoneNoStart(pos->coefficient, pos->exponent);
        pos = pos->next;
    }
    printf("]\n");
}

int isEmpty(Polynomial list) { return list->next == NULL; }

int isLast(Position pos, Polynomial list) { return pos->next == NULL; }

Position advance(Position pos) { return pos->next; }

void insert(int coe, int exp, Polynomial list, Position pos) {
    Position newp = malloc(sizeof(struct Node));
    newp->coefficient = coe;
    newp->exponent = exp;
    newp->next = pos->next;
    pos->next = newp;
}

void setNext(Position p, Position next, Polynomial list) { p->next = next; }

int coefficient(Position pos, Polynomial p) { return pos->coefficient; }

int exponent(Position pos, Polynomial p) { return pos->exponent; }

/**
 * 交换两个节点中的系数和指数
 */
void swap(Position p, Position q) {
    if (p == q) {
        return;
    }
    p->exponent ^= q->exponent ^= p->exponent ^= q->exponent;
    p->coefficient ^= q->coefficient ^= p->coefficient ^= q->coefficient;
}

void quickSortPart(Position begin, Position end, Polynomial poly) {
    if (begin == end || begin->next == end || begin->next->next == end) {
        return; // 确保有两项可以排序
    }
    int baseExp = begin->exponent;

    Position p = begin, q = begin;
    while (q != end) {
        if (q->exponent < baseExp) {
            p = p->next;
            swap(p, q);
        }
        q = q->next;
    }
    swap(begin, p);

    quickSortPart(begin, p, poly);
    quickSortPart(p, end, poly);
}

/**
 * 根据多项式的指数对多项式进行排序
 */
void quickSortPolyByExp(Polynomial poly) {
    quickSortPart(poly->next, NULL, poly);
}

/**
 * 归并排序
 * 将两个有序的链表合并成为一个有序的链表
 */
void merge(Polynomial poly1, Polynomial poly2) {
    Polynomial temp = poly1;
    Position ptemp = temp;
    Position p = poly1->next, q = poly2->next;
    while (p && q) {
        if (p->exponent < q->exponent) {
            ptemp->next = p;
            p = p->next;
            ptemp = ptemp->next;
        } else {
            ptemp->next = q;
            q = q->next;
            ptemp = ptemp->next;
        }
    }

    if (p) {
        ptemp->next = p;
    } else {
        ptemp->next = q;
    }
}

/**
 * 使用快慢指针找到链表的中间的元素
 */
Polynomial findMid(Polynomial poly) {
    Position fast = poly->next, slow = poly->next;

    while (fast && fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 * 将链表一分为二，返回后面的部分的头节点
 */
Polynomial midSeparate(Polynomial poly) {
    if (!poly || !poly->next || !poly->next->next) {
        return NULL;
    }
    Polynomial newList = createPolynomial();
    Polynomial mid = findMid(poly);
    newList->next = mid->next;
    mid->next = NULL;
    return newList;
}

/**
 * 使用归并排序对多项式进行排序
 */
void mergeSort(Polynomial poly) {
    if (!poly || !poly->next || !poly->next->next) {
        return;
    }
    Polynomial head1 = poly;
    Polynomial head2 = midSeparate(poly);
    mergeSort(head1);
    mergeSort(head2);
    merge(head1, head2);
}

Position createNode() { return malloc(sizeof(struct Node)); }

void copyNode(Position src, Position dest) {
    dest->coefficient = src->coefficient;
    dest->exponent = src->exponent;
}

/**
 * 拷贝一个多项式
 */
Polynomial copyPolynomial(Polynomial src) {
    Polynomial dest = createPolynomial();
    Position pdest = dest;
    Position psrc = src->next;
    Position newNode;
    while (psrc) {
        newNode = createNode();
        copyNode(psrc, newNode);
        pdest->next = newNode;
        pdest = pdest->next;
        psrc = psrc->next;
    }
    return dest;
}

Position createItem(int coe, int exp) {
    Position tmp = createNode();
    tmp->coefficient = coe;
    tmp->exponent = exp;
    tmp->next = NULL;

    return tmp;
}