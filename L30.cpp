// Program for addition very long numbers using Linked List
#include <iostream>
using namespace std;
#include "linkedlist.h"

// function for addition very long numbers using Linked List
void Addition(struct Node **S1, struct Node **S2)
{
    struct Node *Answer = NULL;
    struct Node *List1 = NULL;
    struct Node *List2 = NULL;
    Reverse(S1);
    Reverse(S2);
    struct Node *P = *S1;
    struct Node *Q = *S2;
    int i = 0;
    int num = 0;
    while (P != NULL)
    {
        i++;
        num = num * 10 + P->info;
        if (i % 4 == 0)
        {
            int newNumber = 0;
            while (num != 0)
            {
                int rem = num % 10;
                newNumber = newNumber * 10 + rem;
                num = num / 10;
            }
            InsEnd(&List1, newNumber);
        }
        P = P->next;
    }
    if (num != 0)
    {
        int newNumber = 0;
        while (num != 0)
        {
            int rem = num % 10;
            newNumber = newNumber * 10 + rem;
            num = num / 10;
        }
        InsEnd(&List1, newNumber);
    }
    i = 0;
    while (Q != NULL)
    {
        i++;
        num = num * 10 + Q->info;
        if (i % 4 == 0)
        {
            int newNumber = 0;
            while (num != 0)
            {
                int rem = num % 10;
                newNumber = newNumber * 10 + rem;
                num = num / 10;
            }
            InsEnd(&List2, newNumber);
        }
        Q = Q->next;
    }
    if (num != 0)
    {
        int newNumber = 0;
        while (num != 0)
        {
            int rem = num % 10;
            newNumber = newNumber * 10 + rem;
            num = num / 10;
        }
        InsEnd(&List2, newNumber);
    }

    int carry = 0;
    while (List1 != 0 && List2 != 0)
    {
        int Total = List1->info + List2->info + carry;
        int sum = Total % 10000;
        carry = Total / 10000;
        InsBeg(&Answer, sum);
        List1 = List1->next;
        List2 = List2->next;
    }
    while (List1 != NULL)
    {
        int Total = List1->info + carry;
        int sum = Total % 10000;
        carry = Total / 10000;
        InsBeg(&Answer, sum);
        List1 = List1->next;
    }
    while (List2 != NULL)
    {
        int Total = List2->info + carry;
        int sum = Total % 10000;
        carry = Total / 10000;
        InsBeg(&Answer, sum);
        List2 = List2->next;
    }
    if (carry != 0)
    {
        InsBeg(&Answer, carry);
    }

    Transverse(Answer);
}
int main()
{
    struct Node *Start = NULL;
    struct Node *Start2 = NULL;
    InsBeg(&Start, 1);
    InsEnd(&Start, 5);
    InsEnd(&Start, 7);
    InsEnd(&Start, 4);
    InsEnd(&Start, 5);
    InsEnd(&Start, 6);
    InsBeg(&Start2, 1);
    InsEnd(&Start2, 5);
    InsEnd(&Start2, 9);
    InsEnd(&Start2, 4);
    InsEnd(&Start2, 5);
    InsEnd(&Start2, 6);
    cout << "____Addition_____" << endl;
    Addition(&Start, &Start2);
    return 0;
}