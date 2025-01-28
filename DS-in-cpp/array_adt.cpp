#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    }
}

int main(){
    struct Array arr={{1, 2, 3, 4, 5}, 20, 5};

    Display(arr);

    return 0;
}