#include <iostream>
using namespace std;
#include "linkedlist.h"

struct Node *CreateCopy(struct Node **S)
{
    struct Node *Start1 = NULL;
    struct Node *P = *S;
    while (P != NULL)
    {
        InsEnd(&Start1, P->info);
        P = P->next;
    }
    return Start1;
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    struct Node *Copy = CreateCopy(&Start);
    Transverse(Copy);
    return 0;
}