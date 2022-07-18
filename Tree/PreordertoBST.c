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

    if(obj.top == -1)   return 100000000;
    struct Node *t = obj.arr[obj.top];
    return t->data;
}

void generateBST(int *pre,int n){

    struct Node *t,*p;

    struct Stack stk;
    stk.size = n;
    stk.top = -1;
    stk.arr = (struct Node **)malloc(stk.size*sizeof(struct Node *));

    int i = 0;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = pre[i++];
    t->left = t->right = NULL;
    root = t;
    p = root;

    while(i < n){

        if(pre[i] < p->data){

            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = pre[i++];
            t->left = t->right = NULL;
            p->left = t;
            push(&stk,p);
            p = t;

        }
        else{

            if(pre[i] > p->data && pre[i] < stkTop(stk)){

                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = pre[i++];
                t->left = t->right = NULL;
                p->right = t;
                p = t;
            }
            else
                p = pop(&stk);
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

    int *pre = (int *)malloc(sizeof(int)*n);
    printf("Enter the preorder traversal of tree : \n");
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    
    generateBST(pre,n);

    inorder(root);

    return 0;
}
