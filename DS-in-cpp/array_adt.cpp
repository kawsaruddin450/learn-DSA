#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }

    T Get(int index);
    void Set(int index, T x);
    void Display();
    void Append(T x);
    void Insert(int index, T x);
    T Delete(int index);
    int LinearSearch(T key);
    int BinarySearch(T key);
    T Max();
    T Min();
    T Sum();
    float Avarage();
    void Reverse();
};

int main()
{
    cout << endl;
    int ch, index, s, sz, x;
    float avg;
    cout << "Enter size of the array: ";
    cin >> sz;

    Array<int> arr(sz);

    do
    {
        cout << "-----------------------------------------------------" << endl
             << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Avarage" << endl;
        cout << "5. Reverse" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an index and a value: ";
            cin >> index >> x;
            arr.Insert(index, x);
            break;
        case 2:
            cout << "Enter the address where to delete: ";
            cin >> index;
            arr.Delete(index);
            break;
        case 3:
            cout << "Enter a key: ";
            cin >> x;
            s = arr.BinarySearch(x);
            cout << "Index of search: " << s << endl;
            break;
        case 4:
            avg = arr.Avarage();
            cout << "Avarage: " << avg << endl;
            break;
        case 5:
            arr.Reverse();
            cout << "Array is reversed";
            break;
        case 6:
            arr.Display();
            break;
        }
    } while (ch < 7);

    return 0;
}

// get function
template<class T>
T Array<T>::Get(int index)
{
    if (index >= 0 && index < length)
    {
        return A[index];
    }
    return 0;
}

// set function
template<class T>
void Array<T>::Set(int index, T x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
}

// display the array
template<class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Append - add an element at the end of the array.
template<class T>
void Array<T>::Append(T x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
}

// Insert - Add an element at any index of the array.
template<class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length + 1 && index < size)
    {
        if (length < size)
        {
            length++;
            for (int i = length - 1; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = x;
        }
    }
}

// Delete an element from the array
template<class T>
T Array<T>::Delete(int index)
{
    if (index >= 0 && index < length - 1)
    {
        T item = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return item;
    }
    else
    {
        return 0;
    }
}

// Linear search on the array
template<class T>
int Array<T>::LinearSearch(T key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Binary search on the array
template<class T>
int Array<T>::BinarySearch(T key)
{
    int l, h, mid = 0;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

// find the max function
template<class T>
T Array<T>::Max()
{
    T max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// find the minimum function
template<class T>
T Array<T>::Min()
{
    T min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

// sum of the array
template<class T>
T Array<T>::Sum()
{
    T s = 0;
    for (int i = 0; i < length; i++)
    {
        s += A[i];
    }
    return s;
}

// avarage of an array
template<class T>
float Array<T>::Avarage()
{
    return (float)Sum() / length;
}

// Reverse the array
template<class T>
void Array<T>::Reverse()
{
    T swap;
    for (int i = 0, j = length - 1; i <= j; i++, j--)
    {
        swap = A[i];
        A[i] = A[j];
        A[j] = swap;
    }
}
