

// Program for addition very long numbers using Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for addition very long numbers using Linked List
struct Node *Mid(struct Node **Start)
{
    struct Node *P = *Start;
    struct Node *T = *Start;
    struct Node *R = (*Start)->next;

    while (R != NULL && R->next != NULL)
    {
        T = T->next;
        R = R->next->next;
        P = P->next;
    }
    return T;
}
int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 5);
    InsEnd(&Start, 7);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    InsEnd(&Start, 6);
    struct Node *MidElement = Mid(&Start);
    cout << "Middle Element : " << MidElement->info << endl;

    return 0;
}