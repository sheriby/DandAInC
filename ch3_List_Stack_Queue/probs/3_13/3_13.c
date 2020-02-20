#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STUDENT_NUM 100000

typedef struct {
    int id; // 暂时就不给其他的信息了
} Student;

typedef Student *pStud;

/**
 * 使用基数排序对目标数组进行排序
 *
 * @param bucketNum 基数排序中使用桶的数量
 */
void radixSort(Student stud[], int num, int bucketNum) {
    int max = stud[0].id;
    int i, j;
    // 找到学生中最大的的那个人的社会安全号码
    for (i = 1; i < num; i++) {
        if (stud[i].id > max) {
            max = stud[i].id;
        }
    }
    // 计算最多需要几次排序 如 2020 第一次落入 20号桶，第二次落入 2号桶
    // 需要两次排序
    printf("%d \n", max);

    int cot = 1;
    while (max / bucketNum) {
        max /= bucketNum;
        cot++;
    }
    printf("%d \n", cot);

    Student **buckets = malloc(bucketNum * sizeof(pStud));
    // 平均起来一个桶中需要放 num/bucketNum个数据，我想这么着也不能多的太多了吧
    // 假定桶的数量是>>50（如题目要求的1000）的，我感觉从概率论上来说每个桶最多可以放
    // num/50已经是足够的了。 要不然num*bucketNum也太特喵的浪费空间了吧
    for (i = 0; i < bucketNum; i++) {
        buckets[i] = malloc(num/60  * sizeof(Student)); // 给每个桶分配空间
    }

    // 创建标识每个桶中数据多少的数组，并手动初始化
    int *bucketCot = malloc(bucketNum * sizeof(int));
    for (i = 0; i < bucketNum; i++) {
        bucketCot[i] = 0;
    }

    int index;
    int position;
    int base = 1;
    for (i = 0; i < cot; i++, base *= bucketNum) {
        for (j = 0; j < num; j++) {
            index = stud[j].id / base % bucketNum; // 放到哪个桶里面去
            position = bucketCot[index]++; // 放到该桶的哪一个位置中
            buckets[index][position] = stud[j]; // 入桶
        }

        // 出桶操作
        int bar = 0; // 数组中的位置
        for (j = 0; j < bucketNum; j++) {
            index = 0; // 该桶中有多少数据
            while (index < bucketCot[j]) {
                stud[bar++] = buckets[j][index++];
            }
            bucketCot[j] = 0; // 将桶中元素清空。
        }
    }
}

void randStud(Student stud[], int len) {
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0; i < len; i++) {
        stud[i].id = rand() * rand() / 2; // 感觉这个数已经蛮大的了
    }
}

void printStud(Student stud[], int len) {
    int i;
    printf("Students: => [");
    for (i = 0; i < len - 1; i++) {
        printf("%d, ", stud[i].id);
    }
    printf("%d]\n", stud[len - 1].id);
}

int isOrdered(Student stud[], int len) {
    int i;
    for (i = 0; i < len - 1; i++) {
        if (stud[i + 1].id < stud[i].id) {
            printf("%d == %d\n", stud[i].id, stud[i+1].id);
            return 0;
        }
    }

    return 1;
}
int main(void) {
    Student studs[STUDENT_NUM];
    randStud(studs, STUDENT_NUM);
    printStud(studs, 10);
    clock_t start, end;
    start = clock();
    radixSort(studs, STUDENT_NUM, 1000);
    end = clock();
    printf("Running Time: %dms\n", (end - start));
    printStud(studs, 10);
    printf("Is is a ordered array? =>%d", isOrdered(studs, STUDENT_NUM));

    return 0;
}
