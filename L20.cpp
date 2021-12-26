// Program for reversing the Circular Linked List

#include <iostream>
using namespace std;
#include "circularLinkedList.h"

void Reverse(struct Node **CStart)
{
    if (*CStart != NULL)
    {
        struct Node *P = (*CStart)->next;
        struct Node *Q = P->next;
        while (Q != *CStart)
        {
            struct Node *Temp = Q;
            Q = Q->next;
            Temp->next = P;
            P = P->next;
        }
        Q = Q->next;
        P = P->next;
        Q->next = P;
        *CStart = Q;
    }
}
int main()
{
    struct Node *CStart = NULL;
    struct Node *CStart2 = NULL;

    InsBeg(&CStart, 1);
    InsEnd(&CStart, 2);
    InsEnd(&CStart, 3);
    InsEnd(&CStart, 4);
    InsEnd(&CStart, 5);
    // InsBeg(&CStart2, 6);
    // InsEnd(&CStart2, 7);
    // InsEnd(&CStart2, 8);
    // InsEnd(&CStart2, 9);
    // InsEnd(&CStart2, 10);
    // struct Node *CStart3 = Concat(&CStart, &CStart2);
    Reverse(&CStart);
    Traverse(CStart);
    return 0;
}