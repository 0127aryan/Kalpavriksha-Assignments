#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* ptr){
    struct Node* temp = ptr;
    if(temp == NULL){
        printf("List is empty\n");
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp = temp->next;
        
        if(temp!=NULL){
            printf(" -> ");
        }
    }
}



struct Node* addNode(struct Node* head, int data){
    struct Node* temp = (struct Node*)malloc (sizeof(struct Node));
    if(temp == NULL){
        return NULL;
    }
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;

}


struct Node* addNumbers(struct Node* head1, struct Node* head2){
    if(head1->data==0) return head2;
    if(head2->data==0) return head1;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    struct Node* temp = NULL;

    int carry=0,sum;
    while(ptr1 || ptr2 || carry){
    sum =0;
    if(ptr1){
        sum = sum+ptr1->data;
        ptr1=ptr1->next;
    }
    if(ptr2){
        sum = sum + ptr2->data;
        ptr2= ptr2->next;
    }

    sum = sum + carry;
    temp = addNode(temp,sum%10);
    carry = sum/10;

    // if(carry){
    //     temp = addNode(temp,carry);
    // }
}
    return temp;
}

struct Node* reverseList(struct Node* head){
    if(head == NULL) return NULL;
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* temp = NULL;

    while(current != NULL){
    temp = current->next;
    current->next = prev;
    prev = current;
    current = temp;
    }
    return prev;
}

struct Node* createNode(struct Node* head, int value){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode ==NULL){
        return NULL;
    }
    newNode->data = value;
    //newNode->next = NULL;

    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* createList(struct Node* head, int n){
    while(n != 0){
        head = createNode(head, n%10);
        n = n/10;
    }

    return head;

}



int main(){
    int a,b;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;
    printf("Enter the first number:\n");
    scanf("%d",&a);
    printf("Enter the second number:\n");
    scanf("%d",&b);

    head1 = createList(head1,a);
    head2 = createList(head2,b);

    head1 = reverseList(head1);
    head2 = reverseList(head2);

    head3 = addNumbers(head1,head2);
    printf("\nAdditon of both the numbers is:\n");
    head3 = reverseList(head3);
    printList(head3);
    return 0;
}