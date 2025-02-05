#ifndef Queue_H
#define Queue_H

#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(){size=10;front=0;rear=0;Q=new int[size];}
    Queue(int size){this->size=size;front=0;rear=0;Q=new int[size];}
    void Enqueue(int x);
    void Display();
    int Dequeue();
};

void Queue::Enqueue(int x){
    if((rear+1)%size == front){
        cout << "Queue is full" << endl;
        return;
    }
    rear = (rear+1)%size;
    Q[rear] = x;
}

int Queue::Dequeue(){
    int x = -1;
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


#endif