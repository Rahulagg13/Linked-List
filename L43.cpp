
//
#include <iostream>
using namespace std;
#include "linkedlist.h"

void InsertAtIndex(struct Node **Start, int x, int index)
{
    struct Node *P = *Start;
    int n = CountNode(Start);
    if (index - 1 > n)
    {
        cout << "Insertion not Possible" << endl;
    }
    else
    {
        struct Node *P = *Start;
        for (int i = 1; i < index - 1; i++)
        {
            P = P->next;
        }
        InsAfter(&P, x);
    }
}
int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    InsertAtIndex(&Start, 2, 2);
    InsertAtIndex(&Start, 5, 5);

    Transverse(Start);
    return 0;
}