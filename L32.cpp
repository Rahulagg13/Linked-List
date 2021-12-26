#include <iostream>
using namespace std;
#include "linkedlist.h"

void DeleteAllOccurences(struct Node **START, int x)
{
    struct Node *P = *START, *Q = NULL;
    while (P != NULL)
    {
        if (P->info == x)
        {
            P = P->next;
            if (Q == NULL)
                delbeg(START);
            else
                DelAft(&Q);
        }
        else
        {
            Q = P;
            P = P->next;
        }
    }
}

int main()
{
    struct Node *START = NULL;
    InsBeg(&START, 2);
    InsEnd(&START, 7);
    InsBeg(&START, 1);
    InsBeg(&START, 9);
    InsBeg(&START, 7);
    InsBeg(&START, 7);
    DeleteAllOccurences(&START, 7);
    Transverse(START);
    return 0;
}