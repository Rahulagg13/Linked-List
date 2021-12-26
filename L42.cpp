

//
#include <iostream>
using namespace std;
#include "linkedlist.h"

void LinearSearch(struct Node **Start, int Key)
{
    struct Node *P = *Start;
    int index = 0;
    int flag = 0;
    while (P != NULL)
    {
        index++;
        if (P->info == Key)
        {
            flag = 1;
            break;
        }
        P = P->next;
    }
    if (flag == 1)
    {

        cout << "Element " << P->info << " found at index " << index << endl;
    }
    else
    {
        cout << "Element " << Key << " is not found !!!" << endl;
    }
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    LinearSearch(&Start, 2);
    Transverse(Start);
    return 0;
}