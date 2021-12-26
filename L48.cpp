#include <iostream>
using namespace std;
#include "linkedlist.h"

void setsymdifference_ll(struct Node **START_1, struct Node **START_2)
{
    struct Node *P, *R;
    struct Node *Q, *START_3;
    Q = *START_1;
    P = *START_2;
    R = GetNode();
    R = START_3;
    START_3 = NULL;
    while (Q != NULL && P != NULL)
    {
        if (Q->info == P->info)
        {
            P = P->next;
            Q = Q->next;
        }
        else if (Q->info > P->info)
        {
            InsBeg(&START_3, P->info);
            P = P->next;
        }
        else
        {
            InsBeg(&START_3, Q->info);
            Q = Q->next;
        }
    }
    while (Q != NULL)
    {
        InsBeg(&START_3, Q->info);
        Q = Q->next;
    }
    while (P != NULL)
    {
        InsBeg(&START_3, P->info);
        P = P->next;
    }
    Reverse(&START_3);
    Transverse(START_3);
}

int main()
{
    struct Node *START_1 = NULL;
    InsBeg(&START_1, 10);
    InsBeg(&START_1, 7);
    InsBeg(&START_1, 5);
    InsBeg(&START_1, 3);
    InsBeg(&START_1, 2);
    InsBeg(&START_1, 1);
    struct Node *START_2 = NULL;
    InsBeg(&START_2, 9);
    InsBeg(&START_2, 8);
    InsBeg(&START_2, 7);
    InsBeg(&START_2, 6);
    InsBeg(&START_2, 3);
    InsBeg(&START_2, 1);
    setsymdifference_ll(&START_1, &START_2);
}