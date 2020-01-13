#include "bstree.h"
#include <malloc.h>
#include <stdio.h>

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree createNode(ElementType ele) {
    SearchTree t = malloc(sizeof(struct TreeNode));
    t->element = ele;
    t->left = NULL;
    t->right = NULL;

    return t;
}

void makeEmpty(SearchTree t) {
    if (t) { // 递归的释放左右节点的空间
        makeEmpty(t->left);
        makeEmpty(t->right);
        free(t);
    }
}

/**
 * 递归的进行寻找，比该节点大则向右寻找，比该节点小则向左寻找，如果相等就是返回该节点。
 */
Position find(ElementType ele, SearchTree t) {
    if (t) {
        if (t->element == ele) {
            return t;
        }
        if (t->element < ele) { // 比该节点大，从右子树中寻找
            find(ele, t->right);
        } else { // 比该节点小，从左子树中寻找
            find(ele, t->left);
        }
    }
    return NULL;
}

/**
 * 一直向左寻找就是最小的节点
 */
Position findMin(SearchTree t) {
    if (!t) {
        return NULL;
    }
    if (t->left) {
        findMin(t->left);
    } else {
        return t;
    }
}

/**
 * 一直向右寻找就是最大的节点
 */
Position findMax(SearchTree t) {
    if (!t) {
        return NULL;
    }
    if (t->right) {
        findMax(t->right);
    } else {
        return t;
    }
}

/**
 * 插入一个节点和寻找一个节点的思路是相同的
 * 默认我们认为二叉排序树中没有相同的元素
 */
SearchTree insert(ElementType ele, SearchTree t) {
    if (!t) {
        t = createNode(ele);
    } else if (ele < t->element) { // 节点应该放在左面
        t->left = insert(ele, t->left);
    } else {
        t->right = insert(ele, t->right);
    }

    return t;
}

SearchTree array2Tree(ElementType arr[], int len) {
    int i;
    SearchTree t = NULL;
    for (i = 0; i < len; i++) {
        t = insert(arr[i], t);
    }

    return t;
}

/**
 * 删除节点需要注意一点，因为要删除的节点似乎可能有很多的子节点
 *
 * - 如果待删除的节点没有子节点，这个很简单，我们可以直接删除该节点
 * -
 * 如果待删除的节点有一个子节点，我们可以让该节点的父节点绕过该节点，直接和该节点的子节点相连
 *  也就是说，可以直接用该节点的那个子节点替换掉该节点。 t = t->left/right
 * -
 * 如果待删除的节点有两个子节点的话，这是最麻烦的情况，一个最常见的做法是将该节点的右子树的最小的
 *   节点来覆盖该节点，然后删除右子树的最小的节点（该节点是肯定没有左子树的，所以比较容易删除）
 */
SearchTree delEle(ElementType ele, SearchTree t) {
    Position temp;
    if (!t) {
        printf("Error => Element Not found!");
        return;
    }
    if (ele < t->element) {
        t->left = delEle(ele, t->left);
    } else if (ele > t->element) {
        t->right = delEle(ele, t->right);
    } else if (t->left && t->right) { // 被删除的节点有两个子节点
        temp = findMin(t->right);
        t->element = temp->element; // 使用右子树中最小的节点进行替代
        t->right = delEle(t->element, t->right); // 删除右子树中最小的节点
    } else { // 被删除的节点有一个节点或者没有节点
        temp = t;
        if (!t->left) { // 这样写是为了同时处理，当没有节点的情况。
            t = t->right;
        } else if (!t->right) {
            t = t->left;
        }
        free(temp); // 释放删除的那个节点的空间
    }

    return t;
}

/**
 * 获取节点中的值
 */
ElementType retrieve(Position pos) { return pos->element; }

Position left(Position pos) { return pos->left; }

Position right(Position pos) { return pos->right; }

Position setLeft(Position pos, Position left) { pos->left = left; }
Position setRight(Position pos, Position right) { pos->right = right; }
void setValue(Position pos, ElementType ele) { pos->element = ele; }

/**
 * 后序遍历
 */
void suffixTree(SearchTree t) {
    if (t) {
        if (t->left) {
            suffixTree(t->left);
        }
        if (t->right) {
            suffixTree(t->right);
        }
        printf("%d ", t->element);
    }
}

void suffix(SearchTree t) {
    suffixTree(t);
    printf("\n");
}

/**
 * 中序遍历
 */
void infixTree(SearchTree t) {
    if (t) {
        if (t->left) {
            infixTree(t->left);
        }
        printf("%d ", t->element);
        if (t->right) {
            infixTree(t->right);
        }
    }
}

void infix(SearchTree t) {
    infixTree(t);
    printf("\n");
}

/**
 * 前序遍历
 */
void prefixTree(SearchTree t) {
    if (t) {
        printf("%d ", t->element);
        if (t->left) {
            prefixTree(t->left);
        }
        if (t->right) {
            prefixTree(t->right);
        }
    }
}

void prefix(SearchTree t) {
    prefixTree(t);
    printf("\n");
}
