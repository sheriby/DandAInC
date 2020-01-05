/**
 * prob 3.9 实现任意精度的整数运算包，就像之前完成的链表多项式一样，并计算2^2000中数字
 * 0-9的分布情况
 * 
 * 虽然题目中说这个和链表多项式一样，但是这似乎一点都不一样好嘛。。。这个题目我们大一的时候就已经
 * 做过了，当时是写的一个BigInteger的东西，但是当时写的那个玩意，肯定是垃圾中的垃圾。。。
 * 
 * 对比其他的语言, Java中有BigDecimal, Python已经可以直接print(2**2000)， C/C++的标准库
 * 中现在似乎都还没有大数据的处理，可能是真的没有必要吧~~~
 */

#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_

typedef char* BigInteger;
typedef BigInteger Bit;

void printInteger(BigInteger i);
BigInteger string2Integer(const char* i);
BigInteger int2Integer(const int i);
int lenInteger(BigInteger i);
BigInteger addInteger(BigInteger l, BigInteger r);
BigInteger mulInteger(BigInteger l, BigInteger r);
BigInteger powInteger(BigInteger l, int i);


#endif // _BIG_INTEGER_