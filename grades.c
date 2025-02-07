#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
}Grade;

struct student{
    char* studentName;
    Grade grade;
    struct student* next;
};

struct student* createStudent(char* name, Grade grade){
    struct student* newStudent = (struct student*) malloc(sizeof(struct student));

    if(newStudent == NULL) return NULL;

    newStudent->studentName = (char*) malloc(strlen(name) + 1);
    if(newStudent->studentName == NULL) return NULL;
    strcpy(newStudent->studentName, name);
    newStudent->grade = grade;

    newStudent->next = NULL;
    return newStudent;
}

struct student* addStudent(struct student* head, char* name, Grade grade){
    struct student* newStudent = createStudent(name, grade);

    if(newStudent == NULL) return head;

    if(head == NULL || head->grade < grade){
        newStudent->next = head;
        head = newStudent;

        return head;
    }
    struct student* current = head;
    while(current->next != NULL && current->next->grade <= grade){
        current = current->next;
    }
    newStudent->next = current->next;
    current->next = newStudent;

    return head;
}

void printData(struct student* head){
    if(head == NULL) return;

    struct student* temp = head;

    while(temp != NULL){
        printf("Student name: %s , Grade: ", temp->studentName);
        switch(temp->grade){
            case A: printf("A\n"); break;
            case B: printf("B\n"); break;
            case C: printf("C\n"); break;
            case D: printf("D\n"); break;
            case E: printf("F\n"); break;
        }
        temp = temp->next;
    }
}

int main(){
    struct student* head = NULL;

    int n = 0;
    int choice;
    char name[50];
    char studentGrade[2];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("1. Add the student and their grade\n");
        printf("2. display the lift\n");

        scanf("%d",&choice);
        switch(choice){
           
            case 1:
             getchar();
        printf("Enter the name: ");
        fgets(name, sizeof(name), stdin);
        printf("enter the grade between A-F: ");
        scanf("%s",studentGrade);
        Grade grade;
        if(strcmp(studentGrade, "A")==0) grade = A;
        else if(strcmp(studentGrade, "B")==0) grade = B;
        else if(strcmp(studentGrade, "C")==0) grade = C;
        else if(strcmp(studentGrade, "D")==0) grade = D;
        else grade = E;

        head = addStudent(head, name, grade);
        break;

        case 2:
        printData(head);
        break;
    }
    }
    return 0;
}
