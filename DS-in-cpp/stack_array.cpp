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
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}
void Stack::Display()
{
    while (top >= 0)
    {
        cout << S[top] << " ";
        top--;
    }
    cout << endl;
}

void Stack::Push(int x)
{
    if (top == size - 1)
    {
        cout << "Stack is full, push is not possible." << endl;
        return;
    }
    top++;
    S[top] = x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Stack st(10);
    for(int i=0; i<5; i++){
        st.Push(A[i]);
    }
    st.Display();

    return 0;
}
