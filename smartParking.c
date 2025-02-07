#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    ELECTRIC = 3,
    HANDICAPPED = 2,
    REGULAR = 1,
}parking;

struct parkingLot{
    char* liscensePlate;
    char* driverName;
    parking type;
    struct parkingLot* next;
};

struct parkingLot* createParking(char* liscensePlate, char* driverName, parking type){
    struct parkingLot* newParking = (struct parkingLot*) malloc(sizeof(struct parkingLot));
    if(newParking == NULL){
        printf("Memory issues\n");
        return NULL;
    }
    newParking->liscensePlate = (char *)malloc(strlen(liscensePlate) + 1);
    if(newParking->liscensePlate == NULL){
        return NULL;
    }
    strcpy(newParking->liscensePlate, liscensePlate);

    newParking->driverName = (char *)malloc(strlen(driverName) + 1);
    if(newParking->driverName == NULL){
        return NULL;
    }
    strcpy(newParking->driverName, driverName);
    newParking->type = type;

    newParking->next = NULL;

    return newParking;

}

struct parkingLot* addVehicleToParking(struct parkingLot* head, char* liscensePlate, char* driverName, parking type){
    struct parkingLot* newParking = createParking(liscensePlate, driverName, type);

    if(newParking == NULL){
        printf("Memory error\n");
        return NULL;
    }

    if(newParking == NULL) return head;

    if(head == NULL || head->type < type){
        newParking->next = head;
        head = newParking;

        return head;
    }

    struct parkingLot* current = head;
    while(current->next != NULL && current->next->type <= type){
        current = current->next;
    }

    newParking->next = current->next;
    current->next = newParking;

    return head;
}


//delete from a given index using ddata se hoga.
struct parkingLot* removeVehicle(struct parkingLot* head, char* liscensePlate){
    if(head == NULL){
        printf("No vehicle is parked\n");
        return NULL;
    }
    struct parkingLot* temp = head;
    struct parkingLot* prev = NULL;

    while(temp != NULL && strcmp(temp->liscensePlate, liscensePlate) != 0){
        prev = temp;
        temp = temp->next;
    }

    //if not found vehicle
    if(temp == NULL){
        printf("Vehicle not found\n");
        return head;
    }

    //if found

    if(prev==NULL){
        head = temp->next;
    }
    else{
        prev->next = temp->next;
    }
    printf("Vehicle removed from parking\n");
    
    free(temp->liscensePlate);
    free(temp->driverName);
    free(temp);

    return head;

}

void displayParkingStatus(struct parkingLot* head){
    struct parkingLot* temp = head;

    if(temp == NULL){
        printf("No vehicle is parked\n");
        return;
    }

    while(temp != NULL){
        printf("Liscense number: %s, driver: %s, type: %d is parked\n", temp->liscensePlate, temp->driverName, temp->type);
        temp = temp->next;
    }
}

int main(){
    struct parkingLot* head = NULL;

    int numberOfoperations = 0;
    char liscensePlate[50];
    char driverName[50];
    int type, choice;

    printf("enter the number of Operations\n");
    scanf("%d", &numberOfoperations);

    printf("Smart parking lot:\n");
    for(int i=0;i<numberOfoperations;i++){
        printf("1. Park a vehicle\n");
        printf("2. Remove a vehicle\n");
        printf("3. display the parking status\n");

        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1: 
            printf("enter the liscense plate number:");
            scanf("%[^\n]%*c",liscensePlate);
            
            
            printf("Enter the driver name:");
            scanf("%[^\n]%*c", driverName);

            printf("Enter the type of vehicle. (1) for electric cars, (2) for Vehicles for people with disabilities and (3) for Regular cars\n");
            scanf("%d", &type);

            if(type <1 || type > 3){
                printf("Enter a valid vehicle type.\n");
            }
            head = addVehicleToParking(head, liscensePlate, driverName, type);
            break;

            case 2:
            printf("Enter the liscense plate of vehicle to be removed\n");
            scanf("%[^\n]%*c", liscensePlate);
            head = removeVehicle(head, liscensePlate);
            break;

            case 3:
            displayParkingStatus(head);
            break;

            default:
            printf("Invalid choice.\n");

        }
        

    }

    return 0;
}