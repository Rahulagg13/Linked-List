// Program for Doubly linked list Primitive operations

#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *GetNode()
{
    struct Node *newNode;
    newNode = new (struct Node);
    return newNode;
}

// Insert Beg
void InsBeg(struct Node **D, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    P->prev = NULL;
    if (*D == NULL)
    {

        P->next = NULL;
        *D = P;
    }
    else
    {
        P->next = *D;
        (*D)->prev = P;
        *D = P;
    }
}

// Ins End
void InsEnd(struct Node **D, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    P->next = NULL;
    if (*D == NULL)
    {
        P->prev = NULL;
        *D = P;
    }
    else
    {
        struct Node *Q = *D;
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

void InsAfter(struct Node **P, int x)
{
    if (*P == NULL)
    {
        cout << "Void Insertion" << endl;
        exit(1);
    }
    else
    {
        struct Node *N = GetNode();
        N->info = x;
        N->next = (*P)->next;
        N->prev = *P;
        (*P)->next = N;
        if ((*P)->next != NULL)
        {
            struct Node *Q = (*P)->next;
            Q->prev = N;
        }
    }
}

// Delete Beg
void DelBeg(struct Node **D)
{
    if (*D != NULL)
    {
        struct Node *P = *D;
        struct Node *Q = (*D)->next;
        *D = Q;
        if (Q != NULL)
        {
            Q->prev = NULL;
        }
        int x = P->info;
        cout << "Deleted Element : " << x << endl;
        delete (P);
    }
    else
    {
        cout << "Void Deletion" << endl;
        exit(1);
    }
}

// Delete End
void DelEnd(struct Node **D)
{
    if (*D == NULL)
    {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    else
    {
        struct Node *P = NULL;
        struct Node *Q = *D;
        while (Q->next != NULL)
        {
            P = Q;
            Q = Q->next;
        }
        if (P != NULL)
        {
            P->next = NULL;
        }
        else
        {
            *D = NULL;
        }
        int x = Q->info;
        cout << "Deleted Element : " << x << endl;
        delete (Q);
    }
}

void DelAft(struct Node **N)
{
    if (*N == NULL || (*N)->next == NULL)
    {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    else
    {
        struct Node *P = (*N)->next;
        (*N)->next = P->next;
        struct Node *Q = P->next;
        if (Q != NULL)
        {
            Q->prev = *N;
        }
        int x = P->info;
        cout << "Deleted Element : " << x << endl;
        delete (P);
    }
}
// Traverse
void Traverse(struct Node *D)
{
    while (D != NULL)
    {
        cout << D->info << " ";
        D = D->next;
    }
}

int main()
{
    struct Node *D1 = NULL;
    InsBeg(&D1, 1);
    InsEnd(&D1, 2);
    InsAfter(&D1->next, 3);
    InsEnd(&D1, 4);
    InsEnd(&D1, 5);

    DelBeg(&D1);
    DelEnd(&D1);
    DelAft(&D1);

    Traverse(D1);
}