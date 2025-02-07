#include<bits/stdc++.h>
using namespace std;

void Insert(int A[], int n){
    int i = n;
    int temp = A[n];
    while(i>1 && temp<A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void CreateHeap(int A[], int n){
    for(int i=1; i<=n; i++){
        Insert(A, i);
    }
}

void PrintHeap(int A[], int n){
    for(int i=1; i<=n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int Delete(int A[], int n){
    int temp;
    int x = A[1];
    A[1] = A[n];

    int i = 1;
    int j = i*2;
    while(j<n){
        if(A[j]>A[j+1]){
            j = j+1;
        }
        if(A[i]>A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j;
            j = i*2;
        }
    }
    A[n] = x;
    return x;
}

int main(){
    int A[] = {0, 1, 2, 40, 33, 56, 98};
    CreateHeap(A, 6);
    cout << Delete(A, 6) << endl;
    PrintHeap(A, 6);
}