#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node *left;
    struct Node *right;

};
struct Node *root = NULL;

struct Node *insert(struct Node *t,int key){

    struct Node *p;
    if(t == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->left = p->right = NULL;
        return p;
    }
    if(key < t->data)
        t->left = insert(t->left,key);
    else if(key > t->data) 
        t->right = insert(t->right,key);
    return t;
}


void inorder(struct Node *t){

    if(t){

        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}

struct Node *search(struct Node *t,int key){

    if(t == NULL)
        return NULL;
    else if(t->data == key)
        return t;
    else if(t->data > key)
        return search(t->left,key);
    else    
        return search(t->right,key);
}

int Height(struct Node *t){

    int x,y;
    if(t != NULL){
        x = Height(t->left);
        y = Height(t->right);
        if(x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

struct Node *Predecessor(struct Node *t){

    while(t &&t->right != NULL)
        t = t->right;
    return t;
}

struct Node *Successor(struct Node *t){

    while(t &&t->left != NULL)
        t = t->left;
    return t;
}

struct Node *delete(struct Node *t,int key){
    
    struct Node *p;
    if(t == NULL)
        return NULL;
    if(t->left == NULL && t->right == NULL){  

        if(t == root)
            root = NULL;  
        free(t);
        return NULL;
    }

    if(key < t->data)
        t->left = delete(t->left,key);
    else if(key > t->data)
        t->right = delete(t->right,key);
    else{

        if(Height(t->left) > Height(t->right)){
            p = Predecessor(t->left);
            t->data = p->data;
            t->left = delete(t->left,p->data);
        }
        else{
            p = Successor(t->right);
            t->data = p->data;
            t->right = delete(t->right,p->data);
        }

    }
    return t;
}

int main(){

    root = insert(root,9);
    insert(root,15);
    insert(root,5);
    insert(root,20);
    insert(root,16);
    insert(root,8);
    insert(root,12);
    insert(root,3);
    insert(root,6);
    insert(root,20);

    inorder(root);
    struct Node *temp ;
    temp = search(root,25);
    if(temp != NULL)
        printf("\nElement %d found!!\n",temp->data);
    else    
        printf("\nElement not found!!\n");

    delete(root,9);
    inorder(root);
    printf("\n");
    delete(root,5);
    inorder(root);
    printf("\n");
    delete(root,16);
    inorder(root);
    printf("\n");
    delete(root,15);
    inorder(root);
    printf("\n");
    delete(root,6);
    inorder(root);
    printf("\n");
    delete(root,20);
    inorder(root);
    printf("\n");
    delete(root,12);
    inorder(root);
    printf("\n");
    delete(root,8);
    inorder(root);
    printf("\n");
    delete(root,3);
    inorder(root);
    printf("\n");



    return 0;
}