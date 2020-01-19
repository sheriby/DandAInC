/**
 * Depth First Search of binary tree(DFS)
 *
 * Traversal the tree depth first
 *
 * Unlike Broad First Search, it will use data structure `Stack` in DFS.
 * When we visit a node, push its right childen and left children into stack in
 * order. And then we pop the stack which will return a new node as the next
 * visit node.
 */

#include "bstree.h"
#include "stackArr.h"
#include <stdio.h>

void dfs(SearchTree t) {
    Stack s = createStack(10); // we can assign stack capacity dynamic
    push(t, s);
    Position p = NULL;
    while (!isEmpty(s)) {
        p = topAndPop(s);
        printf("%d ", retrieve(p));
        if (right(p)) {
            push(right(p), s);
        }
        if (left(p)) {
            push(left(p), s);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0};
    SearchTree t = array2Tree(arr, 10);
    dfs(t);
    return 0;
}