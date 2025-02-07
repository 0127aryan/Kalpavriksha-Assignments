#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

#define TABLE_SIZE 10

struct Node{
    int data;
    int key;
    struct Node* next;
};

struct Node* hashtable[TABLE_SIZE];

int hash(int key){
    return key % TABLE_SIZE;
}

void put(int key, int data){
    int index = hash(key);
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) return;

    newNode->data = data;
    newNode->key = key;
    newNode->next = NULL;

    struct Node* current = hashtable[index];
    struct Node* prev = NULL;

    while(current != NULL){
        if(current->key == key){
            current->data = data;
            free(newNode);
            return;
        }
        prev = current;
        current = current->next;
    }

    if(prev == NULL){
        hashtable[index] = newNode;
    } else{
        prev->next = newNode;
    }
}

void search(int key){
    int index = hash(key);
    struct Node* current = hashtable[index];

    while(current != NULL){
        if(current->key == key){
            printf("Value: %d\n",current->data);
            return;
        }
    }
}

void delete(int key){
    int index = hash(key);
    struct Node* current = hashtable[index];
    struct Node* prev = NULL;

    while(current != NULL){
        if(current->key == key){
            if(prev == NULL){
                hashtable[index] = current->next;
            } else{
                prev->next = current->next;
            }
            free(current);
            printf("Deleted key: %d\n",key);
            return;
        }

        prev=current;
        current = current->next;
    }
    printf("%d Key not found\n",key);
}

void display(){
    printf("Hash Table: \n");
    for(int i=0;i<TABLE_SIZE;i++){
        struct Node* current = hashtable[i];
       
        if(current != NULL){
            printf("Index %d:",i);
        while(current != NULL){
            printf("(%d, %d)",current->key,current->data);
            current = current->next;
            if(current != NULL){
                printf("->");
            }
            
        }
        printf("\n");
    }
    }
}


int main(){
    
        printf("1. Insert in hashMap\n");
        printf("2. Search in hashMap\n");
        printf("3. Delete from HashMap\n");
        printf("4. display the Hashmap\n");
        printf("5. Exit the program\n");
        printf("\n");
        
    int choice, key, data;
    while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the key: ");
                scanf("%d", &key);
                printf("Enter the value: ");
                scanf("%d", &data);

                put(key,data);
                break;
            
                
            case 2:
                printf("Enter the key: ");
                scanf("%d",&key);          
                search(key);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d",&key);

                delete(key);
                break;
            
            case 4:
                display();
                break;
                
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
            printf("Invalid Choice\n");
            return 1;    
        }
    }

    return 0;
}