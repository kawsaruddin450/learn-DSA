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
    int Pop();
    bool isEmpty();
    void Display();
    int Peek(int index);
    int StackTop();
};

void Stack::Push(int x){
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

int Stack::Pop(){
    Node *p = top;
    int x = -1;
    if(this->isEmpty()){
        cout << "Stack Underflow." << endl;
    }
    top = top->next;
    x=p->data;
    delete p;
    return x;
}

bool Stack::isEmpty(){
    if(top==NULL)
        return true;
    return false;
}

void Stack::Display(){
    Node *p = top;
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int Stack::Peek(int index){
    if(top==NULL){
        cout << "Stack is empty." << endl;
        return -1;
    }
    else{
        Node *p = top;
        for(int i=1; p!=NULL && i<index; i++){
            p=p->next;
        }
        if(this->isEmpty()){
            return -1;
        }
        else{
            return p->data;
        }
    }
}

int Stack::StackTop(){
    if(this->isEmpty()){
        return -1;
    }
    return top->data;
}

int main(){
    Stack st;
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    for(int i=0; i<7; i++){
        st.Push(A[i]);
    }
    st.Display();
    st.Pop();
    st.Display();
    
    cout << st.StackTop();

    return 0;
}