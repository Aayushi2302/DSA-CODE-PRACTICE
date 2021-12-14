#include<iostream>
using namespace std;

bool search(int *a,int size,int key){

    for(int i=0;i<size;i++){

        if(a[i] == key) return true;
    }
    return false;
}

int main(){
    
    int *A,*B,*C,m,n;
    cout<<"Enter the size of array 1 and array 2 : "<<endl;
    cin>>m>>n;

    A = new int[m];
    B = new int[n];
    C = new int[m+n];

    cout<<"Enter elements of array 1 : "<<endl;
    for(int i=0;i<m;i++)    cin>>A[i];
    cout<<"Enter elements of array 2 : "<<endl;
    for(int i=0;i<n;i++)    cin>>B[i];

    int k = 0;
    for(int i=0;i<n;i++){

        if(search(A,m,B[i]))    C[k++]  =   B[i];
        else    continue;
    }

    cout<<"Intersection elements : "<<endl;
    for(int i=0;i<k;i++)    cout<<C[i]<<" ";

    return 0;
}