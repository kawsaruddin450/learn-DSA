#include<stdio.h>

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;

    // printing base address of an array;
    printf("%p\n", p);
    printf("%p\n", a);
    printf("%p\n", &a);

    // printing address of different index;
    printf("%p\n", (p+1));
    printf("%p\n", &a+1);

    // printing value
    printf("%d\n", 3[a]);

    // printing values using pointers;
    printf("%d\n", *p);
    printf("%d\n", *a);
    printf("%d\n", *p+1);
    printf("%d\n", *(a+1));
    printf("%d\n", *a+1);

    //printing whole array using pointers/addres;
    for(int i=0; i<5; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d ", p[i]);
    }

    return 0;
}