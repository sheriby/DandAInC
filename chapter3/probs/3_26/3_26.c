#include "deque.h"

int main(int argc, char const *argv[]) {
    Deque d = createDeque(10);
    inject(10, d);
    inject(20, d);
    inject(30, d);
    inject(40, d);
    push(777, d);
    push(66, d);
    forEach(d);
    pop(d);
    // pop(d);
    eject(d);
    forEach(d);
    // 测试完成
    return 0;
}
