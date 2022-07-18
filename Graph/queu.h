#include<stdio.h>
#include<stdlib.h>
#define size 20

int front = -1,rear = -1;
int arr[20];

int isfull(){

    if(rear == size-1){
        return 1;
    }
    return 0;
}

void enqueue(int value){

    if(isfull()){
        printf("\nThe Queue is Full !!\n");
    }
    else{

        if(front == -1) front = 0;
        rear++;
        arr[rear] = value;
    }

}

int isempty(){

    if(front == -1 && front == rear)
        return 1;
    return 0;
}

int dequeue(){

    if(isempty()){
        printf("\nThe Queue is Empty !!\n");
    }
    else{
        //printf("\nThe element to be deleted is : %d",arr[front]);
        int x =arr[front];
        front++;

        if(front == rear+1){
            front = rear = -1;
        }
        return x;
    }
}
