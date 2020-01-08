/**
 * 2. 使用一般数组重写上面的操作
 */
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteEle(int arr[], int len, int j) {
    memcpy(arr + j, arr + j + 1,
           (len - 1 - j) * sizeof(int)); // 后面的覆盖前面的元素
}

/**
 * @return 去重之后数组中的元素的个数
 */
int duplicateRemove(int arr[], int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                deleteEle(arr, len--, j--); // 这里需要将len--， j--！！

                // for循环中竟然是可以修改循环中的变量的，是我无知了。。。
                // 可能是之前使用C++给我这个不可以修改的错觉吧，，，主要是使用的情况不一样
                // C++好像是在使用迭代器迭代是，无法修改迭代器中的内容。
            }
        }
    }

    return len;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 2, 3, 1, 3, 6, 3, 6, 9, 7, 3, 9, 0, 2, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    printArr(arr, n);
    int len = duplicateRemove(arr, n);
    printArr(arr, len);

    getchar();
    return 0;
}
