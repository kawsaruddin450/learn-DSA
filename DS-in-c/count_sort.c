#include<stdio.h>
#include<stdlib.h>

int findMax(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n){
    int i,j, max, *temp;
    max = findMax(arr, n);
    temp =(int *) malloc(sizeof(int)*(max+1));

    for(int i=0; i<max+1; i++){
        temp[i] = 0;
    }

    for(i=0; i<n; i++){
        temp[arr[i]]++;
    }
    i=0;
    j=0;
    while(j<max+1){
        if(temp[j]>0){
            arr[i++] = j;
            temp[j]--;
        }else{
            j++;
        }
    }
}

int main(){
    int arr[] = {8, 3, 4, 10, 6, 7, 2, 5, 11, 9};
    int n = 10;
    countSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}