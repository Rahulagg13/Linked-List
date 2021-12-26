
//

//

//
#include <iostream>
using namespace std;
#include "linkedlist.h"

// Remove duplication
void RemoveDuplication(struct Node **S)
{
    struct Node *P = *S;

    while (P != NULL)
    {
        struct Node *Temp = P;
        struct Node *Q = P->next;
        while (Q != NULL)
        {
            if (Q->info == P->info)
            {
                Q = Q->next;
                DelAft(&Temp);
                continue;
            }
            Temp = Temp->next;
            Q = Q->next;
        }
        P = P->next;
    }
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    InsBeg(&Start, 1);
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    RemoveDuplication(&Start);
    Transverse(Start);
    return 0;
}