#include "bstree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * 对一个节点进行右旋转，返回新的节点
 */
SearchTree rotateRight(SearchTree t) {
    Position l = left(t);
    setLeft(t, right(l));
    setRight(l, t);
    return l;
}

/**
 * 对一个节点进行左旋转，返回新的节点
 */
SearchTree rotateLeft(SearchTree t) {
    Position r = right(t);
    setRight(t, left(r));
    setLeft(r, t);
    return r;
}

/**
 * 伸展树的find操作的实现。
 *
 * 采用了第二种方法————展开。对于不同的状态，需要采取不同的旋转策略。
 *
 * @return 返回值是寻找到的节点，但是同时也变成了新的树的根节点。
 * 也就是说调用了find操作之后，树的结构发生了改变，后面不能再使用函数参数中的t了。
 * 要对t进行覆盖操作。
 */
Position splayFind(ElementType ele, SearchTree t) {
    if (!t) {
        return NULL;
    }

    if (retrieve(t) == ele) {
        return t;
    }

    Position g, p, x; // 分别代表祖父，父和目标节点。
    Position tmp;

    /**
     * 说明待找的节点在左面
     */
    if (ele < retrieve(t)) {
        g = t;
        p = left(t);
        if (ele == retrieve(p)) {
            g = rotateRight(g);
            return g;
        }
        if (ele > retrieve(p)) { // 之字形，直接两次旋转搞定。
            x = splayFind(ele, right(p));
            setRight(p, x);
            p = rotateLeft(p);
            setLeft(g, p);
            g = rotateRight(g);
            return g;
        } else { // 向左的一字型，进行特殊的旋转。
            x = splayFind(ele, left(p));
            tmp = right(x);
            setRight(x, p);
            setLeft(p, tmp);

            tmp = right(p);
            setRight(p, g);
            setLeft(g, tmp);
            return x;
        }
    }

    /**
     * 说明待找到的节点在右面
     */
    if (ele > retrieve(t)) {
        g = t;
        p = right(t);
        if (ele == retrieve(p)) {
            g = rotateLeft(g);
            return g;
        }
        if (ele < retrieve(p)) { // 之字形，直接两次旋转搞定。
            x = splayFind(ele, left(p));
            setLeft(p, x);
            p = rotateRight(p);
            setRight(g, p);
            g = rotateLeft(g);
            return g;
        } else { // 向右的一字型，进行特殊的旋转。
            x = splayFind(ele, right(p));
            tmp = left(x);
            setLeft(x, p);
            setRight(p, tmp);

            tmp = left(p);
            setLeft(p, g);
            setRight(g, tmp);

            return x;
        }
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 3, 1, 2, 6, 7, 0, 8, 9, 4};
    SearchTree t = array2Tree(arr, 10);
    prefix(t);
    Position p;
    p = splayFind(2, t);
    prefix(p);
    p = splayFind(6, p);
    prefix(p);
    p = splayFind(8, p);
    prefix(p);
    p = splayFind(0, p);
    prefix(p);
    p = splayFind(9, p);
    prefix(p);
    p = splayFind(4, p);
    prefix(p);
    
    return 0;
}
