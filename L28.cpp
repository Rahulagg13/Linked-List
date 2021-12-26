// Program for Sorting of a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for Set Difference
struct Node *BinarySearch(struct Node *Start, int x)
{
    struct Node *S = Start;
    while (S != NULL)
    {
        struct Node *mid = Mid(&S);
        if (x == mid->info)
        {
            return mid;
        }
        else if (x > mid->info)
        {
            S = mid->next;
        }
        else if (x < mid->info)
        {
            mid->next = NULL;
        }
    }
    return NULL;
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
    struct Node *E = BinarySearch(Start, 1);
    if (E == NULL)
    {
        cout << "Element not Found !!!";
    }
    else
    {
        cout << "Element Fount 🥳";
    }

    return 0;
}