/**
 * 编写两个链表多项式相加的函数，其中两个多项式分为为M，N项，
 * 请计算你的程序的时间复杂度。。。
 *
 * 要完成这个题目，我还要先来个多项式写一个链表结构，因为我们通用的链表中只可以放置一个元素，
 * 如果硬要我往里面放一个结构体，感觉看起来很煞笔~~
 *
 * 难度系数: 0.1
 */

#include "..\polynomial/polynomia.h"

/**
 * 将两个链表相加，其中两个链表的系数都是有序的,
 * 这样思路和之前的多项式交集并集就是一样的了
 *
 * 算法时间复杂度 => O(N)  2N??
 */
Polynomial orderPolyAdd(Polynomial pol1, Polynomial pol2) {
    Polynomial res = createPolynomial();
    Position pres = res;
    Position p1 = advance(pol1);
    Position p2 = advance(pol2);

    int exp1, exp2;
    int coe1, coe2;
    while (p1 && p2) {
        exp1 = exponent(p1, pol1);
        exp2 = exponent(p2, pol2);
        coe1 = coefficient(p1, pol1);
        coe2 = coefficient(p2, pol2);
        if (exp1 == exp2) {
            insert(coe1 + coe2, exp1, res, pres);
            pres = advance(pres);
            p1 = advance(p1);
            p2 = advance(p2);
        } else if (exp1 < exp2) {
            insert(coe1, exp1, res, pres);
            pres = advance(pres);
            p1 = advance(p1);
        } else {
            insert(coe2, exp2, res, pres);
            pres = advance(pres);
            p2 = advance(p2);
        }
    }

    while (p1) {
        insert(coe1, exp1, res, pres);
        pres = advance(pres);
        p1 = advance(p1);
    }

    while (p2) {
        insert(coe2, exp2, res, pres);
        pres = advance(pres);
        p2 = advance(p2);
    }

    return res;
}

/**
 * 只是解决了两个有序的链表的相加问题，如果是无序的呢？？？
 * 那就化归就完事了，我们要做的就是将这个多项式变得有序，别无其他。
 *
 * 这个函数应该是放在多项式那个文件中来实现。。。定义在头文件中
 *
 * 将多项式以指数的大小进行排序
 * 排序方式？
 * 如果我们想要使用交换节点的排序方式，或许冒泡是最容易的选择，但是效率也太低了。
 * 而且本题中，链表中我们也没有使用什么大型的数据，所以只需要交换节点中的数据就行了。
 * 理想的排序方式有如下的两种：
 * 快速排序和归并排序。。。
 * 我还是先来复习复习普通数组的快速排序和归并排序吧。
 */
Polynomial polyAdd(Polynomial poly1, Polynomial poly2) {
    mergeSort(poly1);          // 使用归并排序  => 交换节点
    quickSortPolyByExp(poly2); // 使用快速排序  => 交换节点中的数据
    return orderPolyAdd(poly1, poly2);
}

// TODO 经过了排序之后我们似乎可以发现一个比较大的问题，那就是原来的数据被我们更改了。。。
// 不过想想，似乎也是应该的。。。下面可以使用一个拷贝函数来弥补一下这个缺点

/**
 * 使用这种方式就可以不该变原来的数据啦~~~
*/
Polynomial polyAddNoChange(Polynomial poly1, Polynomial poly2){
    Polynomial temp1 = copyPolynomial(poly1);
    Polynomial temp2 = copyPolynomial(poly2);

    return polyAdd(temp1, temp2);
}
int main(void) {
    int arr[] = {1, 3, 2, 4, 6, -1, 7, 2};
    Polynomial p1 = array2Polynomial(arr, 8);
    int arr2[] = {3, 3, 3, 2, 5, -1, 6, 1, 3, 4};
    Polynomial p2 = array2Polynomial(arr2, 10);
    printList(p1);
    printList(p2);

    Polynomial res = polyAddNoChange(p1, p2);
    printList(res);
    printList(p1);
    printList(p2);
    return 0;
}