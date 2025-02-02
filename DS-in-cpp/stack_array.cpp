#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;

public:
    Stack()
    {
        size = 10;
        top = -1;
        S = new int[size];
    }
    Stack(int size);
    void Display();
    void Push(int x);
    int Pop();
    int Peek(int index);
    int StackTop();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}
void Stack::Display()
{
    int n=top;
    while (n >= 0)
    {
        cout << S[n] << " ";
        n--;
    }
    cout << endl;
}

void Stack::Push(int x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow." << endl;
        return;
    }
    top++;
    S[top] = x;
}

int Stack::Pop(){
    int x = -1;
    if(top==-1){
        cout << "Stack Underflow.";
    }
    else{
        x = S[top];
        top--;
    }
    return x;
}

int Stack::Peek(int index){
    int x= -1;
    if((top+1-index) < 0){
        cout << "Invalid index." << endl;
    }
    else{
        x = S[top-index+1];
    }
    return x;
}

int Stack::StackTop(){
    if(top==-1)
        return -1;
    return S[top];
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Stack st(10);
    for(int i=0; i<5; i++){
        st.Push(A[i]);
    }
    st.Display();
    cout << st.Peek(2);
    

    return 0;
}
