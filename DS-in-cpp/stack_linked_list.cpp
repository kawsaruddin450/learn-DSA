#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top = NULL;
public: 
    Stack(){
        top=NULL;
    }
    void Push(int x);
    void Display();
};

void Stack::Push(int x){
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

void Stack::Display(){
    Node *p = top;
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int main(){
    Stack st;
    st.Push(5);
    st.Push(5);
    st.Push(5);
    st.Display();

    return 0;
}