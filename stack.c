#include<stdio.h>
#define STACK_MAX 100

typedef struct{
    int top;
    int data[STACK_MAX];
}Stack;

void push(Stack *s, int item){
    if(s->top < STACK_MAX){
        s->data[s->top] = item;
        s->top = s->top+1;
    }else{
        printf("The stack is full.");
    }
}

int pop(Stack *s){
    if(s->top==0){
        printf("Stack is empty.\n");
        return -1;
    }else{
        s->top = s->top-1;
        int item = s->data[s->top];
        return item;
    }
}

int main(){
    Stack my_stack;
    int item;
    
    my_stack.top = 0;

    push(&my_stack, 1);
    push(&my_stack, 2);
    push(&my_stack, 3);

    item = pop(&my_stack);
    printf("%d\n", item);

    item = pop(&my_stack);
    printf("%d\n", item);

    item = pop(&my_stack);
    printf("%d\n", item);

    item = pop(&my_stack);
    printf("%d\n", item);

    return 0;
}