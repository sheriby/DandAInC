/**
 * 广度优先搜索(BFS Broad First Search)
 *
 * 广度优先搜索在树的层面就是层序遍历一层接着一层的遍历。要求遍历的广度而不是遍历的深度。
 * 广度优先搜索需要使用到栈的结构
 */
#include "queue.h"
#include "bstree.h"
#include <stdio.h>

void bfs(SearchTree t) {
    Queue q = createQueue(10); // 这个栈的大小后面可以按需改
    SearchTree p = NULL;
    enqueue(t, q);
    while (!isEmpty(q)) {
        p = frontAndDeQueue(q);
        printf("%d ", retrieve(p));
        if (left(p)){
            enqueue(left(p), q);
        }
        if (right(p)){
            enqueue(right(p), q);
        }
    }   
}

int main(int argc, char const *argv[]) {
    int arr[] = {5, 1, 6, 2, 7, 3, 8, 4, 9, 0};
    SearchTree t = array2Tree(arr, 10);
    bfs(t);
    return 0;
}
