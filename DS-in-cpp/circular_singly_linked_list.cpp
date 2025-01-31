#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CircularList{
    private:
        Node *head;
    public:
        CircularList(){
            head = NULL;
        }
        CircularList(int A[], int n);
        void Display();
};

int main(){
    int A[] = {1, 2, 3, 4, 5};
    CircularList cl(A, 5);
    cl.Display();

    return 0;
}

CircularList::CircularList(int A[], int n){
    Node *p = new Node;
    Node *last;
    p->data= A[0];
    p->next = p;
    head = p;
    last = p;
    for(int i=1; i<n; i++){
        Node *t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last=t;
    }
}

void CircularList::Display(){
    Node *p = head;
    do{
        cout << p->data << " ";
        p=p->next;
    }while(p!=head);
    cout << endl;
}