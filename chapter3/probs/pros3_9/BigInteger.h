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

// TODO
/**
 * 使用上面的加法，乘法和幂运算的函数其实我们就已经完成了题目中要求的2^2000的任务了
 * 不过这个大整数还是需要完善的
 * 
 * 1) 首先是对负数的支持，这点我建议是创建一个结构体，
 *      typedef struct Node{
 *          char* integer;
 *          char symbol; // => '+' 表示是一个整数/ '-'表示是一个负数
 *      }
 *      
 *      typedef Node *BigInteger; 
 * 
 * 2) 添加了负数之后，自然要完善之前的那个加法的函数。至于减法其实就是加法的特例，减一个数也就是
 *    加上这个数的相反数。
 * 
 * 3）然后就需要添加除法（结果当然还是整数）
 *    除法的思路好像要比乘法要复杂不少（单纯的从时间复杂度上面来看）
 *    如果是简单的实现话，似乎好像真的就只有遍历了。
 * 
 * 4）添加取模的函数，这样取幂的函数指数也就可以使用大整数了。（取模的实现应该在除法的前面）
 * 
 * 5) 添加平方根函数（返回结果也还是整数）， 上面的加减乘除都已经实现了，再来使用牛顿迭代法求
 *    平方根似乎并不是什么难事。
 * 
 * 
 * 基本上也就上面的这些操作了，不过现在确实是有点不想做，等以后闲的没事干再写吧~~
*/


#endif // _BIG_INTEGER_