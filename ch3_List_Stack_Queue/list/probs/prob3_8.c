/**
 * 多项式的幂
 * 给定一个多项式F(X)，计算出(F(X))^P。
 * 至少提出一种对F(X) 和 P的某些可能的选择具有竞争性的解法
 */

#include "../polynomial/polynomia.h"
#include <stdio.h>

/***************Prob3_7中的代码***********************/
// 不想放到头文件中，这里还是要使用乘法的。
void combineSameItem(Polynomial pol) {
    mergeSort(pol); // 对链表进行归并排序
    Position pos = advance(pol);
    Polynomial res = pol;
    Position pres = res;
    int curExp = exponent(pos, pol);
    int curCoe = coefficient(pos, pol);
    Position newNode;
    pos = advance(pos);
    while (pos) {
        if (exponent(pos, pol) == curExp) {
            curCoe += coefficient(pos, pol);
        } else {
            newNode = createItem(curCoe, curExp);
            setNext(pres, newNode, res);
            pres = newNode;

            curExp = exponent(pos, pol);
            curCoe = coefficient(pos, pol);
        }
        pos = advance(pos);
    }
    newNode = createItem(curCoe, curExp);
    setNext(pres, newNode, res);
}

Polynomial polyMul(Polynomial pol1, Polynomial pol2) {
    Position p = advance(pol1);
    Position q = advance(pol2);

    Polynomial res = createPolynomial();
    Position pres = res;
    Position newNode;
    int coe1, coe2, exp1, exp2;
    while (p) {
        coe1 = coefficient(p, pol1);
        exp1 = exponent(p, pol1);

        q = advance(pol2);
        while (q) {
            coe2 = coefficient(q, pol2);
            exp2 = exponent(q, pol2);
            newNode = createItem(coe1 * coe2, exp1 + exp2);
            setNext(pres, newNode, res);
            pres = newNode;
            q = advance(q);
        }
        p = advance(p);
    }
    combineSameItem(res); // 合并乘积的同类项
    return res;
}

/*********************************************************/

/**
 * 之前写的普通的整型的幂
 */
// long long pow(long int x, unsigned int n) {
//     if (n == 0) {
//         return 1;
//     }
//     if (n == 1) {
//         return x;
//     }
//     if (n & 1) { // 使用位与运算表示n是一个奇数(二进制的最后一位为0就是奇数)
//         return pow(x * x, n / 2) * x;
//     } else {
//         return pow(x * x, n / 2);
//     }
// }

/**
 * 返回一个多项式的e次方
 * 可以使用上面的同样的方式
 */
Polynomial polyExp(Polynomial poly, int e) {
    Polynomial res;
    if (e == 0) {
        res = createPolynomial();
        setNext(res, createItem(1, 0), res); // 结果是1
    }
    if (e == 1) {
        return copyPolynomial(poly);
    }
    if (e & 1) {
        return polyMul(polyExp(polyMul(poly, poly), e / 2), poly);
    } else {
        return polyExp(polyMul(poly, poly), e / 2);
    }
}

/**
 * 虽然上面的算法已经算是比较好的了，速度也是非常快，但是总感觉没内味（刚才看了一下答案，答案也是我
 * 上面的这个思路，因为他第二章讲过，我之前也刷到过这个题目）
 *
 * 不过说起求幂，我就想起来二次项定理
 * 下面简单的实现了排列组合的基本函数
 */
int factorial(int m) { // return m!
    if (m == 0 || m == 1) {
        return 1;
    }
    int res = 1;
    int i;
    for (i = 2; i <= m; i++) {
        res *= i;
    }
    return res;
}

int arrange(int m, int n) { // return Amn
    if (m < n) {            // Error!
        return 0;
    } else if (m == n) {
        return factorial(m);
    }
    int res = 1;
    int i;
    for (i = 0; i < n; i++) {
        res *= m--;
    }
    return res;
}

int combine(int m, int n) { // return Cmn(m>n)
    if (m < n) {
        return 0;
    } else if (m == n) {
        return 1;
    }
    n = n > m - n ? m - n : n;
    return arrange(m, n) / factorial(n);
}

/**
 * 这里也需要求幂的函数, 不过这个自然是比多项式的求幂要简单多了
 */
