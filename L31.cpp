// Head node has the number of elements
#include <iostream>
using namespace std;
#include "linkedlist.h"
void create_header_list(struct Node **Head)
{
    *Head = GetNode();
    (*Head)->next = NULL;
    (*Head)->info = 0;
}

void Insbeg(struct Node **Head, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    struct Node *Q = (*Head)->next;
    P->next = Q;
    (*Head)->next = P;
    (*Head)->info = (*Head)->info + 1;
}

int DelBeg(struct Node **Head)
{
    if ((*Head)->next != NULL)
    {
        struct Node *P = (*Head)->next;
        struct Node *Q = P->next;
        (*Head)->next = Q;
        (*Head)->info = (*Head)->info - 1;
        int x = P->info;
        delete (P);
        return x;
    }
    else
    {
        cout << "void deletion";
    }
    return 0;
}

int main()
{
    struct Node *Head;

    create_header_list(&Head);

    Insbeg(&Head, 100);
    Insbeg(&Head, 200);
    Insbeg(&Head, 300);
    Insbeg(&Head, 400);
    Insbeg(&Head, 500);
    Transverse(Head);
    DelBeg(&Head);

    Transverse(Head);
}