## 第三章 习题 3-11

### 问题描述
分别使用递归和非递归的方式寻找单链表中的特定的元素，并比较这两种方法的运行时间。当单链表中的有
多少元素的时候，使用递归的方式查找元素会崩溃？

### 问题分析
感觉应该是很简单的亚子。

**难度系数： 0**

---

### 我的答案
**当数组的大小是3000时**
> no recursion result => 1666  
> Running Time: 0ms  
> recursion result => 1666  
> Running Time: 0ms  

**当数组的大小为30000时**
> no recursion result => 16666  
> Running Time: 0ms  
> recursion result => 16666  
> Running Time: 2ms

**当数组大小为300000时**
> no recursion result => 16666  
> Running Time: 0ms

此时使用递归的查找方式崩溃了，估计着也该是栈溢出了

### 结论
这种情况下使用递归即慢还浪费空间，纯属没有意义。（递归一时爽，一直递归一直爽！）