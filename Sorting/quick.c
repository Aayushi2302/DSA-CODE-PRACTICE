#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *A,int l,int h){

    int pivot = A[l];
    int i = l,j = h;
    do{
        do{
            i++;
        }while(A[i]<=pivot);
        do{
            j--;
        }while(A[j]>pivot);
        if(i<j) swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}

void Quicksort(int *A,int l,int h){
    int j;
    if(l<h){
        j = partition(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    }
}

int main(){

    int A[] = {7,8,2,3,12,0};
    int n = sizeof(A)/sizeof(int);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    Quicksort(A,0,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}