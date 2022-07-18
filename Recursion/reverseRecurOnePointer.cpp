#include<iostream>
using namespace std;

void swap(int *p,int *q){

	int temp = *p;
	*p = *q;
	*q = temp;
}

void reverseArray(int *arr,int i,int n){

	if(i >= n/2)	return;

	swap(&arr[i],&arr[n-1-i]);
	reverseArray(arr,i+1,n);
}

int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<"The array before swapping : "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";


	int i=0;
	reverseArray(arr,i,n);

	cout<<endl<<"The array after swapping : "<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}