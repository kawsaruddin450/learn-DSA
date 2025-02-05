#ifndef TQueue_H
#define TQueue_H

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(){size=10;front=0;rear=0;Q=new Node*[size];}
    Queue(int size){this->size=size;front=0;rear=0; Q=new Node*[size];}
    void Enqueue(Node* x);
    void Display();
    Node* Dequeue();
    bool isEmpty();
};

void Queue::Enqueue(Node* x){
    if((rear+1)%size == front){
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear+1)%size;
    Q[rear] = x;
}

Node* Queue::Dequeue(){
    Node* x = NULL;
    if(front==rear){
        cout << "Queue is empty";
    }
    else{
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void Queue::Display(){
    if(front==rear){
        cout << "Queue is empty." << endl;
        return;
    }
    int i = front+1;
    do{
        cout << Q[i] << " ";
        i = (i+1)%size;
    }while(i!= (rear+1)%size);
    cout << endl;
}

bool Queue::isEmpty(){
    return front == rear;
}


#endif