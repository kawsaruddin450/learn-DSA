#include<stdio.h>

int main(){
    int a[50], size, pos, num;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        printf("Enter the value for index %d: ", i);
        scanf("%d", &a[i]);
    }

    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }

    printf("\nEnter the number you want to insert: ");
    scanf("%d", &num);
    printf("Which position you want to enter the number: ");
    scanf("%d", &pos);

    for(int i=size-1; i>=pos-1; i--){
        a[i+1] = a[i];
    }
    a[pos-1] = num;
    size++;

    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }

    return 0;
}