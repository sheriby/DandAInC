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

int coefficient(Position pos, Polynomial p){
    return pos->coefficient;
}

int exponent(Position pos, Polynomial p){
    return pos->exponent;
}
