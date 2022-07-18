//prints only those subbsequences whose sum is k

//This code is used to print all the subsequences of the string using recursion
#include<bits/stdc++.h>
using namespace std;

bool printSubsequenceRecur(int index,vector<int> &sub,int arr[],int n,int sum,int k){

	if(index >= n){

		if(sum == k){
			for(auto it : sub)
				cout<<it<<" ";
			if(sub.size() == 0)
				cout<<"{}";
			cout<<endl;
			return true;

		}
		else return false;	
	}

	sub.push_back(arr[index]);
	if(printSubsequenceRecur(index+1,sub,arr,n,sum+arr[index],k))	
		return true;

	sub.pop_back();
	if(printSubsequenceRecur(index+1,sub,arr,n,sum,k))
		return true;
	return false; 
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

	int index=0,sum=0,k;
	cin>>k;

	int check = printSubsequenceRecur(index,sub,arr,n,sum,k);

	if(check == 1)
		cout<<"Subsequence with given sum "<<k<<" is printed"<<endl;
	else
		cout<<"Subsequence with given sum "<<k<<" does not exist"<<endl;

	return 0;
}