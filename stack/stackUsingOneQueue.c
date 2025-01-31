#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int *arr;
    int f; //f refers to front
    int r; //r refers to rear
};

// void printList(struct queue *q){
//     struct queue* temp = q;
//     while(temp !=NULL){
//         printf("%d ",temp->f);
//         temp = temp->r;
//     }
// }

int isEmpty(struct queue *q){
    return q->f == -1; 
}

int isFull(struct queue *q){
    return q->r == q->size - 1;
}

void printList(struct queue *q){
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else{
    for (int i = q->f; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    }
}


void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue is full\n");
        return ;
    }

    if(isEmpty(q)){
        q->f = 0;
    }
    q->arr[++(q->r)] = value;
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return (q)->arr[(q->f)++];
    }
}

void push(struct queue *q, int value){
    enqueue(q,value);    
}

int pop(struct queue *q){
    if(isEmpty(q)){
        printf("Stack is Empty:\n");
        return -1;
    }
    else{
        return dequeue(q);
    }
}

int main(){
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    if(q == NULL){
        printf("memory allocation failed\n");
        return -1;
    }
    q->f = -1;
    q->r = -1;
    q->size = 10;
    q->arr = (int *) malloc(q->size * sizeof(int));
    if(q->arr == NULL){
        printf("memory allocation failed");
        free(q);
        return -1;
    }

    

    push(q,10);
    push(q,20);
    push(q,30);
    push(q,40);

    printList(q);

    printf("Popped Element is: %d\n",pop(q));
    printList(q);

    // free(q->arr);
    // free(q);

    return 0;
}
