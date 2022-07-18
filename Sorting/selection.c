#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int *A,int n){

    int k;
    for(int i=0;i<n;i++){
        for(int j=k=i;j<n;j++){

            if(A[j] < A[k])
                k = j;
        }
        swap(&A[k],&A[i]);
    }
}

int main(){

    int A[] = {7,8,2,3,12,0};
    int n = sizeof(A)/sizeof(int);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    selection(A,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}