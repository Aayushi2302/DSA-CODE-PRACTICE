#include<bits/stdc++.h>
using namespace std;

void sumOfSubsets(int index,int sum,vector<int> &subsetSum,int *arr,int n){


	if(index >= n){

		subsetSum.push_back(sum);
		return;
	}

	sumOfSubsets(index+1,sum+arr[index],subsetSum,arr,n);
	sumOfSubsets(index+1,sum,subsetSum,arr,n);
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

	vector<int> subsetSum;

	int sum=0,index=0;

	sumOfSubsets(index,sum,subsetSum,arr,n);

	sort(subsetSum.begin(),subsetSum.end());

	for(auto i : subsetSum)
		cout<<i<<" ";

	return 0;

}