#include <iostream>
using namespace std;
#include "circularLinkedList.h"

void Josephus(struct Node **CS)
{
    struct Node *P = (*CS)->next;
    int i = 1;
    while (P->next != P)
    {
        if (i == 12)
        {
            DelAft(&P, CS);
            i = 0;
        }

        P = P->next;
        i++;
    }
    cout << "-------" << endl;
    cout << "Alive : " << P->info << endl;
}

int main()
{
    struct Node *CStart = NULL;
    InsBeg(&CStart, 0);
    for (int i = 1; i < 100; i++)
    {
        InsEnd(&CStart, i);
    }

    cout << "-------" << endl;
    Josephus(&CStart);
    cout << "-------" << endl;

    return 0;
}