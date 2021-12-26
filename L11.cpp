// Program for Sorting of a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for Set Difference
void BubbleSort(struct Node **Start)
{
    int n = CountNode(Start);
    for (int i = 0; i < n; i++)
    {
        struct Node *P = *Start;
        struct Node *Q = P->next;
        for (int j = n - 1; j > i; j--)
        {
            if (P->info > Q->info)
            {
                int temp = P->info;
                P->info = Q->info;
                Q->info = temp;
            }
            P = P->next;
            Q = Q->next;
        }
    }
}

int main()
{
    struct Node *Start = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 5);
    InsEnd(&Start, 2);
    InsEnd(&Start, 6);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    BubbleSort(&Start);
    Transverse(Start);
    return 0;
}