#include <bits/stdc++.h>
using namespace std;


template <class T>
class Stack
{
private:
    int size;
    int top;
    T *S;

public:
    Stack()
    {
        size = 10;
        top = -1;
        S = new T[size];
    }
    Stack(int size);
    void Display();
    void Push(T x);
    T Pop();
    T Peek(int index);
    T StackTop();
    bool isEmpty();
    bool isFull();
};

template<class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new T[size];
}
template<class T>
void Stack<T>::Display()
{
    int n=top;
    while (n >= 0)
    {
        cout << S[n] << " ";
        n--;
    }
    cout << endl;
}

template<class T>
void Stack<T>::Push(T x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow." << endl;
        return;
    }
    top++;
    S[top] = x;
}

template<class T>
T Stack<T>::Pop(){
    T x = -1;
    if(this->isEmpty()){
        cout << "Stack Underflow.";
    }
    else{
        x = S[top];
        top--;
    }
    return x;
}

template<class T>
T Stack<T>::Peek(int index){
    T x= -1;
    if((top+1-index) < 0){
        cout << "Invalid index." << endl;
    }
    else{
        x = S[top-index+1];
    }
    return x;
}

template<class T>
T Stack<T>::StackTop(){
    if(this->isEmpty())
        return -1;
    return S[top];
}

template<class T>
bool Stack<T>::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

template<class T>
bool Stack<T>::isFull(){
    if(top == size-1){
        return true;
    }
    return false;
}

int main()
{
    string A = "Kawsar";
    Stack<char> st(7);
    for(int i=0; A[i]; i++){
        st.Push(A[i]);
    }
    st.Display();
    cout << st.Peek(2) << endl;
    bool empty = st.isEmpty();
    bool full = st.isFull();
    cout << empty << endl;
    cout << full << endl;
    

    return 0;
}
