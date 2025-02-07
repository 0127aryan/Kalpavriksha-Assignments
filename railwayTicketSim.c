#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    VIP = 3,
    SENIOR_CITIZEN = 2,
    GENERAL = 1
}Priority;

struct Passenger{
    int passengerId;
    Priority type;
    char* passengerName;
    struct Passenger* next;    
};

struct Passenger* createPassenger(int id, Priority type, char* name){
    struct Passenger* newPassenger  = (struct Passenger*) malloc(sizeof(struct Passenger));

    if(newPassenger == NULL){
        printf("memory error\n");
        return NULL;
    }
   
        newPassenger->passengerId = id;
        newPassenger->type = type;
        
        newPassenger->passengerName = (char *)malloc(strlen(name) + 1);
        if(newPassenger->passengerName == NULL){
            printf("memory error\n");
        }
        strcpy(newPassenger->passengerName, name);

        newPassenger->next = NULL;
        return newPassenger;
}

struct Passenger* addPassenger(struct Passenger* head, int id, Priority type, char* name){
    struct Passenger* newPassenger = createPassenger(id, type, name);

    if(newPassenger == NULL){
        printf("cannot add passenger\n");
    }

    if(newPassenger == NULL) return head;

    if(head == NULL || head->type < type){
        newPassenger->next = head;
        head = newPassenger;

        return head;
    }

    struct Passenger* current = head;
    while(current->next != NULL && current->next->type <= type){
        current = current->next;
    }
    newPassenger->next = current->next;
    current->next = newPassenger;

    return head;
}

struct Passenger* serverNextPassenger(struct Passenger* head){
    if(head == NULL) return NULL;

    struct Passenger* temp = head;
    head = head->next;
    free(temp->passengerName);
    free(temp);

    return head;
}

void displayWaitingPassengers(struct Passenger* head){
    struct Passenger* temp = head;
    if(temp == NULL) return;

    while(temp != NULL){
        printf("Passenger Id: %d, Passenger Name:%s, Passenger Type: ", temp->passengerId, temp->passengerName);
        switch(temp->type){
            case VIP: printf("VIP\n"); break;
            case SENIOR_CITIZEN: printf("SENIOR_CITIZEN\n"); break;
            case GENERAL: printf("GENERAL\n"); break;
        }
        temp = temp->next;
    }
}

int main(){
    struct Passenger* head = NULL;

    int N = 0; //Number of Operations
    int choice, passengerId;
    char passengerName[50];
    char  passengerType[20];

    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            scanf("%d %s %[^\n]",&passengerId,passengerType,passengerName);
            Priority type;
            if(strcmp(passengerType, "VIP") == 0) type = VIP;
            else if(strcmp(passengerType, "SENIOR_CITIZEN") == 0) type = SENIOR_CITIZEN;
            else type = GENERAL;
            head = addPassenger(head,passengerId,type,passengerName);
            break;

            case 2:
            head = serverNextPassenger(head);
            break;

            case 3:
            displayWaitingPassengers(head);
            break;

            default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}