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
 * 每次对一个节点进行访问的时候，将其旋转到根节点的位置。
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

    Position tmp;
    /**
     * 说明待找的节点在左面
     */
    if (ele < retrieve(t)) {
        tmp = splayFind(ele, left(t));
        setLeft(t, tmp);
        return rotateRight(t);
    }

    /**
     * 说明待找到的节点在右面
     */
    if (ele > retrieve(t)) {
        tmp = splayFind(ele, right(t));
        setRight(t, tmp);
        return rotateLeft(t);
    }
}

void randarr(int arr[], int len) {
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 10;
    }
}


int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    SearchTree t = array2Tree(arr, 6);
    prefix(t);
    Position p;
    p = splayFind(5, t);
    prefix(p);
    p = splayFind(3, p);
    prefix(p);
    p = splayFind(6, p);
    prefix(p);
    p = splayFind(1, p);
    prefix(p);
    p = splayFind(2, p);
    prefix(p);
    return 0;
}
