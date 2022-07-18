#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int *A,int n){

    int flag;
    for(int i=0;i<n;i++){
        flag = 0;
        for(int j=0;j<(n-1-i);j++){

            if(A[j] > A[j+1]){
                swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

int main(){

    int A[] = {7,8,2,3,12,0};
    int n = sizeof(A)/sizeof(int);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    bubble(A,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}