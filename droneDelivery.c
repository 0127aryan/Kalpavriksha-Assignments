#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    URGENT = 3,
    PRIORITY = 2,
    STANDARD = 1
}Priority;

struct droneDelivery{
    int packageId;
    char * recipientName;
    Priority type;
    float packageWeight;
    struct droneDelivery* next;
};

//create a new package ( new node)
struct droneDelivery* createPackage(int packageId, char* recipientName, Priority type, float packageWeight){
    struct droneDelivery* newPackage = (struct droneDelivery*) malloc(sizeof(struct droneDelivery));
    if(newPackage == NULL){
        printf("Memory error\n");
        return NULL;
    }

    newPackage->packageId = packageId;
    newPackage->recipientName = (char *) malloc(strlen(recipientName + 1));
    if(newPackage->recipientName == NULL){
        printf("memory error\n");
    }
    strcpy(newPackage->recipientName ,recipientName);
    newPackage->type = type;
    newPackage->packageWeight = packageWeight;

    newPackage->next = NULL;

    return newPackage;

}
// add the package (add node)

struct droneDelivery* addPackage(struct droneDelivery* head, int packageId, char* recipientName,Priority type, float packageWeight){
    struct droneDelivery* newPackage = createPackage(packageId, recipientName, type, packageWeight);

    if(newPackage == NULL) return head;

    if(head == NULL || head->type > type){
        newPackage->next = head;
        head = newPackage;

        return head;
    }

    struct droneDelivery* current = head;
    while(current->next != NULL && current->next->type <= type){
        current = current -> next;
    }

    newPackage->next = current->next;
    current->next = newPackage;

    return head;
}

//dispatch the package ( delete the node)

struct droneDelivery* dispatchPackage(struct droneDelivery* head){
    if(head == NULL){
        printf("No package to deliver.\n");
        return NULL;
    }

    struct droneDelivery* temp = head;
    head = head->next;
    free(temp->recipientName);
    free(temp);

    return head;
}

// display the remaining package (print the list)

void displaypackage(struct droneDelivery* head){
    struct droneDelivery* temp = head;
    if(temp == NULL){
        printf("No package details to show.\n");
        return;
    }

    while(temp != NULL){
        printf("Package ID: %d, recipient name: %s, delivery Type: %d, package weight: %f\n", temp->packageId,temp->recipientName, temp->type, temp->packageWeight);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    struct droneDelivery * head = NULL;
    int numberOfOperations = 0;
    int id, type, choice;
    char recipientName[50];
    float packageweight;

    printf("Enter the number of operations:\n");
    scanf("%d",&numberOfOperations);

    printf("Autonomous Drone Delivery System\n");
    for(int i=0;i<numberOfOperations;i++){
        printf("1. Register a package\n");
        printf("2. Dispatch the package\n");
        printf("3. Display pending deliveries\n");

        scanf("%d", &choice);

        switch(choice){
            case 1: 
            printf("enter a package ID:\n");
            scanf("%d", &id);
            getchar();

            printf("enter the recipient's name:\n");
            scanf("%[^\n]%*c", recipientName);

            printf("Enter the delivery type: (1) for URGENT, (2) for PRIORITY and (3) for STANDARD\n");
            scanf("%d",&type);

            printf("Enter the weigth of the package in KG\n");
            scanf("%f", &packageweight);

            if(type<1 || type>3){
                printf("Invalid Delivery Type");
                break;
            }
            head = addPackage(head, id, recipientName, type, packageweight);

            break;

            case 2:
            head = dispatchPackage(head);
            break;

            case 3:
            displaypackage(head);
            break;

            default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}