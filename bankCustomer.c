#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    PREMIUM = 3,
    REGULAR = 2,
    SAVINGS =1
}Account;

struct customer{
    int customerId;
    char *name;
    Account type;
    struct customer* next;
};

struct customer* createCustomer(int id, char *name, Account type){
    struct customer* newCustomer = (struct customer*) malloc(sizeof(struct customer));
    if(newCustomer == NULL) return NULL;

    newCustomer->customerId = id;

    newCustomer->name = (char *)malloc(strlen(name) + 1);
    if(newCustomer->name == NULL) return NULL;
    strcpy(newCustomer->name, name);
    newCustomer->type = type;

    newCustomer->next = NULL;
    return newCustomer;
}

struct customer* addCustomer(struct customer* head, int id, char* name, Account type){
    struct customer* newCustomer = createCustomer(id, name, type);
    if(newCustomer == NULL) return head;

    if(head == NULL || head->type < type){
        newCustomer->next = head;
        head = newCustomer;

        return head;
    }

    struct customer* current = head;
    while(current->next != NULL && current->next->type >= type){
        current = current->next;
    }

    newCustomer->next = current->next;
    current->next = newCustomer;

    return head;
}

struct customer* serverNextCustomer(struct customer* head){
    if(head == NULL) return NULL;

    
        struct customer* temp = head;
        head = head->next;
        free(temp->name);
        free(temp);        
    
    return head;
}

void displayWaitingCustomer(struct customer* head){
    struct customer* temp = head;
    if(temp == NULL) return;

    while(temp!= NULL){
        printf("Customer Id: %d, Customer name: %s, account type: ", temp->customerId, temp->name);
        switch(temp->type){
            case PREMIUM: printf("PREMIUM\n");break;
            case REGULAR: printf("REGULAR\n");break;
            case SAVINGS: printf("SAVINGS\n");break;
        }
        temp = temp->next;
    }

}

int main(){

    struct customer* head = NULL;
    int n = 0;
    int choice, id;
    char name[50];
    char accEnum[20];

    printf("enter the number of operations\n");
    scanf("%d", &n);

    printf("Bank Customers Management:\n");
    for(int i=0;i<n;i++){
        printf("1. add customer\n");
        printf("2. server the next customer.\n");
        printf("3. display waiting customers\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("enter customer Id\n");
            scanf("%d",&id);
            getchar();
            printf("enter customer name.\n");
            scanf("%[^\n]",name);
            getchar();
            printf("enter customer type.\n");
            scanf("%[^\n]",accEnum);
            Account customerType;
            if(strcmp(accEnum, "PREMIUM")==0) customerType = PREMIUM;
            else if(strcmp(accEnum, "REGULAR")==0) customerType = REGULAR;
            else customerType = SAVINGS;

            head = addCustomer(head, id, name, customerType);
            break;

            case 2:
            head = serverNextCustomer(head);
            break;

            case 3:
            displayWaitingCustomer(head);
            break;

            default:
            printf("invalid operations\n");
        }
    }

    return 0;
}