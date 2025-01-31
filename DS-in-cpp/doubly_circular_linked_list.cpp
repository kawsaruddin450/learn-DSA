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
    head = p;
    p->prev = p;
    p->next = p;
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

int DoublyCircular::length(){
    Node *p = head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    do{
        count++;
        p=p->next;
    }while(p!=head);

    return count;
}