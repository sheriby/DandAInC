#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    ElementType element;
    Position next;
};
int main() {
    List list = (List)malloc(sizeof(struct Node));
    PtrToNode node1 = (List)malloc(sizeof(struct Node));
    PtrToNode node2 = (List)malloc(sizeof(struct Node));
    PtrToNode node3 = (List)malloc(sizeof(struct Node));
    list->next = node1;
    node1->element = 3;
    node1->next = node2;
    node2->element = 5;
    node2->next = node3;
    node3->element = 11;
    node3->next = NULL;

    // printf("is empyt: %d\n", isEmpty(list));
    printList(list);
    delete(5, list);
    printList(list);
    getchar();
    return 0;
}
