#include<bits/stdc++.h>
using namespace std;

void Swap(int *x, int *y){
    int swap = *x;
    *x = *y;
    *y = swap;
}

int Partition(int A[], int l, int h){
    int pivot = A[l];
    int i=l, j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

        if(i<j){
            Swap(&A[i], &A[j]);
        }
    }while(i<j);

    Swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}

int main(){
    int A[] = {4, 8, 5, 9, 12, 3, 7, 10, 11, 2, INT32_MAX};
    int n = 10;

    QuickSort(A, 0, n);
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
}