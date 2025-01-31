#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    void Display();
    int Count();
};

int main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    LinkedList Ll(A, 8);
    Ll.Display();
    cout << "Number of elements in the linked list: " << Ll.Count() << endl;

    return 0;
}

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void LinkedList::Display(){
    Node *p;
    p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int LinkedList::Count(){
    Node *p;
    int count = 0;
    p=first;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}