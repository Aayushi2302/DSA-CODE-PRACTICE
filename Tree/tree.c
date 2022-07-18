#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue{

    int size;
    int front,rear;
    struct Node **arr;

};

struct Stack{

    int size;
    int top;
    struct Node **arr;
};

struct Node *Root = NULL;

void enqueue(struct Queue *Q,struct Node *temp){

    if(Q->front == 0 && Q->rear == Q->size-1){
        printf("\nQueue is Full!!\n");
    }
    else{
        if(Q->front == -1){
            ++Q->front;
        }
        ++Q->rear;
        Q->arr[Q->rear] = temp;
        //printf("%d ",Q->rear);
    }
}

struct Node* dequeue(struct Queue *Q){

    if(Q->front == -1)
        printf("\nQueue is Empty!!\n");
    else{

        struct Node *temp = Q->arr[Q->front];
        Q->front++;
        if(Q->front == Q->rear+1){
            Q->front = -1;
            Q->rear = -1;
        }
        return temp;
    }
}

int isEmpty(struct Queue *Q){

    if(Q->front == -1) return 1;
    return 0;
}

void create(int size){

    struct Queue Q;
    Q.size = size;
    Q.front = Q.rear = -1;
    Q.arr = (struct Node **)malloc(sizeof(struct Node *)*Q.size);

    struct Node *t,*p;
    int val;
    printf("Enter root value : ");
    scanf("%d",&val);
    Root = (struct Node *)malloc(sizeof(struct Node));
    Root->data = val;
    Root->left = NULL;
    Root->right = NULL;
    enqueue(&Q,Root);
    //printf("%u %u",Root,Q->arr[0]);
    while(!isEmpty(&Q)){

        p = dequeue(&Q);
        printf("Enter the value to left of %d : ",p->data);
        scanf("%d",&val);
        if(val != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->left = NULL;
            t->right = NULL;
            p->left = t;
            enqueue(&Q,t);

        }

        printf("Enter the value to right of %d : ",p->data);
        scanf("%d",&val);
        if(val != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            enqueue(&Q,t);

        }
    }
}


int Empty(struct Stack *t){

    if(t->top == -1)    return 1;
    return 0;
}

struct Node * pop(struct Stack *t){

    if(t->top == -1){
        printf("\nStack is already empty!!\n");
    }
    else{

        struct Node *temp = t->arr[t->top];
        --t->top;
        return temp;
    }
}

void push(struct Stack *t,struct Node *temp){

    if(t->top == t->size-1){
        printf("\nStack is already full!!\n");
    }
    else{
        ++t->top;
        t->arr[t->top] = temp; 
    }
}

//With Recursion Treversal
/* void preorder(struct Node *temp){

    if(temp){

        printf("%d ",temp->data);
        preorder(temp->left);
        preorder(temp->right);

    }   
} */

/* void inorder(struct Node *temp){

    if(temp){

        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
    }
}*/

/* void postorder(struct Node *temp){

    if(temp){

        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
} */

//Without Recursion
void preorder(struct Node *temp,int size){
    
    struct Stack stk;
    stk.size = size;
    stk.top = -1;
    stk.arr = (struct Node **)malloc(size*sizeof(struct Node *));

    while(temp != NULL || !Empty(&stk)){

        if(temp == NULL){

            temp = pop(&stk);
            temp = temp->right;
        }
        else{
            printf("%d ",temp->data);
            push(&stk,temp);
            temp = temp->left;
        }
    }
}

void inorder(struct Node *temp,int size){
    
    struct Stack stk;
    stk.size = size;
    stk.top = -1;
    stk.arr = (struct Node **)malloc(size*sizeof(struct Node *));

    while(temp != NULL || !Empty(&stk)){

        if(temp == NULL){

            temp = pop(&stk);
            printf("%d ",temp->data);
            temp = temp->right;
        }
        else{ 
            push(&stk,temp);
            temp = temp->left;
        }
    }
}

void postorder(struct Node *temp,int size){

    struct Stack S1,S2;
    S1.size = S2.size = size;
    S1.top = S2.top = -1;
    S1.arr = (struct Node **)malloc(size*sizeof(struct Node *));
    S2.arr = (struct Node **)malloc(size*sizeof(struct Node *));

    if(temp != NULL){
        push(&S1,temp);
    }

    while(!Empty(&S1)){

        temp = pop(&S1);
        push(&S2,temp);
        if(temp->left != NULL)
            push(&S1,temp->left);
        if(temp->right != NULL)
            push(&S1,temp->right);
    }

    while(!Empty(&S2)){

        temp = pop(&S2);
        printf("%d ",temp->data);
    }
}

int main(){

    int size;
    printf("Enter the number of nodes in the tree : ");
    scanf("%d",&size);
    
    create(size);

    printf("Preorder : \n");
    preorder(Root,size);
    printf("\nInorder : \n");
    inorder(Root,size);
    printf("\nPostorder : \n");
    postorder(Root,size);

    return 0;
}