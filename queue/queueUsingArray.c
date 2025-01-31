#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;

}

int isEmpty(struct queue *q){
    if(q->r == q-> f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue is full\n");
    }

    else{
        q->r++;
        q->arr[q->r] = val;
    }
} 

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is empty");
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
    return -1;
}

int peek(struct queue *q,int position){
    if(isEmpty(q)){
        return 1;
    }
    else{
        if(position < 1 || position > q->size){
            return 1;
        }

        int index = (q->f + position +1) % q->size;

        return q->arr[index];
    }
}

int main(){
    struct queue q;
    q.size = 10;
    q.f = -1;
    q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    

    enqueue(&q, 12);
    enqueue(&q, 14);
    enqueue(&q, 16);
    enqueue(&q, 18);

    int element = peek(&q, 2);
    printf("%d\n", element);

    printf("Dequeue %d element from queue\n", dequeue(&q));
    printf("Dequeue %d element from queue\n", dequeue(&q));

    element = peek(&q,1);
    printf("%d\n", element);
   

    return 0;
}