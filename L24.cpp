#include <iostream>
using namespace std;
#include "linkedlist.h"

struct Node *findKthNode(struct Node **START, int x)
{
    int n = 0;
    struct Node *p = *START;
    while (p)
    {
        p = p->next;
        n++;
    }
    if (n >= x)
    {
        p = (*START);
        for (int i = 0; i < n - x; i++)
        {
            p = p->next;
        }
    }
    return p;
}

int main()
{
    struct Node *START = NULL;
    InsEnd(&START, 100);
    InsEnd(&START, 200);
    InsEnd(&START, 300);
    InsEnd(&START, 400);
    InsEnd(&START, 500);
    InsEnd(&START, 600);
    Transverse(START);
    int x = 3;
    struct Node *p = findKthNode(&START, 3);
    cout << "Kth Node from Last : " << p->info;
}