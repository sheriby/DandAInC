#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 计算一个数字的有多少位，可以转成字符串，然后看看大小.需要注意的是，注意正负数的问题。
 * 转成字符串标准库中已经有了 sprintf函数了。
 * 这个函数我们也可以简单的实现，不过应该算是比较复杂就是了。
 */
size_t numBit(int num) {
    if (num < 0) { // 负数转为正数计算长度。
        num = -num;
    }
    char *res[20]; //数字最多可以有二十位 10^20这个数已经是天文数字了。。。
    sprintf(res, "%d", num);
    return strlen(res);
}

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randArr(int arr[], int len) {
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 1000;
    }
}

/**
 * 基数排序算法，一种非常简单的桶类排序算法，使用空间换取时间。
 * @param arr 待排序的数组
 * @param len 数组的长度
 */
void radixSort(int arr[], size_t len) {
    // 先来准备十个桶，分别代表0-9
    // 下面我们需要来计算桶的大小是多少，也就是最大的数字的位数。
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int maxBit = numBit(max); // 得到桶的最大的大小

    // 生成桶
    int *bucket[10]; // 数组中存放的是指针，也可以说这是一个二维数组
    int i, j;
    for (i = 0; i < 9; i++) {
        bucket[i] = malloc(len * sizeof(int));
    }

    // 储存每个桶中数据的个数
    int bucketCot[10] = {0};

    int index;
    int base = 1;
    for (j = 0; j < maxBit; j++, base *= 10) {
        for (i = 0; i < len; i++) {
            index = arr[i] / base % 10;
            bucket[index][bucketCot[index]++] = arr[i]; // 将数据放入到桶当中去
        }

        // 从桶中取出数据
        int cot = 0; // 用来记录当前取了多少个数据
        for (i = 0; i < 10; i++) {
            index = 0; // 用来记录当前取的是这个桶的第几个数据
            while (index < bucketCot[i]) {
                arr[cot] = bucket[i][index];
                index++;
                cot++;
            }
            bucketCot[i] = 0; // 将这个桶清空。
        }
    }
}
int main() {
    int a[10];
    int len = 10;
    randArr(a, len);
    printArr(a, len);
    radixSort(a, len);
    printArr(a, len);

    getchar();
    return 0;
}