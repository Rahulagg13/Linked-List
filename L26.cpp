// Program for Sorting of a Linked List
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

bool Palindrome(struct Node **Start)
{

    struct Node *P = CreateCopy(Start);
    struct Node *Q = *Start;
    Reverse(&P);
    while (P != NULL && Q != NULL)
    {
        if (P->info != Q->info)
        {
            return false;
        }
        P = P->next;
        Q = Q->next;
    }
    return true;
}
int main()
{
    struct Node *Start = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 3);
    InsEnd(&Start, 2);
    InsEnd(&Start, 1);
    bool isPlaindrome = Palindrome(&Start);
    cout << isPlaindrome;
    // Transverse(Start);
    return 0;
}