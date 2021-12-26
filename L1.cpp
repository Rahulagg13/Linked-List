// Program for Linear Linked List Primitive Operations

#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};

struct Node *GetNode()
{
    struct Node *newNode;
    newNode = new (struct Node);
    return newNode;
}

// Insert Beg
void InsBeg(struct Node **S, int x)
{
    struct Node *P;
    P = GetNode();
    P->info = x;
    P->next = *S;
    *S = P;
}

// Insert End
void InsEnd(struct Node **S, int x)
{
    struct Node *P = *S;
    if (P == NULL)
    {
        P = GetNode();
        P->info = x;
        P->next = NULL;
        *S = P;
    }
    else
    {
        if (S != NULL)
        {
            while (P->next != NULL)
            {
                P = P->next;
            }
            struct Node *Q;
            Q = GetNode();
            Q->info = x;
            P->next = Q;
            Q->next = NULL;
        }
        else
        {
            InsBeg(S, x);
        }
    }
}

// Traverse
void Transverse(struct Node *Start)
{
    struct Node *P = Start;
    while (P != NULL)
    {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Delete Beg
void delbeg(struct Node **start)
{
    if (*start != NULL)
    {
        struct Node *p = (*start);
        int x = (*start)->info;
        *start = (*start)->next;
        cout << "Deleted element is : " << x << endl;
        delete (p);
    }
    else
    {
        cout << "Void Deletion";
        exit(1);
    }
}

// Delete After
void DelAft(struct Node **Q)
{
    if (*Q == NULL || (*Q)->next == NULL)
    {
        cout << "Void Deletion";
        exit(1);
    }
    struct Node *P = (*Q)->next;
    (*Q)->next = P->next;
    cout << "Deleted Element : " << P->info << endl;
    delete (P);
}

// Delete End
void delEnd(struct Node **start)
{

    if ((*start) == NULL)
    {
        cout << "Void Deletion";
        exit(1);
    }
    else
    {
        struct Node *q = *start;
        struct Node *P = NULL;
        while (q->next != NULL)
        {
            P = q;
            q = q->next;
        }

        cout << "Deleted element is " << q->info << " " << endl;
        if (P != NULL)
        {

            P->next = NULL;
        }
        else
        {
            *start = NULL;
        }
        delete (q);
    }
}

int main()
{
    struct Node *Start = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 2);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    InsEnd(&Start, 6);
    delbeg(&Start);
    delEnd(&Start);
    DelAft(&Start);
    Transverse(Start);
    return 0;
}