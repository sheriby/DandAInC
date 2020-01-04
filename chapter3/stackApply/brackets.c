#include "stackArr.h"
#include <stdio.h>
#include <string.h>

struct StackRecord {
    int capacity;   // =>栈的最大容量
    int topOfStack; // => 栈顶的位置，默认是-1表示栈中没有数据
    ElementType *elements; // => 存放栈元素的数组
};

void forEach(Stack s) {
    int i;
    for (i = 0; i <= s->topOfStack; i++) {
        printf("%c ", s->elements[i]);
    }
    printf("\n");
}

/*
    平衡符号问题，给定一个字符串，判断字符串是否是合法的。
*/

/**
 * 检测给定的含有的表达式中的括号是否是合法的，算法如下：
 * 如果遇到的是一个开放型括号如 ( [ { 那么就将这个符号入栈。
 * 如果遇到的是一个封闭型符号如 ) ] }，那么检查栈是否为空，
 *      如果为空就说明表达式不合法，
 *      不为空弹出栈顶的元素，如果与目标元素不匹配，那么也还是不合法
 *
 * @param brackets 一个表达式字符串 如(a+b)*{a-(b*c)/[a-(c+b)]}
 * @param len 字符串的长度
 */
int isValidBracket(const char *brackets) {
    int len = strlen(brackets);
    const char *pos = brackets;
    char val, temp;
    Stack s = createStack(len / 2);

    while (*pos) {
        val = *pos;
        if (val == '(' || val == '[' || val == '{') {
            push(val, s); // 开放型符号入栈,
                          // 不考虑栈满的情况，因为上面已经分配了足够的空间
        } else if (val == ')' || val == ']' || val == '}') {
            if (isEmpty(s)) {
                return 0;
            } else {
                temp = topAndPop(s);
                // 如果符号不匹配则返回假
                if (val == ')' && temp != '(') {
                    return 0;
                } else if (val == ']' && temp != '[') {
                    return 0;
                } else if (val == '}' && temp != '{') {
                    return 0;
                }
            }
        }
        pos++;
    }
    // 如果此时栈中还是有括号（此时只可以有开放型括号），也是一个不合法的表达式
    int res = isEmpty(s);
    disposeStack(s); // 要清除栈空间，防止内存泄漏
    return res;
}

/*
    问题的扩展，在数学里面似乎括号是具有优先级的。比如{[()]}这样的括号是合法的，
    但是({[]})这样的括号却是非法的，在这个模式下又该如何进行正确的匹配呢？

    思路分析：
    首先去掉右面的括号观察
   ({[是不合法的，因为{的优先级是大于(的，但是不是所有的情况下都是这样的 如
   (){[]}去掉右括号也是({[却是合法的。因为(在大括号进来的时候已经出栈了。
    我们在每次入栈的时候检查一下栈顶的优先级是否大于自己的优先级（等于也是合法的），如果大于或等于就是合法，
    如果小于就是非法的
    如果入栈的时候栈是空的，那么直接入栈就完事了
*/

int isValidBracketEx(const char *brackets) {
    int len = strlen(brackets);
    const char *pos = brackets;
    char val, temp;
    Stack s = createStack(len / 2);

    while (*pos) {
        val = *pos;
        if (val == '(' || val == '[' || val == '{') {
            temp = top(s);
            //主要看入栈的时候
            if (isEmpty(s) || val == '(') { // 栈空直接入栈就完事了
                push(val, s);
            } else {            // 栈不是空才进行判断
                temp = top(s);
                // 小括号放入一直都是合法的
                if (val == '[' && temp == '(') { // 中括号前面不能是小括号
                    return 0;
                } else if (val == '{' && temp != '{') { //大括号前面只能是大括号
                    return 0;
                }
                // 括号合法入栈
                push(val, s);
            }
        } else if (val == ')' || val == ']' || val == '}') {
            if (isEmpty(s)) {
                return 0;
            } else {
                temp = topAndPop(s);
                // 如果符号不匹配则返回假
                if (val == ')' && temp != '(') {
                    return 0;
                } else if (val == ']' && temp != '[') {
                    return 0;
                } else if (val == '}' && temp != '{') {
                    return 0;
                }
            }
        }
        pos++;
    }
    // 如果此时栈中还是有括号（此时只可以有开放型括号），也是一个不合法的表达式
    int res = isEmpty(s);
    disposeStack(s); // 要清除栈空间，防止内存泄漏, 不过上面返回的时候都没有做这方面的工作
    return res;
}

int main() {
    const char *str = "(a+b)*{a-(b*c)/[a-(c+b)]}";
    printf("this expression %s is %s!\n", str,
           isValidBracketEx(str) ? "valid" : "invalid");
    return 0;
}