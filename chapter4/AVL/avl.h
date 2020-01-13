/**
 * Stupid idea to create avl.h
 * We just need to create function 'toAvl' in class bstree, and in correct time call 
 * this function and make it became avl tree RATHER THAN create stupid class avl and 
 * rotate node when we insert and delete!
 * Fucking stupid idea that I cannot understand.
*/

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

Position createNode(ElementType ele, int height);
AvlTree array2Tree(ElementType arr[], int len);
void makeEmpty(AvlTree t);
Position find(ElementType ele, AvlTree t);
Position findMin(AvlTree t);
Position findMax(AvlTree t);
AvlTree insert(ElementType ele, AvlTree t);
AvlTree delEle(ElementType ele, AvlTree t);
ElementType retrieve(Position pos);
int height(Position pos);

Position left(Position pos);
Position right(Position pos);

Position setLeft(Position pos, Position left);
Position setRight(Position pos, Position right);
void setValue(Position pos, ElementType ele);

void infix(AvlTree t);
void prefix(AvlTree t);
void suffix(AvlTree t);


#endif