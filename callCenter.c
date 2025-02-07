#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    CRITICAL = 4,
    HIGH = 3,
    MEDIUM = 2,
    LOW = 1
}urgency;

struct callCenter{
    int callId;
    char callName[50];
    urgency urgencyLevel;
    struct callCenter * next;
};

//creating a new node

struct callCenter* createCall(int callId, char *callName, urgency urgencyLevel){
    struct callCenter* newCall = (struct callCenter*) malloc(sizeof(struct callCenter));
    if(newCall == NULL){
        printf("memory not allocated\n");
        return NULL;
    }
    newCall -> callId = callId;
    strcpy(newCall -> callName ,callName);
    newCall -> urgencyLevel = urgencyLevel;

    newCall->next = NULL;

    return newCall;

}

//adding call priority wise
struct callCenter* addCall(struct callCenter* head,int id, char * callName, urgency urgencyLevel){
    struct callCenter* newCall = createCall(id, callName, urgencyLevel);

    if(newCall==NULL) return head;

    if(head == NULL || head->urgencyLevel < urgencyLevel){
        newCall->next = head;
        head = newCall;

        return head;
    }

    struct callCenter* current = head;
    while(current->next != NULL && current->next->urgencyLevel >= urgencyLevel){
        current = current->next;
    }
    newCall->next = current->next;
    current->next = newCall;
    return head;
}

struct callCenter* processNextCall(struct callCenter* head){
    if(head == NULL){
        printf("No calls to process!\n");
        return NULL;
    }
    struct callCenter* temp = head;
    head = head->next;
    free(temp);

    return head;
}

void displayCalls(struct callCenter* head){
    struct callCenter* temp = head;
    if(temp == NULL){
        printf("No calls left!\n");
    }
    while(temp!=NULL){
        printf("Id: %d, caller Name: %s, Urgency Level: %d\n",temp->callId, temp->callName, temp->urgencyLevel);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct callCenter* head = NULL;
    int choice, id, urgencyLevel;
    char callName[50];
    int numberOfOperations;

    printf("Enter the number of operations.\n");
    scanf("%d",&numberOfOperations);

    printf("Call Center Support System\n");
    for(int i =0; i<numberOfOperations;i++){
        printf("1. Log a new Call.\n");
        printf("2. Process the next call.\n");
        printf("3. Display all pending calls.\n");

        scanf("%d", &choice);
        switch(choice){
            case 1:
            printf("Enter the caller Id:\n");
            scanf("%d",&id);
            getchar();
            printf("Enter the caller name\n");
            scanf("%[^\n]%*c", callName);
            printf("Enter the urgency level. (1) for critical,(2) for High , (3) for Medium and (4) for Low level of urgency\n");
            scanf("%d",&urgencyLevel);

            if(urgencyLevel<1 || urgencyLevel>4){
                printf("Invalid urgency level\n");
                break;
            }

            head = addCall(head, id, callName, (urgency)urgencyLevel);
            break;

            case 2:
            head = processNextCall(head);
            break;

            case 3:
            displayCalls(head);
            break;

            default:
            printf("Invalid Choice!\n");
        }





    }

    return 0;
}