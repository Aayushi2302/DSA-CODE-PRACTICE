#include<stdio.h>
#include<stdlib.h>

struct Node {

    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *root = NULL;

struct Stack {

    int size;
    int top;
    struct Node **arr;
};

int isEmpty(struct Stack obj){

    if(obj.top == -1)  return 1;
    return 0;
}

void push(struct Stack *obj,struct Node *temp){

    obj->arr[++(obj->top)] = temp;

}

struct Node *pop(struct Stack *obj){

    struct Node *t = obj->arr[obj->top];
    --(obj->top);
    return t;
}

int stkTop(struct Stack obj){

    struct Node *t = obj.arr[obj.top];
    return t->data;
}


void generateBST(int *post,int n){

    struct Node *t,*p;

    struct Stack stk;
    stk.size = n;
    stk.top = -1;
    stk.arr = (struct Node **)malloc(stk.size*sizeof(struct Node *));

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = post[n-1];
    t->left = t->right = NULL;
    root = t;
    p = root;

    int i = n-2;
    while(i >= 0){

        if(post[i] > p->data){

            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = post[i--];
            t->left = t->right = NULL;
            p->right = t;
            push(&stk,p);
            p = t;

        }
        else{

            if(isEmpty(stk) || post[i] > stkTop(stk)){

                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = post[i--];
                t->left = t->right = NULL;
                p->left = t;
                p = t;
            }
            else{
                p = pop(&stk);
            }
        }
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

    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    int *post = (int *)malloc(sizeof(int)*n);
    printf("Enter the postorder traversal of tree : \n");
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    
    generateBST(post,n);

    inorder(root);

    return 0;
}