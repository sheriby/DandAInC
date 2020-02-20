/**
 * 通过一个表达式构建一颗树
 *
 * 其中树枝是操作符，树叶是操作数。
 * 这里所说的操作符是+ - * / 这种二元操作符，所以构造出来的是一颗二叉树。
 *
 * 给定表达式
 * a b + c d e + * *
 * 这是一个后缀表达式。
 */
#include "stackArr.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

PtrToNode createTreeNode(ElementType2 ele) {
    PtrToNode node = malloc(sizeof(struct TreeNode));
    node->element = ele;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isOper(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }
Tree buildTree(const char expr[]) {
    // 使用栈结构帮助构建表达式树
    int len = strlen(expr);
    Stack s = createStack(len);
    PtrToNode node;
    PtrToNode left, right;
    int i;
    for (i = 0; i < len; i++) {
        if (!isOper(expr[i])) {
            node = createTreeNode(expr[i]);
            push(node, s);
        } else {
            right = topAndPop(s);
            left = topAndPop(s);
            node = createTreeNode(expr[i]);
            node->left = left;
            node->right = right;
            push(node, s);
        }
    }

    return topAndPop(s);
}

void suffixTree(Tree t) {
    if (t) {
        if (t->left) {
            suffixTree(t->left);
        }
        if (t->right) {
            suffixTree(t->right);
        }
        printf("%c", t->element);
    }
}

void infixTree(Tree t) {
    if (t) {
        if (t->left) {
            infixTree(t->left);
        }
        printf("%c", t->element);
        if (t->right) {
            infixTree(t->right);
        }
    }
}

void prefixTree(Tree t) {
    if (t) {
        printf("%c", t->element);
        if (t->left) {
            prefixTree(t->left);
        }
        if (t->right) {
            prefixTree(t->right);
        }
    }
}

int main(int argc, char const *argv[]) {
    const char expr[] = "ab+cde+**"; // 现就不考虑格式的问题了
    Tree t = buildTree(expr);
    suffixTree(t); // ab+cde+** 后缀表达式 逆波兰表达式
    printf("\n");
    infixTree(t); // a+b*c*d+e 中缀表达式 
    printf("\n");
    prefixTree(t); // *+ab*c+de 前缀表达式 波兰表达式
    return 0;
}

/*
    由此可见，通过树和栈的的结合，我们也可以将后缀表达式转换成为其他形式的表达式。
*/
