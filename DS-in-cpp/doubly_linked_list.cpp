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
    void DisplayReverse();
    int Length();
    void Insert(int pos, int x);
    void Delete(int pos);
};

/*********************************************************************
                        MAIN FUNCTION
**********************************************************************/

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    DoublyList dl(A, 5);
    dl.Delete(4);
    dl.Display();
    dl.DisplayReverse();
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

void DoublyList::DisplayReverse()
{
    Node *p = first;
    while (p->next)
    {
        p = p->next;
    }
    while(p){
        cout << p->data << " ";
        p=p->prev;
    }
    cout << endl;
    
}

int DoublyList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyList::Insert(int pos, int x)
{
    Node *t, *p;
    if (pos < 0 || pos > this->Length())
    {
        cout << "Index out of range. Insertion not possible." << endl;
    }
    else
    {
        p = first;
        t = new Node;
        t->data = x;
        if (pos == 0)
        {
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
        else
        {
            Node *q;
            for (int i = 1; i < pos; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            p->next = t;
            q = t->next;
            if (q)
                q->prev = t;
        }
    }
}
void DoublyList::Delete(int pos)
{
    if (pos < 0 || pos > this->Length())
    {
        return;
    }
    else
    {
        if (pos == 1)
        {
            Node *p = first;
            first = first->next;
            if (first)
                first->prev = NULL;
            delete p;
        }
        else
        {
            Node *p = first;
            for (int i = 1; i < pos; i++)
            {
                p = p->next;
            }
            (p->prev)->next = p->next;
            if (p->next)
            {
                (p->next)->prev = p->prev;
            }
            delete p;
        }
    }
}