#include "bstree.h"

int main(int argc, char const *argv[]) {
    SearchTree t = insert(6, 0);
    insert(2, t);
    insert(8, t);
    insert(1, t);
    insert(5, t);
    insert(3, t);
    insert(4, t);

    infix(t);
    // delEle(3, t);
    delEle(2, t);
    infix(t); // 测试OK
    return 0;
}
