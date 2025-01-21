#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
    struct Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}
void insertAtEnd(struct Node** head, int data) {
    struct Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL) {
        *head = ptr;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr;
}
void insertAtPosition(struct Node** head, int position, int data) {
    if (position < 1) {
        printf("Position is invalid\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("position is invalid\n");
        free(ptr);
        return;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void updateAtPosition(struct Node* head, int position, int newValue) {
    if (position < 1) {
        printf("position is invalid\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("position is invalid\n");
        return;
    }
    temp->data = newValue;
}
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("position is invalid\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("position is invalid\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(struct Node** head, int position) {
    if (position < 1 || *head == NULL) {
        printf("position is invalid\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
    if (temp == NULL || temp->next == NULL) {
        printf("position invalid\n");
        return;
    }
    temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("position invalid\n");
        return;
    }
    struct Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode);
}

int main() {
    struct Node* head = NULL;
    int n, operation, value, position;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);
        if(operation == 1){
            scanf("%d", &value);
            insertAtBeginning(&head, value);
        }
        else if(operation == 2){
            scanf("%d", &value);
            insertAtEnd(&head, value);
        }
        else if(operation == 3){
            scanf("%d %d", &position, &value);
            insertAtPosition(&head, position, value);
        }
        else if(operation == 4){
            display(head);
        }else if(operation == 5){
            scanf("%d %d", &position, &value);
            updateAtPosition(head, position, value);
        }
        else if(operation == 6){
            deleteAtBeginning(&head);
        }
        else if(operation == 7){
            deleteAtEnd(&head);
        }
        else if(operation == 8){
            scanf("%d", &position);
            deleteAtPosition(&head, position);
        }
        else{
            printf("invalid operation\n");
        }
    }
    return 0;
}