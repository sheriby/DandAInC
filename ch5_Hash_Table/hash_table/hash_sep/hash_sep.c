#include "hash_sep.h"
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#define MIN_TABLE_SIZE (1 << 4)

// Here we use element type str
// So here introducing function hasn_str
typedef unsigned int Hash;
Hash hash_str(const char *val) {
    int hash = 0;
    while (*val) {
        hash = (hash << 5) - hash + *val; // => 31*hash + *val
        // why 31?? Because 31 is prime number, and multiply 32 is easy in
        // binary.
        val++;
    }
    return hash;
}

struct ListNode {
    ElementType element;
    Position next;
};

typedef Position List;

struct HashTbl {
    /**
     * Here I set the size to the power of 2, such as 16, 32, 64 and so
     * on. because we can convert [x % n] to [x & (n - 1)], which is same to
     * HashSet/HashMap in JDK.
     * It seems that many people including the author of this book suggect
     * that we should set the size to a prime number to avoid the hash
     * collision. Emm...As a matter of fact, I also don't know how to handle
     * this problem.
     */
    int talbeSize;
    List *lists;
    int power;
};

static void Next2Power(int *tableSize, int *power) {
    int pow = 0;
    int val = 1;
    while (val < *tableSize) {
        val *= 2;
        pow++;
    }
    *power = pow;
    *tableSize = val;
}

static void makeEmpty(HashTable h) {
    int i;
    for (i = 0; i < h->talbeSize; i++) {
        // this function is only for initialization, so don't need to
        // free the nodes.
        h->lists[i]->next = NULL;
    }
}

// HashTable initializeTable(int tableSize) {
//     HashTable h;
//     int i;

//     h = (HashTable)malloc(sizeof(struct HashTbl));

//     if (tableSize < MIN_TABLE_SIZE) {
//         h->talbeSize = MIN_TABLE_SIZE;
//         h->power = 4;
//     } else {
//         Next2Power(&h->talbeSize, &h->power);
//     }
//     h->lists = (List *)malloc(sizeof(List) * h->talbeSize);
//     // h->lists = malloc(sizeof(struct ListNode) * h->talbeSize);
//     for (i = 0; i < h->talbeSize; i++) {
//         h->lists[i] = (List)malloc(sizeof(struct ListNode));
//         h->lists[i]->next = NULL;
//     }

//     return h;
// }

// impove he function `initializeTable`, there are too many malloc when we create the head
// node. We just need to malloc once!
// And if changing the way of malloc, we must changing the method of Destroy as well.
// Ensure malloc and free mathes!

HashTable initializeTable(int tableSize) {
    HashTable h;
    int i;

    h = (HashTable)malloc(sizeof(struct HashTbl));

    if (tableSize < MIN_TABLE_SIZE) {
        h->talbeSize = MIN_TABLE_SIZE;
        h->power = 4;
    } else {
        Next2Power(&h->talbeSize, &h->power);
    }
    h->lists = (List *)malloc(sizeof(List) * h->talbeSize);
    // Here we just malloc once!
    List temp= (List)malloc(sizeof(struct ListNode) * h->talbeSize);
    for (i = 0; i < h->talbeSize; i++) {
        h->lists[i] = &temp[i];
        h->lists[i]->next = NULL;
    }
    
    return h;
}

static void freeList(List list) {
    Position next;
    while (list) {
        next = list->next;
        free(list);
        list = next;
    }
}

// void destroyTable(HashTable h) {
//     int i;
//     for (i = 0; i < h->talbeSize; i++) {
//         freeList(h->lists[i]); // free the list
//     }
//     free(h->lists); // free the table
// }

void destroyTable(HashTable h) {
    int i;
    for (i = 0; i < h->talbeSize; i++) {
        freeList(h->lists[i]->next); // free the list
    }
    free(h->lists[0]); // free all head node
    free(h->lists); // free the table
}

Position find(ElementType key, HashTable h) {
    Hash hash;
    int index;
    List list;
    Position next;
    hash = hash_str(key);
    index = hash & (h->power - 1);
    list = h->lists[index];
    while (list) {
        next = list->next;
        if (next == NULL) {
            return NULL;
        }
        if (!strcmp(next->element, key)) {
            return next;
        }
        list = next;
    }
    return NULL;
}

void insert(ElementType key, HashTable h) {
    Hash hash;
    int index;
    List list;
    Position next;
    hash = hash_str(key);
    // index = hash % h->talbeSize;
    index = hash & (h->power - 1);
    list = h->lists[index];
    while (list) {
        next = list->next;
        if (next == NULL) {
            list->next = (Position)malloc(sizeof(struct ListNode));
            list->next->element = key;
            list->next->next = NULL;
            return;
        }
        if (!strcmp(next->element, key)) {
            return;
        }
        list = next;
    }
}
ElementType retrieve(Position p) {
    if (!p) {
        return "null";
    }
    return p->element;
}
