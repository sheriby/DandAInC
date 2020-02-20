#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StudentNode {
    int id;
    int age;
} StudentNode, *Student;

Student initStudent(int id, int age) {
    Student stud = malloc(sizeof(StudentNode));
    stud->id = id;
    stud->age = age;
    return stud;
}

typedef struct SAListNode {
    Student element;
    int length;
    int capacity;
} SAListNode, *SAList;

SAList initSAList(int capacity) {
    SAList list = malloc(sizeof(SAListNode));
    list->capacity = capacity;
    list->length = 0;
    list->element = malloc(capacity * sizeof(StudentNode));

    return list;
}

void freeSAList(SAList list) {
    free(list->element);
    free(list);
}

int insert(SAList list, Student stud) {
    if (list->length == list->capacity) { // 此时表满了，无法存放数据
        return 0;
    }
    memcpy(list->element + 1, list->element,
           list->length * sizeof(StudentNode)); // 往后移动一位
    list->element[0] = *stud;

    return 1;
}

int find(SAList list, int id) {
    int i;
    int age;
    for (i = 0; i < list->length; i++) {
        if (list->element[i].id == id) {
            age = list->element[i].age;
            break;
        }
    }

    Student stud = &list->element[i];
    memcpy(list->element + 1, list->element, i * sizeof(StudentNode)); // 往后移动一位
    // 我也蛮喜欢使用C++中的std::copy函数的，这两个函数作用是类似的
    /*
        如  int a[] = {1, 2, 3, 4, 5};
            std::copy(a, a + 5, ostream_iterator<int>(std::cout, ""));
            std::cout << std::endl;
        上面使用std::copy就应该写成如下的形式
            std::copy(list->element, list->element + i, list->element + 1); // stl多是[)
    */
    // 还有一个函数式memccpy(void* desc, void* src, int val, size_t size)
    // 和memcpy不同的是遇到字符val后会停止复制，并返回后一个指针位置。

    list->element[0] = *stud;
}
/**
 * 这里就不测试了，应该是没什么问题，测试还有创建好多节点，有点烦~~
*/