#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* f = NULL; // Front pointer
struct Node* r = NULL; // Rear pointer
int size = 0;

void printList(struct Node* ptr){
    struct Node* temp = ptr;
    while(temp !=NULL){
        printf("Elements are: %d\n",temp->data);
        temp = temp->next;
    }
}

int isEmpty(){
    return f == NULL;
}

int isFull(int capacity){
    return size>= capacity;
}

void enqueue(int value, int capacity){
    if(isFull(capacity)){
        printf("Queue is full\n");
        return;
    }
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("queue is Full");
    }
    else{
        n->data = value;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }

}

int dequeue(){
    int value = -1;
    struct Node* ptr = f;

    if(f==NULL){
        printf("Queue is Empty");
    }
    else{
        f = f->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}



int main(){
    
    int capacity = 10;

    enqueue(21,capacity);
    enqueue(31,capacity);
    enqueue(41,capacity);
    enqueue(61,capacity);
    enqueue(51,capacity);

    printList(f);

    printf("Dequeue top element from list: %d\n", dequeue());
    printList(f);
    return 0;
}