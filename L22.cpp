#include <iostream>
using namespace std;
#include "linkedlist.h"
void Initialize(struct Node **Top)
{
    *Top = NULL;
}
void Push(struct Node **Top, int x)
{
    InsBeg(Top, x);
}
void Pop(struct Node **Top)
{
    delbeg(Top);
}
void Traverse(struct Node **Top)
{
    Transverse(*Top);
}
int main()
{
    struct Node *Top;
    Initialize(&Top);
    Push(&Top, 1);
    Push(&Top, 2);
    Push(&Top, 3);
    Push(&Top, 4);
    Push(&Top, 5);
    Pop(&Top);
    Traverse(&Top);
    return 0;
}