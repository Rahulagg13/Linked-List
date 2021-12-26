
//

//
#include <iostream>
using namespace std;
#include "linkedlist.h"

void CountEvenOdd(struct Node **Start)
{
    struct Node *P = *Start;
    int EventCount = 0;
    int OddCount = 0;
    while (P != NULL)
    {
        if (P->info % 2 == 0)
        {
            EventCount++;
        }
        else
        {
            OddCount++;
        }
        P = P->next;
    }
    cout << "Even = " << EventCount << endl;
    cout << "Odd = " << OddCount << endl;
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    CountEvenOdd(&Start);
    return 0;
}