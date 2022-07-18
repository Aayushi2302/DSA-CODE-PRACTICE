//This is second pattern to print the permutation of an array/string in O(n!*n) time complexity but constant space complexity except the auxiliary space
#include<bits/stdc++.h>
using namespace std;

void swap(int &p,int &q){

	int temp = p;
	p = q;
	q = temp;
}

void printPermuatation(int index,int *arr,int n){

	if(index == n){

		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}

	for(int i=index;i<n;i++){

		swap(arr[i],arr[index]);
		printPermuatation(index+1,arr,n);
		swap(arr[i],arr[index]);
	}
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

	int index=0;

	printPermuatation(index,arr,n);

	return 0;
}