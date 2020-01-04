#include "cursor.h"

/**
 * 在链表的指针有以下的两个重要的特性。
 *  - 数据存储在一组结构体中，
 *      每一个结构中包含存储的数据和指向下一个结构体的指针。
 *  - 一个新的结构体可以调用malloc而从系统内存中得到，
 *      并且可以调用free而释放。
 */

struct Node {
    ElementType element;
    Position next;
};

struct Node cursorSpace[10]; // 用来分配空间，这里最多只可以分配十个结构体
/**
 * 这十个空间一开始串成一个圈的，
 * 如他们对应的编为分别是     0 1 2 3 4 5 6 7 8 9
 * 他们的下一个结构体值分别是  1 2 3 4 5 6 7 8 9 0 (next值)
 *
 * 当结构体位于表头->表头的这个循环中的时候就是可以分配的，当不在的时候就是分配
 * 出去的空间。
 * 当没有内存空间可以分配的时候， 表头->next =
 * 表头，也就是这个循环中没有其他的元素了。
 * 我感觉表头这个东西应该是不可以被分配出去的吧。
 */

/**
 * 相当于链表的malloc，
 * 每次都取表头后面的第一个元素，当没有元素时（内存空间不足是），表头后面没有元素。
 */
static Position cursorAlloc(void) {
    Position pos;

    pos = cursorSpace[0].next;
    cursorSpace[0].next = cursorSpace[pos].next;

    return pos;
}

/**
 * 相当于链表的free， 将元素放到表头的后面，这样下次malloc就可以取到这个元素了
 */
static void cursorFree(Position pos) {
    cursorSpace[pos].next = cursorSpace[0].next;
    cursorSpace[0].next = pos;
}

/**
 * 判断表是否为空
 */
int isEmpty(List list) { return cursorSpace[list].next == 0; }

/**
 * 判断节点是否是最后一个节点
 */
int isLast(Position pos, List list) { return cursorSpace[pos].next == 0; }

/**
 * 返回与目标元素从左到右第一个匹配的位置
 */
Position find(ElementType ele, List list) {
    Position pos;
    pos = cursorSpace[list].next;

    while (pos && cursorSpace[pos].element != ele) {
        pos = cursorSpace[pos].next;
    }
    return pos;
}

/**
 * 返回匹配到目标元素的前一个位置
 */
Position findPrevious(ElementType ele, List list) {
    Position pos;
    pos = &cursorSpace[list];

    while (cursorSpace[pos].next &&
           cursorSpace[cursorSpace[pos].next].element != ele) {
        pos = cursorSpace[pos].next;
    }
    return pos;
}

/**
 * 删除匹配到的元素
*/
void deleteEle(ElementType ele, List list) {
    Position pos, temp;
    pos = cursorSpace[list].next;

    pos = findPrevious(ele, list);

    if (!isLast(pos, list)) {
        temp = cursorSpace[pos].next;
        cursorSpace[pos].next = cursorSpace[temp].next;
        cursorFree(temp);
    }
}

/**
 * 在对应的位置后面插入给定的元素
*/
void insert(ElementType ele, List list, Position pos){
    Position next = cursorSpace[pos].next;
    Position newNode = cursorAlloc();
    cursorSpace[newNode].element = ele;
    cursorSpace[pos].next = newNode;
    cursorSpace[newNode].next = next;
}