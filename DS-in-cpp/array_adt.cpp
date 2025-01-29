#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int *A;
    int size=0;
    int length=0;
};

// get function
int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return 0;
}

// set function
void Set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

// display the array
void Display(Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    cout << endl;
}

// Append - add an element at the end of the array.
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

// Insert - Add an element at any index of the array.
void Insert(struct Array *arr, int index, int x)
{
    if (index >= 0 && index <= arr->length + 1 && index < arr->size)
    {
        if (arr->length < arr->size)
        {
            arr->length++;
            for (int i = arr->length - 1; i > index; i--)
            {
                arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = x;
        }
    }
}

// Delete an element from the array
int Delete(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length - 1)
    {
        int item = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return item;
    }
    else
    {
        return 0;
    }
}

// Linear search on the array
int LinearSearch(Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Binary search on the array
int BinarySearch(Array arr, int key)
{
    int l, h, mid = 0;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
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
int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// find the minimum function
int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// sum of the array
int Sum(Array arr)
{
    int s = 0;
    for (int i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }
    return s;
}

// avarage of an array
float Avarage(Array arr)
{
    return (float)Sum(arr) / arr.length;
}

// Reverse the array
void Reverse(Array *arr)
{
    int swap;
    for (int i = 0, j = arr->length - 1; i <= j; i++, j--)
    {
        swap = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = swap;
    }
}

int main()
{
    struct Array arr;
    int ch, x, index, s;
    float avg;
    cout << "Enter size of the array: ";
    cin >> arr.size;

    arr.A = new int[arr.size];

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
            Insert(&arr, index, x);
            break;
        case 2:
            cout << "Enter the address where to delete: ";
            cin >> index;
            Delete(&arr, index);
            break;
        case 3:
            cout << "Enter a key: ";
            cin >> x;
            s = BinarySearch(arr, x);
            cout << "Index of search: " << s << endl;
            break;
        case 4:
            avg = Avarage(arr);
            cout << "Avarage: " << avg << endl;
            break;
        case 5:
            Reverse(&arr);
            cout << "Array is reversed";
            break;
        case 6:
            Display(arr);
            break;
        }
    } while (ch < 7);

    Display(arr);
    Reverse(&arr);
    Display(arr);

    return 0;
}