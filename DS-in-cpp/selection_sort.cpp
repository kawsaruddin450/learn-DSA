#include<bits/stdc++.h>
using namespace std;

void Swap(int *x, int *y){
    int swap = *x;
    *x = *y;
    *y = swap;
}

void SelectionSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int k=i;
        for(int j=i+1; j<n; j++){
            if(A[k]>A[j]){
                k=j;
            }
        }
        Swap(&A[i], &A[k]);
    }
}

int main(){
    int A[] = {8, 6, 3, 10, 9, 4, 12, 5, 2, 7};
    int n = 10;
    SelectionSort(A, n);
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }

    return 0;
}