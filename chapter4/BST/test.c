#include "bstree.h"

int main(int argc, char const *argv[]) {
    // SearchTree t = insert(6, 0);
    // insert(2, t);
    // insert(8, t);
    // insert(1, t);
    // insert(5, t);
    // insert(3, t);
    // insert(4, t);
    int arr[] = {1, 2, 3, 4, 5, 6};
    SearchTree t = array2Tree(arr, 6);
    infix(t);
    // delEle(3, t);
    delEle(2, t);
    infix(t); // 测试OK
    return 0;
}
