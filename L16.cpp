
// Program for concatenation of Circular Linked List
#include <iostream>
using namespace std;
#include "circularLinkedList.h"

struct Node *Concat(struct Node **C1, struct Node **C2)
{
    if (*C1 != NULL && *C2 != NULL)
    {
        struct Node *P = (*C1)->next;
        (*C1)->next = (*C2)->next;
        (*C2)->next = P;

        struct Node *C3 = *C2;
        return C3;
    }
    else if (*C1 == NULL)
    {
        struct Node *C3 = *C2;
        return C3;
    }
    else if (*C2 == NULL)
    {
        struct Node *C3 = *C1;
        return C3;
    }
    else
    {
        cout << "Void concatenation!!!" << endl;
        exit(1);
    }
}

int main()
{
    struct Node *CStart = NULL;
    struct Node *CStart2 = NULL;

    InsBeg(&CStart, 1);
    InsEnd(&CStart, 2);
    InsEnd(&CStart, 3);
    InsEnd(&CStart, 4);
    InsEnd(&CStart, 5);
    InsBeg(&CStart2, 6);
    InsEnd(&CStart2, 7);
    InsEnd(&CStart2, 8);
    InsEnd(&CStart2, 9);
    InsEnd(&CStart2, 10);
    struct Node *CStart3 = Concat(&CStart, &CStart2);
    Traverse(CStart3);
    return 0;
}