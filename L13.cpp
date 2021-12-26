// Program for finding Cycle in a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

bool isCyclic(struct Node **S)
{
    struct Node *T = *S;
    struct Node *R = *S;
    while (R != NULL && R->next != NULL)
    {
        T = T->next;
        R = R->next->next;
        if (T == R)
        {
            return true;
        }
    }
    return false;
}
// function for finding Cycle in Linked List
struct Node *FindCycle(struct Node **S)
{
    struct Node *T = *S;
    struct Node *R = *S;
    while (R != NULL && R->next != NULL)
    {
        T = T->next;
        R = R->next->next;
        if (T == R)
        {
            return T;
        }
    }
    return R;
}

// function to find the length of the cycle
int CycleLength(struct Node **S)
{
    struct Node *P = FindCycle(S);
    struct Node *T = P->next;
    struct Node *R = P;
    int count = 1;
    while (T != R)
    {
        count++;
        T = T->next;
    }
    return count;
}

// function to find the cycle node in a given linked List
struct Node *FindCycleNode(struct Node **S)
{
    struct Node *P = FindCycle(S);
    struct Node *T = *S;
    struct Node *R = P;
    while (R != T)
    {
        R = R->next;
        T = T->next;
    }
    return T;
}

int main()
{
    struct Node *Start = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    InsEnd(&Start, 6);

    // making linked list cyclic
    Start->next->next->next->next->next->next = Start->next;

    string cyclic = isCyclic(&Start) == 1 ? "TRUE" : "False";
    cout << "Is Cyclic : " << cyclic << endl;

    struct Node *Q = FindCycleNode(&Start);

    cout << "Cyclic Node : " << Q->info << endl;

    int n = CycleLength(&Start);
    cout << "Cycle Length : " << n;

    return 0;
}