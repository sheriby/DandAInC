## 第三章 习题 3-15

### 问题描述

1. 写出自调整(`self-adjusting`)表的*数组*实现。自调整表如同一个规则的表，但是所有的插入都在表头进行，当一个元素被`Find`访问时，它就被移到表头而不改变其余项的相对顺序。
2. 写出自调整表的链表实现
3. 设每个元素都有其被访问的固定概率*pi*。证明那些具有最高访问概率的元素都靠近表头。

### 个人想法
先就假设我们需要根据学生的ID，访问学生的信息吧，不然都不知道表中要放些什么东西，光放一个数字感觉也蛮尴尬的。

### 我的答案
使用数组实现实在是有点儿蛋疼的，不过我也还是写了，但是没有测试。这个东西经常插入和删除，使用链表来实现才是最好的
吧，而且还蛮简单的。