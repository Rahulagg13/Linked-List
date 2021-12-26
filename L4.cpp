// Reverse of a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

void Reverse(struct Node **S)
{

    struct Node *p = NULL;
    struct Node *C = *S;
    struct Node *N = (*S)->next;
    while (N != NULL)
    {
        C->next = p;
        p = C;
        C = N;
        N = N->next;
    }
    C->next = p;
    *S = C;
}

int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    Reverse(&Start);
    Transverse(Start);
    return 0;
}