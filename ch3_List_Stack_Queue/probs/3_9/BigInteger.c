#include "BigInteger.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

int isNum(const char i) {
    if (i <= '9' && i >= '0') {
        return 1;
    }
    return 0;
}

int isValidInteger(const char *i) {
    while (*i) {
        if (!isNum(*i)) {
            return 0;
        }
        i++;
    }
    return 1;
}

void printInteger(BigInteger i) { printf("Integer => %s\n", i); }

BigInteger string2Integer(const char *i) {
    if (!isValidInteger(i)) {
        return NULL;
    }
    int len = strlen(i);
    BigInteger b = malloc((len + 1) * sizeof(char));
    strcpy(b, i);
    return b;
}

BigInteger bitInteger(int bit) {
    BigInteger b = malloc((bit + 1) * sizeof(char));
    b[bit] = '\0';
    return b;
}

char intNum2Char(const int i) { return i + '0'; }
int charNum2Int(const char i) { return i - '0'; }

/**
 * 数字转字符串这里就直接使用sprinf函数了，之前也写过了好多次这种东西了。
 */
BigInteger int2Integer(const int i) {
    char *buf = malloc((11) * sizeof(char));
    sprintf(buf, "%d", i);
    return buf;
}

int lenInteger(BigInteger i) { return strlen(i); }

/**
 * 两个字符相加 如 '1' + '4' => '5'
 * @param res 计算的结果
 *
 * @return 是否需要进位 如 '5' + '7' => '2' 返回值是1，说明需要进位
 *
 * 关于将计算的结果作为返回值还是是否进位作为返回值，我想了很多，最终还是认为将
 * 是否进位作为返回值更好...(其实都差不多)
 */
int bitAdd(const char i, const char j, char *res) {
    char r = i + j + *res - 3 * '0';
    if (r > 9) {
        r -= 10;
        *res = r + '0';
        return 1; // 产生了进位
    }
    *res = r + '0';
    return 0; // 没有进位
}

/**
 * 两个大整数相加
 */
BigInteger addInteger(BigInteger l, BigInteger r) {
    int lenl = lenInteger(l);
    int lenr = lenInteger(r);
    int maxlen = lenl > lenr ? lenl : lenr;

    BigInteger result = bitInteger(maxlen + 1);
    int pres = maxlen; // 指向最低位

    int p = lenl - 1;
    int q = lenr - 1; // 都指向数组的最后一位，也就是个位
    int inc = 0;      // 是否进位的标识
    char res;
    char left, right;
    int i;
    for (i = 0; i < maxlen; i++) {
        if (inc) {
            res = '1';
        } else {
            res = '0';
        }
        left = p == -1 ? '0' : l[p--];
        right = q == -1 ? '0' : r[q--]; // 不足的补全位数
        // printf("%c == %c", left, right);

        inc = bitAdd(left, right, &res);
        // printf("==> %c\n", res);
        result[pres--] = res;
    }

    if (inc) {
        result[pres--] = '1';
    } else {                        // 第一位没有用到
        strcpy(result, result + 1); // 整体向左来一位
    }

    return result;
}

/**
 * 两个大整数相乘
 * 一个M位的数和一个N位的数相乘得到的整数最多是M+N位, 最少是M+N-1位。
 *
 * 乘法和加法其实是有点像的，我们正常在加法的时候的思路就是将上面的那个与下面的一个个位相乘，
 * 然后就行累加
 * 我们这里其实也可以使用这个思路
 */
int bitMul(char a, char b, int base, int *res) {
    a -= '0';
    b -= '0';
    int val = a * b + base;
    int inc = val / 10; // 要进位的值
    *res = val % 10;    // 计算的结果
    return inc;
}
BigInteger mulIntegerBit(BigInteger l, const char i) {
    int len = lenInteger(l);
    BigInteger result = bitInteger(len + 1);
    int pres = len; // 指向数字的末尾
    int p = len - 1;
    int res;
    int base = 0;
    while (p != -1) {
        base = bitMul(l[p--], i, base, &res);
        result[pres--] = intNum2Char(res);
    }
    result[pres--] = intNum2Char(base);
    if (pres == 0) {
        strcpy(result, result + 1);
    }
    return result;
}

/**
 * 相当于十进制中的 << 扩大十倍
 */
BigInteger shiftLeft(BigInteger b, int n) {
    int len = lenInteger(b);
    BigInteger result = bitInteger(len + n);
    strcpy(result, b);
    int i;
    for (i = len; i < len + n; i++) {
        result[i] = '0';
    }
    return result;
}

BigInteger mulInteger(BigInteger l, BigInteger r) {
    if (l > r) {
        return mulInteger(r, l);
    }
    BigInteger result = int2Integer(0);
    int p = lenInteger(l) - 1;
    int i = 0;
    while (p != -1) {
        BigInteger t = mulIntegerBit(r, l[p--]);
        result = addInteger(result, shiftLeft(t, i++));
    }
    if (*result == '0') {
        strcpy(result, result + 1);
    }
    return result;
}

BigInteger copyInteger(BigInteger i) {
    int len = lenInteger(i);
    BigInteger res = bitInteger(len);
    strcpy(res, i);
    return res;
}
/**
 * 思路应该还是之前的那个pow算法,
 * 这里我的i没有设置为大整数，如果是的话，那是真滴大！！
 * 可能是我的电脑算不出来的大
 */
BigInteger powInteger(BigInteger l, int i) {
    if (i == 0) {
        return string2Integer("0");
    }
    if (i == 1) {
        return copyInteger(l);
    }
    if (i & 1) {
        return mulInteger(powInteger(mulInteger(l, l), i / 2), l);
    } else {
        return powInteger(mulInteger(l, l), i / 2);
    }
}
