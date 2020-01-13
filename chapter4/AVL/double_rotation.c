#include "bstree.h"
#include <stdio.h>

int max2(int a, int b) { return a > b ? a : b; }

int getHeight(SearchTree t) {
    if (t) {
        return 1 + max2(getHeight(left(t)), getHeight(right(t)));
    } else {
        return 0;
    }
}

int getLeftHeight(SearchTree t) {
    if (t) {
        return getHeight(left(t));
    }
    return 0;
}

int getRightHeight(SearchTree t) {
    if (t) {
        return getHeight(right(t));
    }
    return 0;
}
/**
 * 向右旋转也就是所谓的顺时针旋转。
 */
SearchTree rotateRight(SearchTree t) {
    Position l = left(t);
    setLeft(t, right(l));
    setRight(l, t);
    return l;
}

SearchTree rotateLeft(SearchTree t) {
    Position r = right(t);
    setRight(t, left(r));
    setLeft(r, t);
    return r;
}

int myabs(int a, int b) { return a > b ? a - b : b - a; }

int isAvlNode(Position pos) {
    return myabs(getHeight(left(pos)), getHeight(right(pos))) <= 1;
}

/**
 * 将一个数变成一个AVL树
 */
SearchTree toAvl(SearchTree t) {
    if (!t) { // 空节点是avl了
        return t;
    }

    int lh = getHeight(left(t));
    int rh = getHeight(right(t));
    Position l, r;

    if (isAvlNode(t)) { // 该节点已经是平衡的了
        l = toAvl(left(t));
        r = toAvl(right(t)); // 递归下去使所有的节点都是平衡的了。
        setLeft(t, l);
        setRight(t, r);
        return t;
    } else {
        if (lh > rh) { // 左节点比较深
            l = left(t);
            // 左子树的右子树比较深，此时先对左子树进行左旋转
            while (getHeight(left(l)) <= getHeight(right(l))) {
                l = rotateLeft(l);
            }
            setLeft(t, l);

            while (!isAvlNode(t)) {
                t = rotateRight(t);
            }

            l = toAvl(left(t));
            r = toAvl(right(t));
            setLeft(t, l);
            setRight(t, r);
            return t;
        } else { // 右节点比较深, 同样的操作
            r = right(t);
            while (getHeight(right(r)) <= getHeight(left(r))) {
                r = rotateRight(r);
            }
            setRight(t, r);

            while (!isAvlNode(t)) {
                t = rotateLeft(t);
            }

            l = toAvl(left(t));
            r = toAvl(right(t));
            setLeft(t, l);
            setRight(t, r);
            return t;
        }
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {10, 7,  8, 9, 4,  11, 1,   12, 3, 12,
                 32, 19, 2, 5, 20, 77, 100, 78, 45};
    int len = sizeof(arr) / sizeof(arr[0]);

    SearchTree t = array2Tree(arr, len);
    printf("left => %d\nright => %d\n", getLeftHeight(t),
           getRightHeight(t)); // 3 1
    prefix(t);
    t = toAvl(t);
    prefix(t);
    printf("left => %d\nright => %d\n", getLeftHeight(t),
           getRightHeight(t)); // 2 2
    return 0;
}
