// Program for Linked List for pair wise swap

#include <iostream>
using namespace std;

#include "linkedlist.h"

void SwapPairs(struct Node **Start)
{
    struct Node *P = *Start;
    while (P->next != NULL && P != NULL)
    {
        struct Node *Q;
        Q = P->next;
        int temp = P->info;
        P->info = Q->info;
        Q->info = temp;
        if (Q->next == NULL || Q == NULL)
        {
            break;
        }
        P = P->next->next;
    }
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    SwapPairs(&Start);
    Transverse(Start);
    return 0;
}