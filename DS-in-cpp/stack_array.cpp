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
    Stack(int A[], int size);
    void Display();
};

Stack::Stack(int A[], int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
    for (int i = 0; i < size; i++)
    {
        S[i] = A[i];
        top++;
    }
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

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Stack st(A, 5);
    st.Display();

    return 0;
}
