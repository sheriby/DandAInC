#ifndef _HashSep_H_
#define _HashSep_H_
/*
    Use 'Separate Chaining' to handle the problem of hash collision.
*/

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

typedef const char* ElementType;

HashTable initializeTable(int tableSize);
void destroyTable(HashTable h);
Position find(ElementType key, HashTable h);
void insert(ElementType key, HashTable h);
ElementType retrieve(Position p);

#endif // _HashSep_H_