#include<stdio.h>
#include<stdlib.h>

void insertion(int *A,int n){
    int j,x;
    for(int i=1;i<n;i++){
        j = i-1;
        x = A[i];
        while(j>-1 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){

    int A[] = {7,8,2,3,12,0};
    int n = sizeof(A)/sizeof(int);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    insertion(A,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}