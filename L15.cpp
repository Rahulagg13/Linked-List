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
void InsBeg(struct Node **CS, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    if (*CS != NULL)
    {
        P->next = (*CS)->next;
        (*CS)->next = P;
    }
    else
    {
        P->next = P;
        *CS = P;
    }
}

// Insert End
void InsEnd(struct Node **CS, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    if (*CS != NULL)
    {
        P->next = (*CS)->next;
        (*CS)->next = P;
    }
    else
    {
        P->next = P;
    }
    *CS = P;
}

// Insert After
void InsAft(struct Node **Q, int x)
{
    struct Node *P = GetNode();
    P->info = x;
    if (*Q != NULL)
    {
        P->next = (*Q)->next;
        (*Q)->next = P;
    }
    else
    {
        P->next = P;
    }
}

// Traverse
void Traverse(struct Node *CS)
{
    if (CS != NULL)
    {
        struct Node *P = (CS)->next;
        if (P != NULL)
        {
            do
            {
                cout << P->info << " ";
                P = P->next;

            } while (P != (CS)->next);
        }
        else
        {
            cout << "There is No Node available";
        }
    }
    else
    {
        cout << "Empty Linked List !!!!" << endl;
    }
}

// Delete Beg
void DelBeg(struct Node **CS)
{
    if (*CS == NULL)
    {
        cout << "Void Deletion";
    }
    else
    {
        struct Node *P = (*CS)->next;
        if ((*CS)->next != *CS)
        {
            (*CS)->next = P->next;
        }
        else
        {
            *CS = NULL;
        }
        int x = P->info;
        delete (P);
        cout << "Delted :" << x << endl;
    }
}

// Delete End
void DelEnd(struct Node **CS)
{
    if (*CS == NULL)
    {
        cout << "Void Deletion !!!";
    }
    else
    {
        struct Node *P = (*CS)->next;
        while (P->next != *CS)
        {
            P = P->next;
        }
        struct Node *Q = (*CS);
        P->next = (*CS)->next;
        if ((*CS)->next != *CS)
        {
            *CS = P;
        }
        else
        {
            *CS = NULL;
        }
        int x = Q->info;
        delete (Q);
        cout << "Deleted :" << x << endl;
    }
}

// Delete After
void DelAft(struct Node **P, struct Node **CS)
{
    if (*P == NULL)
    {
        cout << "Void Deletion";
    }
    else if ((*P)->next == *CS)
    {
        DelEnd(CS);
    }
    else
    {
        struct Node *Q = (*P)->next;
        struct Node *R = Q->next;
        if ((*P)->next != *P)
        {
            (*P)->next = R;
        }
        else
        {
            *P = NULL;
        }
        int x = Q->info;
        cout << "Deleted :" << x << endl;
        delete (Q);
    }
}
int main()
{
    struct Node *CStart = NULL;
    InsBeg(&CStart, 1);
    InsEnd(&CStart, 2);
    InsEnd(&CStart, 3);
    InsEnd(&CStart, 4);
    InsEnd(&CStart, 5);
    DelBeg(&CStart);
    DelEnd(&CStart);
    DelAft(&CStart->next, &CStart);
    Traverse(CStart);
    return 0;
}