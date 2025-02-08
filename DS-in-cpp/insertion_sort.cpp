#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int A[], int n){
    int x;
    for(int i=1; i<n; i++){
        x = A[i];
        int j = i-1;
        while(j>=0 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){
    int A[] = {9, 5, 12, 8, 3};
    InsertionSort(A, 5);

    for(int i=0; i<5; i++){
        cout << A[i] << " ";
    }

    return 0;
}