#include <iostream>
using namespace std;
#include "circularLinkedList.h"
int Sum(struct Node *S)
{
    struct Node *P = S->next;
    int sum = 0;
    while (P != S)
    {
        sum += P->info;
        P = P->next;
    }
    return (P->info + sum);
}
void ModifyLinkedList(struct Node **S)
{
    struct Node *P = (*S)->next;
    int sum = Sum(P);
    while (P != *S)
    {
        P->info = sum - P->info;
        P = P->next;
    }
    P->info = sum - P->info;
}

int main()
{
    struct Node *CStart = NULL;
    InsBeg(&CStart, 1);
    InsEnd(&CStart, 2);
    InsEnd(&CStart, 3);
    InsEnd(&CStart, 4);
    InsEnd(&CStart, 5);
    ModifyLinkedList(&CStart);
    Traverse(CStart);
    return 0;
}