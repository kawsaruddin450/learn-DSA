#include<stdio.h>

void merge(int A[], int l, int mid, int h);
void merge_sort(int A[], int l, int h);

int main(){

    int A[] = {8, 2, 11, 7, 5, 6, 3, 9, 4, 10};
    int n = 10;
    merge_sort(A, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    return 0;
}

void merge(int A[], int l, int mid, int h){
    int i,j,k, index;
    i=l;
    index=l;
    k=l;
    j=mid+1;
    int B[100];
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[index++] = A[i++];
        }else{
            B[index++] = A[j++];
        }
    }
    for(;i<=mid; i++){
        B[index++] = A[i];
    }
    for(;j<=h; j++){
        B[index++] = A[j];
    }

    for(k=l; k<index; k++){
        A[k] = B[k];
    }
}

void merge_sort(int A[], int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(A, l, mid);
        merge_sort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}