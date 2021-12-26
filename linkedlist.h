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

void InsBeg(struct Node **S, int x)
{
    struct Node *P;
    P = GetNode();
    P->info = x;
    P->next = *S;
    *S = P;
}
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
// Insert After
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
        (*P)->next = N;
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
int DelAft(struct Node **Q)
{
    if (*Q == NULL || (*Q)->next == NULL)
    {
        cout << "Void Deletion";
        exit(1);
    }
    struct Node *P = (*Q)->next;
    (*Q)->next = P->next;
    int x = P->info;
    cout << "Deleted Element : " << x << endl;
    delete (P);
    return x;
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

// Count Node
int CountNode(struct Node **Start)
{
    struct Node *P = *Start;
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}
void Reverse(struct Node **S)
{

    struct Node *p = NULL;
    struct Node *C = *S;
    struct Node *N = (*S)->next;
    while (N != NULL)
    {
        C->next = p;
        p = C;
        C = N;
        N = N->next;
    }
    C->next = p;
    *S = C;
}
void Concat(struct Node **S1, struct Node **S2)
{
    struct Node *P = *S1;
    while (P->next != NULL)
    {
        P = P->next;
    }
    P->next = *S2;
}

// Middle Element
struct Node *Mid(struct Node **Start)
{
    struct Node *P = *Start;
    struct Node *T = *Start;
    struct Node *R = (*Start)->next;

    while (R != NULL && R->next != NULL)
    {
        T = T->next;
        R = R->next->next;
        P = P->next;
    }
    return T;
}