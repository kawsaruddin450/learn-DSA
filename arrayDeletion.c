#include<stdio.h>

int main(){
    int a[50], size, pos;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        printf("Enter the value for index %d: ", i);
        scanf("%d", &a[i]);
    }

    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }

    printf("Enter which position you want to delete: ");
    scanf("%d", &pos);

    for(int i=pos-1; i<size; i++){
        a[i]=a[i+1];
    }
    size--;

    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }

    return 0;
}