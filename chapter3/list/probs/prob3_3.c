/**
 * 习题3-3， 通过只调整指针的值，交换两个相邻的元素
 * 
 * 难度系数： 0
*/

#include "..\list.h"
#include <stdio.h>

/**
 * 给定位置的节点和该节点的前驱节点，使得该节点和其下一个节点的位置进行交换
*/
void exchangeAfter(Position pre, Position pos, List list){
    Position next = advance(pos);
    Position nnext = advance(next);
    setNext(pre, next, list);
    setNext(next, pos, list);
    setNext(pos, nnext, list);
}

/**
 * 给定位置的节点和该节点的前驱节点，使得该节点和其下一个节点的位置进行交换
*/

void exchange(Position pos, List list){
    exchangeAfter(findPrevious(retrieve(pos), list), pos, list);
}


int main(void){
    int arr[] = {1, 2, 3, 4, 5};
    List list = arrayTolist(arr, 5);

    printList(list);
    Position pos = advance(advance(list));
    exchange(pos, list);
    printList(list);

    return 0;
}