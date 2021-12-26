#include <iostream>
using namespace std;
#include "linkedlist.h"
void ascendingOrderLinearLinkedList(int key, struct Node **start)
{
    struct Node *p = (*start);
    struct Node *q = NULL;
    while (p != NULL && key >= p->info)
    {
        q = p;
        p = p->next;
    }
    if (q != NULL)
    {
        InsAfter(&q, key);
    }
    else
    {
        InsBeg(&(*start), key);
    }
}

int main()
{
    struct Node *S = NULL;
    ascendingOrderLinearLinkedList(2, &S);
    ascendingOrderLinearLinkedList(4, &S);
    ascendingOrderLinearLinkedList(1, &S);
    ascendingOrderLinearLinkedList(5, &S);
    ascendingOrderLinearLinkedList(3, &S);
    Transverse(S);
    return 0;
}