int mypow(int num, int e) {
    if (e == 0) {
        return 1;
    }
    if (e == 1) {
        return num;
    }
    if (e & 1) {
        return mypow(num * num, e / 2) * num;
    } else {
        return mypow(num * num, e / 2);
    }
}

/**
 * 使用二次项定理进行求幂
 * 如 (x + 1)^5 就是 C50 x^5 + C51 x^4 ...
 *
 * 需要注意的是，这里的多项式只可以有两项
 */

int isBin(Polynomial poly) { // 是否多项式中只有两个元素
    return advance(poly) && advance(advance(poly)) &&
           !advance(advance(advance(poly)));
}

void myswap(int *p, int *q) { *p ^= *q ^= *p ^= *q; }

Polynomial binExp(Polynomial poly, int e) {
    if (!isBin(poly)) {
        return NULL;
    }
    int coe1 = coefficient(advance(poly), poly);
    int exp1 = exponent(advance(poly), poly);
    int coe2 = coefficient(advance(advance(poly)), poly);
    int exp2 = exponent(advance(advance(poly)), poly);

    if (exp1 > exp2) { // 使前面的指数小于后面，这样结果就是从小到大有序的了
        myswap(&coe1, &coe2);
        myswap(&exp1, &exp2);
    }

    Polynomial res = createPolynomial();
    Position pres = res;
    int i;
    Position newNode;
    int newCoe;
    int newExp;
    for (i = 0; i <= e; i++) {
        newCoe = combine(e, i) * mypow(coe1, e - i) * mypow(coe2, i);
        newExp = exp1 * (e - i) + exp2 * i;
        newNode = createItem(newCoe, newExp);
        setNext(pres, newNode, res);
        pres = newNode;
    }

    return res;
}

/**
 * 上面我们已经解决了两项的多项式间的幂，看起来很不错，如果我们不是两项的多项式那该如何呢？？
 * 似乎我们又要使用化归的思想了，将他们变成两项的幂。
 *
 * 使用归并排序的方式，将前面和后面分开来计算吗？？？
 * 如 32x^5 + 80x^4 + 80x^3 + 40x^2 + 10x + 1
 * 可以看成 (32x^5 + 80x^4 + 80x^3) + (40x^2 + 10x + 1)
 * 然后再看出 ((32x^5 + 80x^4) + 80x^3) + ((40x^2 + 10x) + 1)
 *
 * emm，，，似乎是我傻了，这个现在还是需要进行很多项很多项的的多项式的乘法
 * 似乎这个方向的思路并不是很聪明的亚子。
 *
 * 不过对于单元素，幂还是很好求的。
 */

int isSingle(Polynomial poly) { // 是否多项式中只有一个元素
    return poly && advance(poly) && !advance(poly);
}

Polynomial singleExp(Polynomial poly, int e) {
    if (!isSingle(poly)) {
        return NULL;
    }
    int coe = coefficient(advance(poly), poly);
    int exp = exponent(advance(poly), poly);

    int newCoe = mypow(coe, e);
    int newExp = exp * e;

    Polynomial res = createPolynomial();
    Position newNode = createItem(newCoe, newExp);
    setNext(res, newNode, res);
    return res;
}

/**
 * 我自认为，只有单个元素或者说只有两个元素的时候，使用上面的方式还是很好求的，我们甚至都没有使用
 * 到多项式的乘法，以及对多项式进行排序。
 *
 * 就将单元素和双元素作为特列，完善一下这个幂算法吧。
 */
Polynomial powOfPoly(Polynomial poly, int e) {
    Polynomial res = singleExp(poly, e);
    if (res) {
        return res;
    }
    res = binExp(poly, e);
    if (res) {
        return res;
    }
    return polyExp(poly, e);
}

int main() {
    int arr[] = {2, 4, 1, 0, 6, 1, 5, -3};
    Polynomial poly = array2Polynomial(arr, 8);
    printList(poly);
    Polynomial res = polyExp(poly, 5);
    printList(res);

    int arr2[] = {2, 2, 3, -4};
    Polynomial p = array2Polynomial(arr2, 4);
    printList(p);
    Polynomial r = powOfPoly(p, 5);
    printList(r);
    return 0;
}