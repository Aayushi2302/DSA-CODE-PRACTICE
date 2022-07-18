//This is the pattern 1 of printing all the permutations of an array
#include<bits/stdc++.h>
using namespace std;

void printPermutation(vector<int> &result,int *freq,int *arr,int n){

	if(result.size() == n){
		for(auto i : result)
			cout<<i<<" ";
		cout<<endl;
		return;
	}

	for(int i=0;i<n;i++){

		if(freq[i] == 0){
			
			result.push_back(arr[i]);
			freq[i]=1;
			printPermutation(result,freq,arr,n);
			result.pop_back();
			freq[i]=0;
		}
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

	vector<int> result;
	int freq[n]={0};


	printPermutation(result,freq,arr,n);

	return 0;
}