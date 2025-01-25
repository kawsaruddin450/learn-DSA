#include<stdio.h>
#define Q_SIZE 5

typedef struct{
    int data[Q_SIZE + 1];
    int head, tail;
}Queue;

void enqueue(Queue *q, int item){
    if((q->tail + 1) % (Q_SIZE + 1) == q->head){
        printf("Queue is full.\n");
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_SIZE + 1);
}

int dequeue(Queue *q){
    int item;
    if(q->tail == q->head){
        printf("Queue is empty.");
        return 0;
    }else{
        item= q->data[q->head];
        q->head = (q->head+1) % (Q_SIZE + 1);
        return item;
    }
}

int main(){
    Queue my_q;

    my_q.head = 0;
    my_q.tail = 0;

    enqueue(&my_q, 1);
    enqueue(&my_q, 2);
    enqueue(&my_q, 3);

    int item;

    item = dequeue(&my_q);
    printf("%d\n", item);

    item = dequeue(&my_q);
    printf("%d\n", item);

    item = dequeue(&my_q);
    printf("%d\n", item);

    item = dequeue(&my_q);
    printf("%d\n", item);


    return 0;
}