#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *Getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void InsBeg(struct node **START, int c, int e)
{
    struct node *temp;
    temp = Getnode();
    temp->coef = c;
    temp->exp = e;
    temp->next = *START;
    (*START) = temp;
}
void InsEnd(struct node **START, int c, int e)
{
    struct node *Q;
    struct node *P;

    Q = *START;
    if (*START == NULL)
    {
        InsBeg(&(*START), c, e);
    }
    else
    {
        while (Q->next != NULL)
        {
            Q = Q->next;
        }
        P = Getnode();
        P->coef = c;
        P->exp = e;
        P->next = NULL;
        Q->next = P;
    }
}
void Traverse(struct node *START)
{
    struct node *p = START;
    while (p != NULL)
    {
        printf("\t %dX%d +", p->coef, p->exp);
        p = p->next;
    }
}
void Reverse(struct node **S)
{

    struct node *p = NULL;
    struct node *C = *S;
    struct node *N = (*S)->next;
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

struct node *polynomial_additon(struct node **Poly1, struct node **Poly2)
{
    struct node *Poly3 = NULL;
    struct node *P = *Poly1;
    struct node *Q = *Poly2;
    while (P != NULL && Q != NULL)
    {
        if (P->exp == Q->exp)
        {
            InsBeg(&Poly3, P->coef + Q->coef, P->exp);
            P = P->next;
            Q = Q->next;
        }
        else
        {
            if (P->exp > Q->exp)
            {
                InsBeg(&Poly3, P->coef, P->exp);
                P = P->next;
            }
            else
            {
                InsBeg(&Poly3, Q->coef, Q->exp);
                Q = Q->next;
            }
        }
    }
    while (P != NULL)
    {
        InsBeg(&Poly3, P->coef, P->exp);
        P = P->next;
    }
    while (Q != NULL)
    {
        InsBeg(&Poly3, Q->coef, Q->exp);
        Q = Q->next;
    }
    Reverse(&Poly3);
    return Poly3;
}

int main()
{
    struct node *START1 = NULL;
    struct node *START2 = NULL;
    struct node *START3 = NULL;
    int x;
    InsEnd(&START1, 3, 8);
    InsEnd(&START1, 5, 7);
    InsEnd(&START1, -2, 6);
    InsEnd(&START1, 8, 4);
    printf("\n First Polynomial is :");
    Traverse(START1);
    printf("\n");
    InsEnd(&START2, 4, 7);
    InsEnd(&START2, 5, 6);
    InsEnd(&START2, -1, 3);
    InsEnd(&START2, 2, 7);
    InsEnd(&START2, -3, 0);
    printf("\n second Polynomial is :");
    Traverse(START2);
    printf("\n");
    START3 = polynomial_additon(&START1, &START2);
    printf("\n");
    printf("Result of polynomial addition is: ");
    Traverse(START3);
}