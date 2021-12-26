// Merging of two sorted/unsorted Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// Function to Merge two sorted/unsorted Linked List
struct Node *Merge(struct Node **S1, struct Node **S2)
{
    struct Node *P = *S1;
    struct Node *Q = *S2;
    struct Node *Start3 = NULL;

    while (P != NULL && Q != NULL)
    {
        if (P->info < Q->info)
        {
            InsEnd(&Start3, P->info);
            P = P->next;
        }
        else
        {
            InsEnd(&Start3, Q->info);
            Q = Q->next;
        }
    }
    while (P != NULL)
    {
        InsEnd(&Start3, P->info);
        P = P->next;
    }
    while (Q != NULL)
    {
        InsEnd(&Start3, Q->info);
        Q = Q->next;
    }
    return Start3;
}
int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 210);
    InsBeg(&Start2, 3);
    InsEnd(&Start2, 4);
    struct Node *Start3 = Merge(&Start, &Start2);

    Transverse(Start3);
    return 0;
}