#include<bits/stdc++.h>
using namespace std;

void printNonDuplicateSubsets(int index,vector<int> sub,int *arr,int n){


	if(sub.size() == 0)	cout<<"[]";
	else{
		cout<<"[ ";
		for(auto i : sub)
			cout<<i<<" ";
		cout<<"]";
	}
	cout<<endl;

	for(int i=index;i<n;i++){

		if(i > index && arr[i]==arr[i-1])	continue;

		sub.push_back(arr[i]);
		printNonDuplicateSubsets(i+1,sub,arr,n);
		sub.pop_back();
	}
}

int main(){


	#ifndef ONLINEJUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);

	int index=0;
	vector<int> sub;


	printNonDuplicateSubsets(index,sub,arr,n);

	return 0;
}