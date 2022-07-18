#include<stdio.h>


int getMax(int A[],int n){
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i] > max)  max = A[i];
    }
    return max;
}

void countingsort(int A[],int n,int place){
    int output[n];
    int count[10] ;
    
    for(int i=0;i<n;i++)    count[i] = 0;

    for(int i=0;i<n;i++)
        count[(A[i]/place)%10]++;

    for(int i=1;i<n;i++)
        count[i] += count[i-1];

    for(int i=n-1;i>=0;i--){

        output[count[(A[i]/place)%10]-1] = A[i];
        count[(A[i]/place)%10]--;
    }

    for(int i=0;i<n;i++)
        A[i] = output[i];
}

void radixsort(int A[],int n){

    int maximum = getMax(A,n);

    for(int place=1 ; maximum/place>0 ; place*=10 )
        countingsort(A,n,place);
}


int main(){

    int A[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(A)/sizeof(A[0]);

    printf("The array before sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    radixsort(A,n);

    printf("\nThe array after sorting : \n");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}