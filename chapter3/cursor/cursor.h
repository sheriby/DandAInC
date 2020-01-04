#ifndef _CURSOR_H_
#define _CURSOR_H_

// 使用游标来模拟链表（很多语言都是无法使用指针的，但是需要使用链表就需要使用数组来模拟链表的操作）

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
typedef int ElementType;

void initializeCursorSpace(void);

void printList(List list);
List makeEmpty(List list);
int isEmpty(List list);
int isLast(Position pos, List list);
Position find(ElementType x, List list);
void deleteEle(ElementType x, List list);
Position findPrevious(ElementType x, List list);
void insert(ElementType x, List list, Position pos);
void deleteList(List list);
Position header(List list);
Position first(List list);
Position advance(Position pos);
ElementType retrieve(Position p);


#endif // _CURSOR_H_
