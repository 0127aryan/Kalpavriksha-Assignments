#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum{
    HIGH_PRIORITY = 3,
    MEDIUM_PRIORITY = 2,
    LOW_PRIORITY = 1
}Priority;

struct Product{
    int productId;
    char* productName;
    Priority priorityLevel;
    int processingTime;
    struct Product* next;
};

struct Product* createProduct(int Id, char* productName, Priority priorityLevel, int processingTime){
    struct Product* newProduct = (struct Product*) malloc(sizeof(struct Product));

    if(newProduct == NULL){
        printf("Memory error\n");
        return NULL;
    }

    newProduct->productId = Id;
    newProduct->productName = (char *) malloc(strlen(productName)+1);
    if(newProduct->productName == NULL){
        printf("Memory error\n");
        return NULL;
    }
    strcpy(newProduct->productName, productName);
    newProduct->priorityLevel = priorityLevel;
    newProduct->processingTime = processingTime;

    newProduct->next = NULL;
    return newProduct;
}

struct Product* addProduct(struct Product* head, int Id, char* productName, Priority priorityLevel, int processingTime){
    struct Product* newProduct = createProduct(Id, productName, priorityLevel, processingTime);

    if(newProduct == NULL){
        printf("Product creation failed\n");
        return NULL;
    }

    if(newProduct == NULL) return head;

    if(head == NULL || head->priorityLevel < priorityLevel){
        newProduct->next = head;
        head = newProduct;

        return head;
    }

    struct Product* current = head;
    while(current->next != NULL && current->next->priorityLevel <= priorityLevel){
        current = current->next;
    }
    newProduct->next = current->next;
    current->next = newProduct;

    return head;
}

struct Product *processNextProduct(struct Product* head){
    if(head == NULL){
        printf("No product to be moved to production.\n");
        return head;
    }
    struct Product* temp = head;
    head = head->next;
    free(temp->productName);
    free(temp);

    return head;
}

void displayPendingItems(struct Product* head){
    struct Product* temp = head;
    if(temp == NULL){
        printf("No pending products available\n");
        return;
    }

    while(temp != NULL){
        printf("Product Id: %d, Product name: %s, Priority Level: %d and processing Time: %d\n",temp->productId, temp->productName, temp->priorityLevel, temp->processingTime);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    struct Product* head = NULL;
    int numberOfOperations = 0;
    int choice, productId, priorityLevel, processingTime;
    char productName[50];

    printf("enter the number of Operations:\n");
    scanf("%d", &numberOfOperations);

    printf("Factory Production\n");
    for(int i=0;i<numberOfOperations;i++){
        printf("1. Add product to production Line\n");
        printf("2. Process the next item.\n");
        printf("3. Display pending production items.\n");

        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter the product id\n");
            scanf("%d",&productId);
            getchar();
            printf("Enter the product Name\n");
            scanf("%[^\n]%*c",productName);
            printf("enter the priority level: (1) High, (2) Medium and (3) Low:\n");
            scanf("%d",&priorityLevel);
            printf("Enter the processing time in seconds:\n");
            scanf("%d", &processingTime);

            if(priorityLevel<1 || priorityLevel>3){
                printf("Invalid priority level\n");
            }

            head = addProduct(head, productId, productName, priorityLevel, processingTime);
            break;

            case 2:
            head = processNextProduct(head);
            break;

            case 3:
            displayPendingItems(head);
            break;

            default:
            printf("Invalid Operation\n");
            
        }
    }

    return 0;
}