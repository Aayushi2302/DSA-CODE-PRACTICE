#include<bits/stdc++.h>
using namespace std;

void printUniqCombination(int index,int target,vector<int> &sub,vector<int> &arr,int n){

		if(target == 0){

			if(sub.size() == 0)	cout<<"{}";

			else{

				for(auto i : sub)
					cout<<i<<" ";
			}
			cout<<endl;
			return;
		}

	for(int i=index;i<n;i++){

		if(arr[i] > target)	break;

		if(i > index && arr[i] == arr[i-1])	continue;

		sub.push_back(arr[i]);
		printUniqCombination(i+1,target-arr[i],sub,arr,n);
		sub.pop_back();
	}		
		
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end());

	int target;
	cin>>target;

	vector<int> sub;

	printUniqCombination(0,target,sub,arr,n);

	return 0;
}