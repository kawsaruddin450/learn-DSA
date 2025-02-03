#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front;
    Node *rear;
public:
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int x);
    void Display();
};

void Queue::Enqueue(int x){
    Node *t = new Node;
    if(t==NULL){
        cout << "Queue is full." << endl;
        return; 
    }
    else{
        t->data = x;
        t->next=NULL;
        if(front==NULL)front=rear=t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

void Queue::Display(){
    Node *p = front;
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    Queue q;
    for(int i=0; i<5; i++){
        q.Enqueue(A[i]);
    }
    q.Enqueue(10);
    q.Display();

    return 0;
}