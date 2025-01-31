#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* ptr){
    struct Node* temp = ptr;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){ 
        printf("Stack is Full\n");
     }
     else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;

        return top;
     }

}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack is Empty\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node* top,int position){
    struct Node* ptr = top;
    for(int i=0;(i<position-1 && ptr!=NULL);i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int main(){
    struct Node* top = NULL;

    top = push(top, 60);
    top = push(top, 70);
    top = push(top, 80);
    top = push(top, 90);
    top = push(top, 100);
    printList(top); 
    int element = pop(&top);
    printf("\nPopped element is : %d\n", element);
    printList(top);
    printf("\nValue at position 2 is : %d\n", peek(top, 2));
    
    return 0;
}