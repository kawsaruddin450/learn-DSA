#include<bits/stdc++.h>
using namespace std;

void Swap(int *x, int *y){
    int swap = *x;
    *x = *y;
    *y = swap;
}

void BubbleSort(int A[], int n){
    int flag=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                Swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int A[] = {1, 89, 34, 29, 56};
    int n = 4;

    BubbleSort(A, n);
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }

    return 0;
}