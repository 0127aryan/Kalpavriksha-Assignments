#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    CRITICAL =3 ,
    SERIOUS = 2,
    STABLE = 1    
}status;

struct patient{
    int patientId;
    char* patientName;
    status type;
    struct patient *next;
};

struct patient* create_Patient(int id, char* name, status type){
    struct patient* newPatient = (struct patient*) malloc(sizeof(struct patient));
    if(newPatient == NULL) return NULL;

    newPatient->patientId = id;
    newPatient->patientName = (char *) malloc(strlen(name) + 1);
    if(newPatient->patientName == NULL) return NULL;
    strcpy(newPatient->patientName, name);
    newPatient->type = type;

    newPatient->next = NULL;
    return newPatient;
}

struct patient* addpatient(struct patient* head, int id, char* name, status type){
    struct patient* newPatient = create_Patient(id,name,type);
    if(head == NULL) return head;

    if(newPatient == NULL || newPatient->type < type){
        newPatient->next = head;
        head = newPatient;
        
        return head;
    }
    struct patient* current = head;
    while(current->next != NULL && current->next->type <= type){
        current = current->next;
    }
    newPatient->next = current->next;
    current->next = newPatient;

    return head;
}

struct patient* nextPatient(struct patient* head){
    if(head == NULL) return NULL;

     struct patient* temp = head;
     head = head->next;
     free(temp->patientName);
     free(temp);
}

void displayAllPatientRecords(struct patient* head){
    struct patient* temp = head;
    if(temp == NULL) return;

    while(temp!= NULL){
        printf("Patient ID: %d, Patient name:%s and patient type: ", temp->patientId, temp->patientName);
        switch(temp->type){
            case CRITICAL: printf("CRITICAL\n");break;
            case SERIOUS: printf("SERIOUS\n");break;
            case STABLE: printf("STABLE\n");break;
        }
        temp = temp->next;
    }
}

int main(){
    struct patient* head = NULL;
    struct patient* head2 = NULL;

    int N = 0;
    int id, choice;
    char name[50];
    char statusType[20];

    printf("Enter the number of operations\n");
    scanf("%d", &N);

    printf("Hospital management system\n");
    for(int i=0;i<N;i++){
        printf("1. Add a patient record\n");
        printf("2. Remove the next patient for treatment\n");
        printf("3. Display the records\n");

        scanf("%d", &choice);

        switch(choice){
            case 1: 
            printf("enter the patient id:");
            scanf("%d",&id);
            getchar();
            printf("enter the patient name:");
            scanf("%[^\n]",name);
            getchar();
            printf("enter the patient type:");
            scanf("%[^\n]",statusType);

            status type;
            if(strcmp(statusType, "CRITICAL") == 0 ) type = CRITICAL;
            else if(strcmp(statusType, "SERIOUS")== 0) type = SERIOUS;
            else type = STABLE;

            head = addpatient(head, id, name, type);
            break;

            case 2:
            head = nextPatient(head);
            break;

            case 3:
            displayAllPatientRecords(head);
            break;

            default:
            printf("Invalid\n");
        }
    }
    return 0;
}