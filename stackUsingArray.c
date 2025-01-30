#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr ,int value){
    if(isFull(ptr)){
        printf("can not push to %d stack\n",value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("No elements in stack to pop");
    }
    else{
        int value = ptr->arr[ptr->top];  
        ptr->top--;
        return value;
       
    }
}

int peek(struct stack* ptr,int position){
    if(ptr->top-position+1 < 0){
        printf("Invalid Position\n");
    }
    else{
        return ptr->arr[ptr->top-position+1];
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before push stack empty: %d\n", isEmpty(s));
    printf("Before Push stack Full: %d\n",isFull(s));

    push(s,56);
    push(s,76);
    push(s,90);
    push(s,123);
    push(s,10);

    for(int i=0;i<s->size;i++){
        printf("elements in stack at position %d is: %d\n",i,peek(s,i));
    } 

    printf("after push stack empty: %d\n", isEmpty(s));
    printf("after push stack full: %d\n",isFull(s));

    printf("peeking %d data at position %d\n",peek(s,4),s->top);


    printf("%d is pop out\n",pop(s));
    printf("peeking %d data at position %d\n",peek(s,4),s->top);

      for(int i=0;i<s->size;i++){
        printf("elements in stack at position %d are: %d\n",i,peek(s,i));
    }

    printf("%d is pop out\n",pop(s));
    printf("peeking %d data at position %d\n",peek(s,4),s->top);

    printf("%d is pop out\n",pop(s));
    printf("peeking %d data at position 4\n",peek(s,4));
    


    return 0;
}