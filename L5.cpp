// Concat  of two Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function to concat two linked list
void Concat(struct Node **S1, struct Node **S2)
{
    struct Node *P = *S1;
    while (P->next != NULL)
    {
        P = P->next;
    }
    P->next = *S2;
}

int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsBeg(&Start2, 3);
    InsEnd(&Start2, 4);

    Concat(&Start, &Start2);

    Transverse(Start);
    return 0;
}