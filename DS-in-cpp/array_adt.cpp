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

//get function
int Get(Array arr, int index){
    if(index>=0 && index< arr.length){
        return arr.A[index];
    }
    return 0;
}

//set function
void Set(Array *arr, int index, int x){
    if(index>=0 && index<arr->length){
        arr->A[index] = x;
    }
}

// display the array
void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
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


//Delete an element from the array
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
    else{
        return 0;
    }
}


//Linear search on the array
int LinearSearch(Array *arr, int key){
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]==key){
            return i;
        }
    }
    return -1;
}

//Binary search on the array
int BinarySearch(Array arr, int key){
    int l, h, mid=0;
    l=0;
    h=arr.length -1;
    while(l<=h){
        mid = (l+h)/2;
        if(arr.A[mid]==key){
            return mid;
        }
        else if(arr.A[mid]>key){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

//find the max function
int Max(Array arr){
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}

//find the minimum function
int Min(Array arr){
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}

//sum of the array
int Sum(Array arr){
    int s = 0;
    for(int i=0; i<arr.length; i++){
        s += arr.A[i];
    }
    return s;
}

//avarage of an array
float Avarage(Array arr){
    return (float) Sum(arr)/arr.length;
}

int main()
{
    struct Array arr = {{10, 11, 15, 18, 21, 24, 28, 31, 35, 39, 40, 56, 59, 80}, 20, 14};


    Set(&arr, 6, 6);
    cout << Get(arr, 7) << endl;
    cout << Max(arr) << endl;
    cout << Min(arr) << endl;
    cout << Avarage(arr) << endl;
    Display(arr);

    return 0;
}