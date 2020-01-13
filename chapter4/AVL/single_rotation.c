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
    return t;
}

int main(int argc, char const *argv[]) {
    int arr[] = {6, 5, 4, 3, 2, 1};
    SearchTree t = array2Tree(arr, 6);
    printf("left => %d\nright => %d\n", getLeftHeight(t),
           getRightHeight(t)); // 5 0
    prefix(t);
    t = rotateRight(t);
    prefix(t);
    printf("left => %d\nright => %d\n", getLeftHeight(t),
           getRightHeight(t)); // 4 1
    t = rotateRight(t);
    prefix(t);
    printf("left => %d\nright => %d\n", getLeftHeight(t),
           getRightHeight(t)); // 3 2
    // 经过了几次右旋转之后，我们发现之前的不平衡的节点竟然变平平衡了（并不意味这个树也变平衡了）
    return 0;

    /*
        当修改数组为 => int arr[] = {10, 7, 8, 9, 4, 11};
        发现单旋转无效了，因为单旋转没能解决左子树的右子树的深度过深的问题。
        我们需要新的算法。
    */
}
