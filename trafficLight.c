#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    EMERGENCY = 1,
    PUBLIC_TRANSPORT = 2,
    PRIVATE = 3
}VehicleType;

struct Vehicle{
    int id;
    VehicleType type;
    char driverName[50];
    struct Vehicle* next;
};

//creating a new Node ( new vehicle entry)

struct Vehicle* createVehicle(int id, VehicleType type, char *driverName){
    struct Vehicle* newVehicle = (struct Vehicle*) malloc(sizeof(struct Vehicle));
    if(newVehicle == NULL){
        printf("Memory error\n");
        return NULL;
    }
    newVehicle->id = id;
    newVehicle->type = type;
    strcpy(newVehicle->driverName ,driverName);
    newVehicle->next = NULL;

    return newVehicle;
}

//add vehicle acc to priority
struct Vehicle* addVehicle(struct Vehicle* head,int id, VehicleType type, char *driverName){
    struct Vehicle* newVehicle = createVehicle(id,type,driverName);
    if(head == NULL || (head)->type > type){
        newVehicle ->next = head;
        head = newVehicle;

        return head;
    }
    
    struct Vehicle* current = head;
    while(current->next != NULL && current->next->type <= type){
        current = current->next;
    }

    newVehicle->next = current->next;
    current->next = newVehicle;

    return head;
}

//delete the head node
struct Vehicle* allowNextvehicle(struct Vehicle* head){
    if(head == NULL){
        printf("No vehicles waiting at signal\n");
        return NULL;
    }
    struct Vehicle* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// display waiting vehicles

void printWaitingVehicles(struct Vehicle* head){
    struct Vehicle* current = head;
    if(current == NULL){
        printf("No Vehicles are waiting\n");
        return;
    }
    while(current!=NULL){
        printf("ID: %d, Type: %d, Driver: %s\n",current->id, current->type, current->driverName);
        current = current->next;

    }
}



int main(){
    struct Vehicle* head = NULL;
    int choice, id, type;
    char driverName[50];
    int numberOfOperations;

    printf("Enter the number of operations\n");
        scanf("%d",&numberOfOperations);

    
        printf("\nTraffic Management System\n");
        for(int i=0;i<numberOfOperations;i++){

        printf("1. Register vehicle\n");
        printf("2. Allow next vehicle to pass\n");
        printf("3. Display waiting vehicles\n");

        

        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("enter your vehicle id:\n");
            scanf("%d", &id);

            printf("enter the vehicle type: (1) for emergency , (2) for public transport and (3) for private vehicle:\n");
            scanf("%d\n", &type);
            getchar();

            printf("Enter the name of the driver:\n");
            scanf("%[^\n]%*c", &driverName);

            if(type<1 || type>3){
                printf("Invalid Vehicle type!\n");
                break;
            }
           head = addVehicle(head, id, (VehicleType)type, driverName);
            break;

            case 2:
           head = allowNextvehicle(head);
            break;

            case 3:
            printWaitingVehicles(head);
            break;

            default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}