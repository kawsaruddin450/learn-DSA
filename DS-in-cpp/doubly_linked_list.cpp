#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};
class DoublyList
{
private:
    Node *first;

public:
    DoublyList()
    {
        first = NULL;
    }
    DoublyList(int A[], int n);
    void Display();
    int Length();
};

/*********************************************************************
                        MAIN FUNCTION
**********************************************************************/

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    DoublyList dl(A, 5);
    dl.Display();
    cout << "Length of the list: " << dl.Length() << endl;

    return 0;
}

/*********************************************************************
                        END
**********************************************************************/

DoublyList::DoublyList(int A[], int n)
{
    Node *t, *p, *last;
    p = new Node;
    p->data = A[0];
    p->next = NULL;
    p->prev = NULL;
    first = p;
    last = p;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void DoublyList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int DoublyList::Length(){
    Node *p = first;
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}