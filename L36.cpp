#include <iostream>
using namespace std;
#include "linkedlist.h"

void Difference(struct Node **S1, struct Node **S2)
{
    struct Node *P = *S1;
    struct Node *Q = *S2;
    while (P != NULL || Q != NULL)
    {
    }
}
int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    struct Node *Start2 = NULL;
    InsBeg(&Start2, 1);
    InsEnd(&Start2, 2);
    InsEnd(&Start2, 3);
    InsEnd(&Start2, 4);
    Difference(&Start, &Start2);
    // Transverse(Start);
    return 0;
}