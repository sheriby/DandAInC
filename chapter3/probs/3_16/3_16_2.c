/**
 * 使用链表实现
 */

#include "list.h"
#include <malloc.h>

Position deleteNext(List list, Position pos) {
    Position del = advance(pos);
    Position next = advance(del);
    setNext(pos, next, list);
    free(del);
    return next;
}

void duplicateRemove(List list) {
    Position pos = advance(list);
    Position ppos;
    Position pprev;
    while (pos) {
        pprev = pos;
        ppos = advance(pos);
        while (ppos) {
            if (retrieve(ppos) == retrieve(pos)) {
                ppos = deleteNext(list, pprev);
                continue;
            }
            pprev = advance(pprev);
            ppos = advance(ppos);
        }
        pos = advance(pos);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 3, 5, 3, 1, 2, 6, 7, 5, 6};
    List list = arrayTolist(arr, 10);
    printList(list); // list: [1, 3, 5, 3, 1, 2, 6, 7, 5, 6]
    duplicateRemove(list);
    printList(list); // list: [1, 3, 5, 2, 6, 7]
    // 测试OK

    return 0;
}
