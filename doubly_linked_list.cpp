#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;
void create(int num,struct Node *&temp){

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;

}

void insertAtTail(int num){

    struct Node *newnode;
    create(num,newnode);

    struct Node *ptr = head;

    while(ptr->next != NULL){

        ptr = ptr->next;
    }

    newnode->prev = ptr;
    ptr->next = newnode;
}

void insertAtHead(int num){

    struct Node *newnode;
    create(num,newnode);

    head->prev = newnode;
    newnode->next = head;
    head= newnode;

}

void insertAtPos(int num,int pos){

    struct Node *newnode;
    create(num,newnode);

    struct Node *ptr = head;
    int count = 0;
    bool flag = false;


    while(ptr != NULL){

        count++;
        if(count == pos){

            flag = true;
            ptr->prev->next = newnode;
            newnode->prev  = ptr->prev;
            newnode->next = ptr;
            ptr->prev = newnode;

            break;

        }
        ptr = ptr->next;
    }

    if(!flag)  
        printf("Position does nort exist !!\n");
}

void deleteAtHead(){

    struct Node *temp = head;
    printf("Item to be deleted : \n");
    printf("%d\n",temp->data);

    head = head->next;
    head->prev = NULL;

    free(temp);
}

void deleteAtTail(){

    struct Node *ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    printf("Item to be deleted :\n ");
    printf("%d\n",ptr->data);

    ptr->prev->next = NULL;
    ptr->prev = NULL;
    free(ptr);
}

void deleteAtPos(int pos){

    struct Node *ptr = head;
    int count = 0;
    bool flag = false;

    while(ptr != NULL){
        count++;
        if(count == pos){

            flag = true;

            printf("Item to be deleted : \n");
            printf("%d\n", ptr->data);

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->prev = NULL;
            ptr->next = NULL;

            free(ptr);
        }
        ptr = ptr->next;
    }

    if(!flag)
        printf("Position does not exist !!\n");
}

void display(){

    struct Node *ptr = head;
    while(ptr != NULL){

        printf("%d", ptr->data);
        printf("->");
        ptr = ptr->next;
    }

    printf("NULL\n");
}

int main(){

    struct Node *n1;
    create(1,n1);
    head = n1;

    insertAtTail(2);
    insertAtTail(3);
    insertAtTail(4);
    insertAtTail(5);

    display();

    insertAtHead(0);

    display();

    insertAtPos(5,3);

    display();

    deleteAtHead();

    display();

    deleteAtTail();

    display();

    deleteAtPos(3);

    display();
    
    return 0;
}