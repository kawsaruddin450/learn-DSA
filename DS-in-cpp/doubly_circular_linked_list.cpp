#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyCircular
{
private:
    Node *head;

public:
    DoublyCircular() { head = NULL; }
    DoublyCircular(int A[], int n);
    void Display();
    int length();
};

/*********************************************************************
                        MAIN FUNCTION
**********************************************************************/

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    DoublyCircular dc(A, 7);
    dc.Display();
    cout << "Length of the list: " << dc.length() << endl;
    return 0;
}

/*********************************************************************
                        END
**********************************************************************/

DoublyCircular::DoublyCircular(int A[], int n)
{
    Node *last, *t, *p;
    p = new Node;
    p->data = A[0];
    p->prev = p;
    p->next = p;
    head = p;
    last = p;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = head;
        last->next = t;
        last = t;
    }
}
void DoublyCircular::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int DoublyCircular::length()
{
    Node *p = head;
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    do
    {
        count++;
        p = p->next;
    } while (p != head);

    return count;
}

// void DoublyCircular::Insert(int pos, int x)
// {
//     if (pos < 0 || pos > this->length())
//     {
//         cout << "Index out of range. Insertion not possible." << endl;
//         return;
//     }
//     else
//     {
//         Node *t = new Node;
//         t->data = x;
//         if (pos == 0)
//         {
//             Node *last = head->prev;
//             t->next = head;
//             t->prev = last;
//             last->next = t;
//             head->prev = t;
//             head = t;
//         }
//         else
//         {
//             Node *p = head;
//             for (int i = 1; i < pos; i++)
//             {
//                 p = p->next;
//             }
//             t->next = p->next;
//             t->prev = p;
//             (p->next)->prev = t;
//             p->next = t;
//         }
//     }
// }

// void DoublyCircular::Delete(int pos)
// {
//     if (pos < 0 || pos > this->length())
//     {
//         return;
//     }
//     else
//     {
//         Node *p = head;
//         if (pos == 0)
//         {
//             if (head->next == head)
//             {
//                 head = NULL;
//             }
//             else
//             {
//                 Node *tail = head->prev;
//                 head = head->next;
//                 head->prev = tail;
//                 tail->next = head;
//             }
//             delete p;
//         }
//         else
//         {
//             for (int i = 1; i < pos; i++)
//             {
//                 p = p->next;
//             }
//             (p->prev)->next = p->next;
//             (p->next)->prev = p->prev;
//             delete p;
//         }
//     }
// }


