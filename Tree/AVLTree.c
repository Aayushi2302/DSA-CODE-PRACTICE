//Given input provided in main uses all 4 rotations to become balanced tree 
#include<stdio.h>
#include<stdlib.h>

struct Node {

    struct Node *left;
    int data;
    int height; //to calculate balance factor
    struct Node *right;
};

struct Node *root = NULL;

int NodeHeight(struct Node *p){

    int hl,hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl>hr ? hl+1 : hr+1;  
}

int BalanceFactor(struct Node *p){
    
    int hl,hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl-hr;

}

struct Node * LLRotation(struct Node *p){

    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;

}

struct Node * LRRotation(struct Node *p){

    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;
    
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;

}

struct Node * RLRotation(struct Node *p){

    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    p->right = prl->left;
    pr->left = prl->right;

    prl->left = p;
    prl->right = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;

}

struct Node * RRRotation(struct Node *p){
    
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;

    return pr;

}

struct Node *insert(struct Node *t,int key){

    struct Node *p;
    if(t == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->height = 1;
        p->left = p->right = NULL;
        return p;
    }
    if(key < t->data)
        t->left = insert(t->left,key);
    else if(key > t->data) 
        t->right = insert(t->right,key);

    t->height = NodeHeight(t);
    
    if(BalanceFactor(t) == 2 && BalanceFactor(t->left) == 1)
       return LLRotation(t);
    else if(BalanceFactor(t) == 2 && BalanceFactor(t->left) == -1)
       return LRRotation(t);
    else if(BalanceFactor(t) == -2 && BalanceFactor(t->right) == -1)
       return RRRotation(t);
    else if(BalanceFactor(t) == -2 && BalanceFactor(t->right) == 1)
        return RLRotation(t);

    return t;
}


void inorder(struct Node *t){
    
    if(t){

        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}

int main(){


    root = insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,25);
    insert(root,28);
    insert(root,27);
    insert(root,5);
    

    inorder(root);

    return 0;
}