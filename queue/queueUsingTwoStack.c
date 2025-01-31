
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue1[SIZE], queue2[SIZE];
int top1 = -1, top2 = -1;
int count = 0;
void push1(int data)
{
    if (top1 == SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    queue1[++top1] = data;
}
void push2(int data)
{
    if (top2 == SIZE - 1)
    {
        printf("Overflow\n");
        return;
    }
    queue2[++top2] = data;
}
int pop1()
{
    if (top1 == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return queue1[top1--];
}
int pop2()
{
    if (top2 == -1)
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return queue2[top2--];
}
void enqueue(int data)
{
    push1(data);
    count++;
}
void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        push2(pop1());
    }
    printf("Dequeue: %d\n", pop2());
    count--;
    for (int i = 0; i < count; i++)
    {
        push1(pop2());
    }
}
void print()
{
    if (top1 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", queue1[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    enqueue(55);
    print();
    dequeue();
    print();
    enqueue(66);
    print();
    dequeue();
    print();
    return 0;
}