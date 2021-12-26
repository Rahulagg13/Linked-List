
// Program for Set Difference
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for Set Difference
struct Node *Difference(struct Node **S1, struct Node **S2)
{
    struct Node *P = *S1;
    struct Node *Start3 = NULL;

    while (P != NULL)
    {
        struct Node *Q = *S2;
        int count = 0;
        while (Q != NULL)
        {
            if (Q->info == P->info)
            {
                count++;
                break;
            }
            Q = Q->next;
        }
        if (count == 0)
        {
            InsEnd(&Start3, P->info);
        }
        P = P->next;
    }
    return (Start3);
}

//

int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 210);
    InsBeg(&Start2, 3);
    InsEnd(&Start2, 4);
    struct Node *Start3 = Difference(&Start, &Start2);

    Transverse(Start3);
    return 0;
}