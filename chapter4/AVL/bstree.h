/**
 * 二叉查找树，又称二叉搜索树。(Binary Search Tree)
 * 每一个节点的左子节点都小于该节点，每一个节点的右子节点都大于该节点，满足这样的树就是二叉查找树。
 * 不过需要注意的是，左面的最大的节点也要小于二叉查找树的根节点。
 *
 * 下面是二叉查找树的ADT
 */
#ifndef _BSTREE_H_
#define _BSTREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

Position createNode(ElementType ele);
SearchTree array2Tree(ElementType arr[], int len);
void makeEmpty(SearchTree t);
Position find(ElementType ele, SearchTree t);
Position findMin(SearchTree t);
Position findMax(SearchTree t);
SearchTree insert(ElementType ele, SearchTree t);
SearchTree delEle(ElementType ele, SearchTree t);
ElementType retrieve(Position pos);

Position left(Position pos);
Position right(Position pos);

Position setLeft(Position pos, Position left);
Position setRight(Position pos, Position right);
void setValue(Position pos, ElementType ele);

void infix(SearchTree t);
void prefix(SearchTree t);
void suffix(SearchTree t);

#endif