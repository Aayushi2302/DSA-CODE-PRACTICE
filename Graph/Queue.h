#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int i){

    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue is Full\n");
    else{

        t->data = i;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x = -1;
    struct Node *t;
    if(front == NULL)
        printf("Queue is Empty\n");
    else{
        t = front;
        front = front->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isEmpty(){
    if(front == NULL)
        return 1;
    return 0;
}