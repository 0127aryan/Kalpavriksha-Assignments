#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* ptr){
    struct Node* temp = ptr;
    printf("elemets are:\n");
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;

        if(temp !=  NULL){
            printf(" -> ");
        }
    }
}



int isPrime(int n){
    if(n<2) return 0;
    for(int i=2; i*i<=n;i++){
            if(n %i == 0){
                return 0;
            }
    }
}

struct Node* getPrimeList(struct Node* head){
    int primes[100], count =0;
    struct Node* temp = head;

    while(temp!=NULL){
        if(isPrime(temp->data)){
            primes[count++] = temp->data;
        }
        temp = temp->next;
    }

    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-1-i;j++){
            if(primes[j]>primes[i]){
                int temp = primes[j];
                primes[j] = primes[j+1];
                primes[j+1] = temp;
            }
        }
    }

    printf("\nprime number list is:\n");
    for(int i=0;i<count;i++){
        printf("%d \n",primes[i]);
        if(i <count-1 && primes!=NULL){
            printf("->");
        }
    }
    

}

struct Node* createNode(struct Node* head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;

    newNode->next = head;
    head = newNode;

    return head;

}

struct Node* createList(struct Node* head, int n){
    while(n!=0){
        head = createNode(head,n%10);
        n = n/10;
    }
    return head;
}
void swap(struct Node* a, struct Node* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    
}
void sortList(struct Node* head){
    int swapped;
    struct Node* ptr1;
    struct Node* ptr2 = NULL;

    if(head == NULL) return;
    do{
        swapped = 0;
        ptr1=head;

        while(ptr1->next != ptr2){
            if(ptr1->data <ptr1->next->data){
                swap(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;

    }while(swapped);

}

int main(){

    int a;
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    printf("Enter the elements of linked list:\n");
    scanf("%d", &a);   

    head = createList(head,a);

    printList(head);
    sortList(head);
    
    getPrimeList(head);
    
    //printList(head1);
    return 0;
}