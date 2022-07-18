//This code is used to print all the subsequences of the string using recursion
#include<bits/stdc++.h>
using namespace std;

void printSubsequenceRecur(int index,vector<int> &sub,int arr[],int n){

	if(index >= n){

		for(auto it : sub)
			cout<<it<<" ";
		

		if(sub.size() == 0)
			cout<<"{}";

		cout<<endl;
		return;
	}

	sub.push_back(arr[index]);
	printSubsequenceRecur(index+1,sub,arr,n);
	sub.pop_back();
	printSubsequenceRecur(index+1,sub,arr,n);
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

	vector<int> sub;

	int index=0;

	printSubsequenceRecur(index,sub,arr,n);

	return 0;
}