#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

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

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};

    Append(&arr, 6);
    Insert(&arr, 0, 10);
    Display(arr);

    return 0;
}