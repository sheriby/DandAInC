#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Polynomial;
typedef PtrToNode Position;

Polynomial createPolynomial();

Polynomial array2Polynomial(int arr[], int len);
void printList(Polynomial list);
int isEmpty(Polynomial list);
int isLast(Position pos, Polynomial list);
Position advance(Position pos);
void insert(int coe, int exp, Polynomial list, Position pos);
void setNext(Position p, Position next, Polynomial list);

int coefficient(Position pos, Polynomial p);
int exponent(Position pos, Polynomial p);

void quickSortPolyByExp(Polynomial poly);
void mergeSort(Polynomial poly);
Position createItem(int coe, int exp);
Polynomial copyPolynomial(Polynomial src);







#endif // _POLYNOMIAL_H_

