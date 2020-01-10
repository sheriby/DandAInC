## 数据结构 ———— 树

这里我们主要探讨的就是二叉树。

树这种结构和我们之前学的数组链表队列和栈是很不一样的。树是一种非常重要的数据结构，但是树没有一个标准的
ADT，告诉我们树应该是实现哪些函数，哪些功能什么的，同样的在C++中也没有所谓的`tree.h`这种头文件。没有ADT意味
着树的应用是非常的广泛的，对于排序有排序二叉树，对于搜索有搜索二叉树。。。等等等。

树在数据结构和算法中起到的功能，不可谓不大，也是比较难以掌握的一种数据结构。

一般来说，树的节点声明如下。

```c
    typedef int ElementType;
    struct TreeNode;
    typedef struct TreeNode *PtrToNode;
    typedef PtrToNode Tree;

    typedef struct TreeNode{
        ElementType element;
        Tree left;
        Tree right;
    }TreeNode;
```

树中一般是一个数据域，两个指针域。和双向链表在结构上一点儿相似，但是完全不一样。