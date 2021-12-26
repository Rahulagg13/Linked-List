// Program for printing Linked List content in Reverse Order
#include <iostream>
using namespace std;
#include "linkedlist.h"

void ReversePrint(struct Node **S)
{
    struct Node *P = *S;
    int n = CountNode(&P);
    int a[n];
    int i = 0;
    // Getting all Elements
    while (P != NULL)
    {
        a[i] = P->info;
        i++;
        P = P->next;
    }
    // Reverse of a array
    for (i = 0; i < n / 2; i++)
    {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
    // print the content of an array
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}

int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    ReversePrint(&Start);
    return 0;
}