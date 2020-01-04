#include "stackArr.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define INIT -1
#define SEPARATE 0
#define NUMBER 1
#define OPERATOR 2

/*============== 注意: stackArr.h 中修改定义如下 typedef int ElementType;===============*/
struct StackRecord {
    int capacity;   // =>栈的最大容量
    int topOfStack; // => 栈顶的位置，默认是-1表示栈中没有数据
    ElementType *elements; // => 存放栈元素的数组
};

/*
    中缀表达式，又称为逆波兰表达式，是计算机的主要计算表达方式
    一般我们写的都是中缀表达式
        如 2 * 3 + 4 - 8 / 2 就是一个中缀表达式
        而  6 5 2 3 + 8 * + 3 + * 就是一后缀表达式

    - 如何计算后缀表达式
        需要使用到栈的知识，遇到数字就把数字压入栈中。
        遇到操作符的话就从栈中弹出两个元素然后进行运算，然后将运算的结果放入到栈中。
        最后栈中剩下的唯一的元素就是计算的结果

    可以看到后缀表达式是不要要运算符的优先级的，因而就不需要括号，而且计算机计算起来
    非常的简单，所有计算机的计算都是使用后缀表达式。不过也存在一些问题，
    计算的元素之间需要有东西隔开
    如 6 5 2 3 + 8 * + 3 + *如果去掉空格的话就是6523+8*+3+*根本不知道是啥玩意。
    
    不过放入栈的时候，我们可以直接将char* 放入到字符串中，
   不过最好的还是将其转为int后再放入栈中。

    下面就实现给定合法的后缀表达式的字符串，返回计算出来的值是多少。
*/

// static void forEach2(Stack s) {
//     int i;
//     for (i = 0; i <= s->topOfStack; i++) {
//         printf("%d ", s->elements[i]);
//     }
//     printf("\n");
// }

/**
 * 看来是我傻了，，还想着去空格，却不知我们不是在做十以内的加减法。。。
 */
char *deleteSpace(const char *old) {
    int len = strlen(old);
    char *str = malloc((len + 1) * sizeof(char));
    int cot = 0;
    const char *pos = old;
    while (*pos) {
        if (*pos != ' ') {
            str[cot++] = *pos;
        }
        pos++;
    }
    str[cot] = '\0';
    return str;
}

/**
 * 这是傻掉了，还以为真的就都是十以内加减法
 * 稍微看看就看出来这玩意果然是垃圾啊！！！
 */
/*
int CaluSuffixStr(const char *suffix) {
    const char *newStr = deleteSpace(suffix);
    int len = strlen(newStr) / 2 + 1;
    Stack s = createStack(len);
    const char *pos = newStr;
    char val;
    int left, right;
    while (*pos) {
        val = *pos;
        if (val >= '0' && val <= '9') { // 将数字压入栈中
            push(val, s);
            forEach(s);
        } else {
            right = topAndPop(s) - '0'; // 从栈中取出右操作数
            left = topAndPop(s) - '0';  // 从栈中取出左操作数
            if (val == '+') {           // 计算完成之后开始入栈
                push(left + right, s);
            } else if (val == '-') {
                push(left - right, s);
            } else if (val == '*') {
                push(left * right, s);
            } else if (val == '/') {
                push(left / right, s);
            }
        }
        pos++;
    }
    return topAndPop(s); // 最后栈中剩下的最后的一个数字就是计算的结果
}
*/

/**
 * 将字符串转为int类型的值
 */
static int charToInt(const char *str, int len) {
    const char *pos = str + len - 1;
    int i, base, sum = 0;
    for (i = 0, base = 1; i < len; i++, base *= 10) {
        sum += (*pos-- - '0') * base;
    }
    return sum;
}

static int isOperator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

static int isNum(const char c) { return c >= '0' && c <= '9'; }

/**
 * 重新开始写计算后缀表达式的函数
 * 算法的初步实现，
 * 此时算法只能计算如下形式的后缀表达式
 *      如   "6 14+4/"
 *      特点如下： 元素之间只有一个空格，要么是空格要么是操作符。
 *      下面我们要做的改进这个，使其可以计算任意形式的合法后缀表达式。
 *      如   “  6 5  2 3  + 8  *  +   3 +   * ”
 *      多了很多分隔符号，但是毫无疑问这是可以计算的。
 *
 * @param suffix 后缀表达式字符串
 * @param sep 字符串之间的分隔符
 *
 * @return 计算的结果
 */
int calSuffix(const char *suffix, char sep) {
    int i, j, num;
    int left, right, op;
    Stack s = createStack(strlen(suffix) / 2 + 1);
    for (i = 0, j = 1; suffix[j]; j++) { // 当j遇到了\0是停止，事实上最后一个一定是符号
        if ( i < j && (suffix[j] == sep || isOperator(suffix[j]))) {// 空隔和符号可以用来分隔不同的数字
            num = charToInt(suffix + i, j - i);
            push(num, s);
            // forEach(s);
            i = j + 1;
            while(suffix[i] && !isNum(suffix[i])){ // 如果i没有到字符串的末端并且i指向的不是数字的话
                i++; // i往后移动，寻找下一个数字的位置
            }
        } 
        if (isOperator(suffix[j])) {
            // 从栈中取出两个操作数
            right = topAndPop(s);
            left = topAndPop(s);
            
            op = suffix[j];
            if (op == '+') { // 计算完成之后开始入栈
                push(left + right, s);
            } else if (op == '-') {
                push(left - right, s);
            } else if (op == '*') {
                push(left * right, s);
            } else if (op == '/') {
                push(left / right, s);
            }
            // forEach(s);
        }
    }
    // forEach(s);
    return topAndPop(s);
}

/**
 * 解决上面所说的空格问题，其实解决的方案很简单，将目标字符串变成我们上面可以解决的那种格式就行了
 * 这个在数学上好像是叫做化归思想吧。将不会做的问题转化成会做的问题。
 * 总体的思路如下：
 *   我们只可以在数字的后面加入空格
 *   如果我们加上了空格却发现之后发现了操作符，那么要用操作符替换这个空格
*/
int calSuffixPlus(const char* suffix, const char sep){
    int len = strlen(suffix);
    char* newSuffix = malloc((len + 1)*sizeof(char));
    int status = INIT; // 表示上一个放入到新字符串中的是什么类型的数据 每次放入的时候都要改变数据类型
    int cot = 0; // 新字符串待放字符的位置
    char val;
    int i;
    for (i = 0; i < len; i++){
        val = suffix[i];
        if (isNum(val)){
            newSuffix[cot++] = val;
            status = NUMBER;
            continue;
        }
        if (status == NUMBER && val == sep){
            newSuffix[cot++] = val;
            status = SEPARATE;
            continue;
        }
        if ((status == NUMBER || status == OPERATOR) && isOperator(val)){
            newSuffix[cot++] = val;
            status = OPERATOR;
            continue;
        }
        if (status == SEPARATE && isOperator(val)){ // 使用操作符替换掉空格
            newSuffix[cot-1] = val;
            status = OPERATOR;
            continue;
        }
    }

    newSuffix[cot] = '\0';
    // printf("%s\n", newSuffix);

    return calSuffix(newSuffix, sep);
}

int main() {
    const char *suffix = "12 322+777*23 11/-";
    printf("%s\n%d\n", suffix, calSuffix(suffix, ' '));
    return 0;
}
