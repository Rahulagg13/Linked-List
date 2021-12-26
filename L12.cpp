
// Program for Sorting of a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for Set Difference
struct Node *Split(struct Node **S)
{
    struct Node *P = *S;
    int n = CountNode(&P);
    int i = 0;
    while (i < (n / 2) - 1)
    {
        P = P->next;
        i++;
    }
    struct Node *Q = P->next;
    P->next = NULL;
    return Q;
}

int main()
{
    struct Node *Start = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    InsEnd(&Start, 6);
    struct Node *Q = Split(&Start);
    cout << "Linked List is Split in two equal Parts : " << endl;
    cout << "First Part : " << endl;
    Transverse(Start);
    cout << "Second Part : " << endl;
    Transverse(Q);
    return 0;
}