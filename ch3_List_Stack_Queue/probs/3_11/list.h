#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;


List arrayTolist(ElementType arr[], int len);
List createList();
void printList(List list);
List makeEmpty(List list);
int isEmpty(List list);
int isLast(Position pos, List list);
Position find(ElementType x, List list);
void delete(ElementType x, List list);
Position findPrevious(ElementType x, List list);
Position findPreviousByAddr(Position pos, List list);
void insert(ElementType x, List list, Position pos);
void deleteList(List list);
Position header(List list);
Position first(List list);
Position advance(Position pos);
ElementType retrieve(Position p);
void setNext(Position p, Position next, List list);
ElementType* elementAddr(Position p, List list);

Position findMid(List list);

#endif // _LIST_H_

