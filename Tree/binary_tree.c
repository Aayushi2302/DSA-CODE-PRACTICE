#include<stdio.h>
#include<stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Queue{

    int size;
    int front,rear;
    struct Node **arr;
};

struct Node *Root = NULL;

void enqueue(struct Queue *Q,struct Node *temp){

    if(Q->front == 0 && Q->rear == Q->size-1)
        printf("Queue is already Full!!\n");
    else{

        if(Q->front == -1)
            Q->front ++;
        Q->rear ++;
        Q->arr[Q->rear] = temp;
    }
}

int isEmpty(struct Queue Q){

    if(Q.front == -1)  return 1;
    return 0;
}

struct Node* dequeue(struct Queue *Q){

    if(Q->front == -1)
        printf("Queue is already Empty!!\n");
    else{

        struct Node *t = Q->arr[Q->front];
        Q->front ++;
        if(Q->front == Q->rear + 1){
            Q->front = Q->rear = -1;
        }
        return t;
    }
}

void create(int n){

    struct Queue Q;
    Q.size = n;
    Q.front = Q.rear = -1;
    Q.arr = (struct Node **)malloc(sizeof(struct Node *)*n);

    int val;
    struct Node *p,*t;
    printf("Enter the value of root : ");
    scanf("%d",&val);

    Root = (struct Node *)malloc(sizeof(struct Node));
    Root->data = val;
    Root->left = NULL;
    Root->right = NULL;

    enqueue(&Q,Root);

    while(!isEmpty(Q)){

        p = dequeue(&Q);
        printf("Enter the value that you want to insert to left of %d : ",p->data);
        scanf("%d",&val);
        if(val != -1){

            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&Q,t);

        }
        printf("Enter the value that you want to insert to right of %d : ",p->data);
        scanf("%d",&val);
        if(val != -1){

            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = val;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&Q,t);

        }
    }
}

void deleteDepth(struct Node *dnode,int n){

    struct Queue Q;
    Q.size = n;
    Q.rear = Q.front = -1;
    Q.arr = (struct Node **)malloc(sizeof(struct Node *)*n);

    enqueue(&Q,Root);
    struct Node *p;

    while(!isEmpty(Q)){

        p = dequeue(&Q);
        if(p->right){
            if(p->right == dnode){
                p->right = NULL;
                free(dnode);
                return;
            }
            else    enqueue(&Q,p->right);
        }
        if(p->left){
            if(p->left == dnode){
                p->left = NULL;
                free(dnode);
                return;
            }
            else    enqueue(&Q,p->left);
        }
    }
}
struct Node * deletion(int key,int n){

    if(Root == NULL)    return NULL;
    if(Root->left == NULL && Root->right == NULL){

        if(Root->data == key)   return NULL;
        else    return Root;
    }

    struct Queue Q;
    Q.size = n;
    Q.rear = Q.front = -1;
    Q.arr = (struct Node **)malloc(sizeof(struct Node *)*n);

    struct Node *p,*key_node = NULL;
    enqueue(&Q,Root);

    while(!isEmpty(Q)){

        p = dequeue(&Q);
        if(p->data == key)
            key_node = p;
        if(p->left){
            enqueue(&Q,p->left);
        }
        if(p->right){
            enqueue(&Q,p->right);
        }
    }
    if(key_node != NULL){

        int x = p->data;
        deleteDepth(p,n);
        key_node->data = x;
    }
}

void inorder(struct Node *t){

    if(t){

        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);

    }
}


int main(){

    int size;
    printf("Enter the number of nodes : ");
    scanf("%d",&size);
    create(size);
    inorder(Root);

    int key;
    printf("Enter the element that you want to delete : ");
    scanf("%d",&key);
    Root = deletion(key,size);
    inorder(Root);

    return 0;
}