#include <iostream>
using namespace std;
#include "linkedlist.h"
int CountNode(struct Node **Start)
{
    struct Node *P = *Start;
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}
int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 5);
    InsEnd(&Start, 7);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    cout << CountNode(&Start);
    return 0;
}