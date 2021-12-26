// Program for Linked List Implementation of Queue

#include <iostream>
using namespace std;
#include "linkedlist.h"
void Initialize(struct Node **front, struct Node **rear)
{
    *front = NULL;
    *rear = NULL;
}
void EnQueue(struct Node **front, struct Node **rear, int x)
{
    if (*front == NULL && *rear == NULL)
    {
        InsBeg(front, x);
        *rear = *front;
    }
    else
    {
        InsAfter(rear, x);
        (*rear) = (*rear)->next;
    }
}

void DeQueue(struct Node **front)
{
    delbeg(front);
}

int main()
{
    struct Node *Front;
    struct Node *Rear;
    Initialize(&Front, &Rear);
    EnQueue(&Front, &Rear, 1);
    EnQueue(&Front, &Rear, 2);
    EnQueue(&Front, &Rear, 3);
    EnQueue(&Front, &Rear, 4);
    EnQueue(&Front, &Rear, 5);
    EnQueue(&Front, &Rear, 6);
    DeQueue(&Front);

    Transverse(Front);
    return 0;
}