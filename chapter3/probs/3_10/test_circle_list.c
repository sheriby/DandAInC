#include "circle_list.h"
#include <stdio.h>
/**
 * 也没写啥方法，写的没做什么异常处理，看起来应该是能用的。
*/
int main() {
    int arr[] = {1, 3, 4, 5, 6, 78, 10};
    List list = arrayTolist(arr, 7);
    printList(list);
    Position p = advance(list);

    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", retrieve(p));
        if (i == 6) {
            deleteNext(p, list);
        }
        p = next(p, list);
    }

    return 0;
}