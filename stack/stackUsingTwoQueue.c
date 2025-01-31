#include<stdio.h>
#include<stdlib.h>

struct queue {
    int *arr;
    int front;
    int rear;
    int size;
};

void printList(struct queue *q){
    int i = q->front;
    while (i <= q->rear) {
        printf("%d ", q->arr[i]);
        i++;
        }
        printf("\n");
}

int isEmpty(struct queue *q){    
        return q->front > q->rear;
}

int isFull(struct queue *q){
    return q->rear == q->size-1 && q->front == 0;
}

void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Queue is Full\n");
        return ;
    }
    else{
        q->rear = q->rear + 1;
        q->arr[q->rear] = data;
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = q->front + 1;
    return value;
}

void push(struct queue *q1, struct queue *q2, int data){
    enqueue(q1,data);
}

int pop(struct queue *q1, struct queue *q2){
    if(isEmpty(q1)){
        printf("Stack is empty.\n");
        return -1;
    }

    else{
    // while(q1->front != q2->rear){
    //     enqueue(q2, dequeue(q1));
    // }

    // int value = dequeue(q1);

    // struct queue * temp = q1;
    // q1 = q2;
    // q2 = temp;

    // return value;
    return dequeue(q1);
    }


}

int main(){
    struct queue *q1 = (struct queue*)malloc(sizeof(struct queue));
    struct queue *q2 = (struct queue*)malloc(sizeof(struct queue));
    if(q1 == NULL || q2 == NULL){
        printf("Memory allocation failed\n");
        free(q1);
        free(q2);
        return -1;
    }
    q1->arr = (int *)malloc(q1->size * sizeof(int));
    q2->arr = (int *)malloc(q2->size * sizeof(int));
    if(q1 == NULL || q2 == NULL){
        printf("Memory allocation failed for the array\n");
        free(q1);
        free(q2);
        return -1;
    }
    q1->front = 0;
    q1->rear = -1;
    q1->size = 10;
    q2->front = 0;
    q2->rear = -1;
    q2->size = 10;

    push(q1,q2,10);
    push(q1,q2,20);
    push(q1,q2,30);
    push(q1,q2,40);
    push(q1,q2,50);

    printList(q1);

    printf("popped value: %d\n",pop(q1,q2));
    printList(q1);
    free(q1->arr);
    free(q2->arr);
    free(q1);
    free(q2);
    

    return 0;
}