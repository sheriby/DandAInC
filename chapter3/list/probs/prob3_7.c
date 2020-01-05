/**
 * 链表多项式相乘函数多项式的项分为为M，N（M >= N），计算算法的时间复杂度
 *
 * i)    给出O(M²N²)时间求解该问题的算法
 * ii)  *给出O(M²N)时间求解该问题的算法
 * iii) *给出O(MNlog(MN))时间求解该问题的算法
 */

#include "../polynomial/polynomia.h"

/**
 * 合并链表中的同类项。之前已经实现了O(NLogN)的链表的排序算法了，这里如果链表是
 * 有序的，合并链表的同类项也就非常简单了
 *
 * @param pol 该操作会改变入参的链表中的内容
 *
 * @return 返回合并完成之后的链表
 *
 * 算法的时间复杂度 排序O(NlogN) 合并 O(N) 加起来还是O(NlogN)
 */
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

/**
 * 计算两个的链表的乘积的多项式, 不要求指数值是有序的，可以是乱序的
 *
 * @param pol12 此函数的参数不会被修改
 * @return 乘积的结果，是有序的且合并了同类项的
 * 
 * 算法的时间复杂度 O(MN) 使用到了合并函数。。这个时间复杂度该如何算呢。。。
 */
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

int main() {
    // int arr[] = {1, 2, 3, 2, 5, -1, 7, 2, 6, -2, 4, -1, 9, -3, 7, -2};
    int arr[] = {3, 1, 1, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {3, 2, 2, 1};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    Polynomial pol = array2Polynomial(arr, len);
    Polynomial pol2 = array2Polynomial(arr2, len2);
    printList(pol);
    printList(pol2);
    Polynomial res = polyMul(pol, pol2);
    printList(pol);
    printList(pol2);
    printList(res);
}