#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularList
{
private:
    Node *head;

public:
    CircularList()
    {
        head = NULL;
    }
    CircularList(int A[], int n);
    void Display();
    void Insert(int pos, int x);
    int Length();
    void Delete(int pos);
};

/*********************************************************************
                        MAIN FUNCTION
**********************************************************************/

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    CircularList cl(A, 5);
    cl.Insert(5, 10);
    cl.Delete(10);
    cl.Display();
    cout << "Length: " << cl.Length() << endl;

    return 0;
}

/*********************************************************************
                        END
**********************************************************************/

CircularList::CircularList(int A[], int n)
{
    Node *p = new Node;
    Node *last;
    p->data = A[0];
    p->next = p;
    head = p;
    last = p;
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void CircularList::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void CircularList::Insert(int pos, int x)
{
    Node *t = new Node;
    Node *p = head;
    t->data = x;
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t->next = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int CircularList::Length()
{
    Node *p = head;
    int count = 0;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

void CircularList::Delete(int pos)
{
    Node *p, *q;
    if (pos <= 0 || pos >= this->Length())
    {
        cout << "Deletion is not possible, Index out of range!" << endl;
    }
    else
    {
        if (pos == 1)
        {
            p = head;
            q = head;
            while (q->next != head)
            {
                q = q->next;
            }
            q->next = head->next;
            head = head->next;
            delete p;
        }
        else
        {
            p = head;
            q = NULL;
            for (int i = 0; i < pos - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
        }
    }
}