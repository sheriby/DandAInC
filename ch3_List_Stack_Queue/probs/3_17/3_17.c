#include <malloc.h>
#include <stdio.h>

struct Node;
typedef struct Node *Position;
typedef struct Node {
    int data;
    int isDel; // 表示是否被标记为删除
    Position next;
} Node;

typedef struct {
    int delNum; // 被标记为删除的节点的数量
    int length; // 总的节点的数量
    Position next;
} ListNode, *List;

List createList() {
    List list = malloc(sizeof(ListNode));
    list->delNum = 0;
    list->length = 0;
    list->next = NULL;

    return list;
}

void printList(List list) {
    Position pos = list->next;
    if (!pos) {
        printf("Empty List!");
        return;
    }
    printf("list => [");
    while (pos->next) {
        printf("%d(%d), ", pos->data, pos->isDel);
        pos = pos->next;
    }
    printf("%d(%d)]\n", pos->data, pos->isDel);
    printf("DelNum => %d\nLength => %d\n", list->delNum, list->length);
}

void insert(List list, int val) {
    Position node = malloc(sizeof(Node));
    node->data = val;
    node->isDel = 0;
    node->next = NULL;

    if (list->next == NULL) {
        list->next = node;
        list->length++;
        return;
    }
    Position pos = list->next;
    while (pos->next) {
        pos = pos->next;
    }
    pos->next = node;
    list->length++;
}

/**
 * 对标记的节点进行删除
 */
void fullDel(List list) {
    Position delNode;
    if (!list->next) { // 列表中没有元素
        return;
    }

    // 找到头部后面第一个不是被清理的节点。
    while (list->next && list->next->isDel) {
        delNode = list->next;
        list->next = delNode->next;
        free(delNode);
        list->delNum--;
        list->length--;
    }
    if (!list->next) {
        return;
    }

    // 为嘛要做上面的那个操作呢？？
    // 主要是因为我设置的头结点和普通的节点不是一个数据类型的。。。所以需要上面的那一步

    Position pos = list->next; // 此时这个不是被清理的
    printf("%d\n", pos->data);
    while (pos->next) {
        if (pos->next->isDel) {
            delNode = pos->next;
            pos->next = delNode->next;
            free(delNode);
            list->delNum--;
            list->length--;
        } else {
            pos = pos->next;
        }
    }
}

/**
 * 对节点删除进行标记
 */
void del(List list, int val) {
    Position pos = list->next;
    while (pos) {
        if (pos->data == val && !pos->isDel) { // 这个节点不能是被比较为删除的节点
            pos->isDel = 1;
            list->delNum++;

            if (list->delNum * 2 >= list->length) {
                fullDel(list); // 真正对元素进行清理
            }
            return;
        }
        pos = pos->next;
    }
}

int main(int argc, char const *argv[]) {
    List list = createList();
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    insert(list, 5);
    insert(list, 6);
    insert(list, 7);
    insert(list, 8);
    insert(list, 9);

    printList(list);

    del(list, 5);
    del(list, 3);
    printList(list);

    del(list, 9);
    del(list, 5);
    del(list, 1);
    del(list, 2);
    printList(list);

    return 0;
}
