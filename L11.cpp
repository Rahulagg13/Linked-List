// Program for Sorting of a Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for Set Difference
void SelectionSort(struct Node **S)
{
}

//

int main()
{
    struct Node *Start = NULL;

    InsBeg(&Start, 1);
    InsEnd(&Start, 5);
    InsEnd(&Start, 2);
    InsEnd(&Start, 6);
    InsEnd(&Start, 3);
    InsEnd(&Start, 4);
    // BubbleSort(&Start);

    Transverse(Start);
    return 0;
}