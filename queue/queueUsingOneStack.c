#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int top;
    int size;
};

void printList(struct stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void initStack(struct stack *s, int size)
{
    s->arr = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
}

void push(struct stack *s, int value)
{
    if (s->top == s->size - 1)
    {
        printf("Stack already full\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int isEmpty(struct stack *s)
{
    return s->top == -1;
}

void enqueue(struct stack *s, int value)
{
    push(s, value);
}

int dequeue(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int x = pop(s);

    if (isEmpty(s))
    {
        return x;
    }

    int item = dequeue(s);
    push(s, x);

    return item;
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    int size = 10;

    initStack(s, size);

    enqueue(s, 10);
    enqueue(s, 20);
    enqueue(s, 30);
    enqueue(s, 40);
    enqueue(s, 50);

    printList(s);

    printf("Popped elements are: %d\n", dequeue(s));
    printf("Popped elements are: %d\n", dequeue(s));
    printf("Popped elements are: %d\n", dequeue(s));

    printList(s);

    enqueue(s, 60);
    enqueue(s, 70);

    printList(s);
    printf("Popped elements are: %d\n", dequeue(s));
    printf("Popped elements are: %d\n", dequeue(s));
    printf("Popped elements are: %d\n", dequeue(s));
    printf("Popped elements are: %d\n", dequeue(s));

    printList(s);

    free(s->arr);
    free(s);

    return 0;
}
