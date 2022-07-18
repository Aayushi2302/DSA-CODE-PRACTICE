#include<stdio.h>
#include<stdlib.h>

void copy(int *A,int *temp,int l,int h){

    for(int i=l;i<=h;i++)
        A[i] = temp[i];
}

void merging(int *A,int *temp,int l1,int u1,int l2,int u2){

    int i = l1,j = l2,k = l1;
    while(i <= u1 && j <= u2){
        if(A[i] < A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while(i <= u1)
        temp[k++] = A[i++];

    while(j <= u2)
        temp[k++] = A[j++];
}

void Mergesort(int *A,int l,int u){
    int mid,temp[10];
    if(l < u){
        mid = (l+u)/2;
        Mergesort(A,l,mid);
        Mergesort(A,mid+1,u);
        merging(A,temp,l,mid,mid+1,u);
        copy(A,temp,l,u);
    }
}

int main(){

    int A[] = {7,8,2,3,12,0};
    int n = sizeof(A)/sizeof(int);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    Mergesort(A,0,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}