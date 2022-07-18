#include<iostream>
using namespace std;

void swap(int *p,int *q){

	int temp = *p;
	*p = *q;
	*q = temp;
}


void reverseArray(int *arr,int l,int r){


	if(l >= r)	return;

	swap(&arr[l],&arr[r]);

	reverseArray(arr,l+1,r-1);


}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int arr[5]; 

	for(int i=0;i<5;i++)
		cin>>arr[i];

	cout<<"The array before swapping : "<<endl;

	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";

	int l=0,r=4;
	reverseArray(arr,l,r);

	cout<<endl<<"The array after swapping : "<<endl;

	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";

	return 0;
}