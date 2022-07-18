#include<bits/stdc++.h>
using namespace std;


int countSubsequnceWithSumK(int index,int *arr,int k,int sum,int n){

	int l,r;
	if(index >= n){

		if(sum == k)	return 1;
		else	return 0;
	}
	l = countSubsequnceWithSumK(index+1,arr,k,sum+arr[index],n);
	r = countSubsequnceWithSumK(index+1,arr,k,sum,n);
	return l+r;

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

	int k;
	cin>>k;

	int index = 0,sum=0;
	
	cout<<endl<<countSubsequnceWithSumK(index,arr,k,sum,n);


	return 0;
}