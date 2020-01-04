#include "stackArr.h"
#include <malloc.h>
#include <stdio.h>

// typedef char ElementType;
/**
 * 将一个中缀表达式转换成为一个后缀表达式
 * 之前我们已经实现了后缀表达式的计算，现在我们只需要将中缀表达式转换成为后缀表达式
 * 就可以实现对中缀字符串表达式的计算
 * 如 (a + b) * c / (d - e) * f => a b + c * d e - / f *
 *
 * 将中缀表达式转成后缀表达式同样需要使用栈结构
 *
 * 举例 将 (2+3)*7-2 转换成后缀表达式，我们可以很容易的看出答案是 2 3+7*2-
 * 可以看到数字的顺序是固定的，我们只需要操作符的位置就行了
 * 解决问题的思路如下：
 * 遇到数字 =》 直接输出
 * 遇到操作符号 观察栈顶的操作符，如果是否优先级大于或等于自己。（优先级 括号 >
 * /* > +-）
 *            ======》 如果大于等于自己，那么栈顶元素出栈输出。重复上一步。
 *            ======》 如果发现栈顶的是左括号，直接入栈。
 * 左括号只有遇到右括号才会出栈，遇到右括号的时候，右括号上所有的元素出栈
 *
 * 如 (2+3)*7-2
 * 输出 2
 * 栈 (
 * 输出 2 3
 * 栈 ( +
 * 输出 2 3
 * 栈 ( + ) => 弹出 + 输出 2 3 +
 * 输出 2 3 +
 * 栈 *
 * 输出 2 3 + 7
 * 栈 * -   => 弹出 * 输出 2 3 + 7 *
 * 输出 2 3 + 7 * 2
 * 栈 -
 * 结束了 将栈中元素一次弹出输出
 * 结果： 2 3 + 7 * 2 -
 */

/**
 * 自己写的一个简单的strlen
 */
static int mystrlen(const char *str) {
    int cot = 0;
    while (*str++) {
        cot++;
    }
    return cot;
}

static int isNum(const char c) { return c >= '0' && c <= '9'; }

static int isOperator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int priority(const char c) {
    if (c == '('){
        return -1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '+' || c == '-') {
        return 1;
    }
}


/**
 * 将一个中缀表达式转为一个后缀表达式
 * @param infix 中缀表达式字符串
 * @param sep 分隔符
 * @return 转换完成的后缀表达式
 *          经过我们的特殊的处理，现在我们转换之后的后缀表达式是如下的形式 2 3+7*2-
 */
static char *infix2Suffix(const char *infix, const char sep) {
    int len = mystrlen(infix);
    char *suffix = malloc((2 * len * sizeof(char)));
    Stack s = createStack(len);
    int cot = 0; // suffix中字符个数
    int beforeIsNum = 1;// 用来判断，数字是否是连续的，也就是说添加数字前是否要添加分隔符
    const char *pos = infix;
    char val, op, topOp;
    while (*pos) {
        val = *pos++; // 使用for似乎更容易理解。 因为后面要使用continue所有提前往后跳转
        if (isNum(val)) {
            if (!beforeIsNum && !isOperator(suffix[cot-1])){ // 如果前面是符号的话，不必加空格
                suffix[cot++] = sep; // 为不同的数字进行间隔
            }
            
            suffix[cot++] = val;
            beforeIsNum = 1;
            continue;
        }
        beforeIsNum = 0;
        if (isOperator(val)) {
            // printf("%c ====\n", val);
            if (isEmpty(s) || val == '(') {
                push(val, s); // 如果栈空直接入栈 如果是左括号也是直接入栈
                continue;
            }
            if (val == ')') { // 遇到了右括号直接将两个括号之间的全部出栈
                op = topAndPop(s);
                while (op != '(') {
                    suffix[cot++] = op;
                    op = topAndPop(s);
                }
                continue;
            }
            topOp = top(s); // 返回栈顶的操作符
            while (!isEmpty(s) && priority(topOp) >= priority(val) ){ // 栈顶的操作符大于自己
                suffix[cot++] = topAndPop(s); // 出栈输出
                topOp = top(s);
            }
            push(val, s); // 入栈
        }

    }
    while(!isEmpty(s)){ // 将栈中剩余的元素输出
        suffix[cot++] = topAndPop(s);
    }
    suffix[cot] = '\0';
    
    return suffix;
}

int main() {
    const char* infix = "(12 + 322) * 777 - 23/   11";
    /*
        本来是打算，将两个功能合在一起的，但是发现还是有点儿麻烦的，，两个栈中我们一个使用的是存放
        char 一个是存放 int 虽然说两者都是整型变量，可以统一使用int，
        但是我定义了很多重名的函数，，emm，，虽然使用了static函数，但是还是冲突了，不知道为啥
        就这样吧，经过验算，这两个功能都算是完成了。
    */
    // const char* suffix = infix2Suffix(infix, ' ');
    // int res = calSuffix(suffix, ' ');
    // printf("infix is %s\nsuffix is %s\nres is %d", infix, suffix, res);

    printf("suffix is %s\n", infix2Suffix(infix, ' '));
    return 0;
}
