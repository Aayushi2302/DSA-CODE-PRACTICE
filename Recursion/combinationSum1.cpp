#include<bits/stdc++.h>
using namespace std;


void printSubWithSum(int index,int target,vector<int> sub,int *arr,int n){


	if(index >= n){

		if(target == 0){

			if(sub.size() == 0)
				cout<<"{}";
			else{

				for(auto i : sub)
				cout<<i<<" ";
			}
			
			cout<<endl;
		}
		return;
	}

	if((target-arr[index]) >= 0){
		sub.push_back(arr[index]);
		printSubWithSum(index,target-arr[index],sub,arr,n);
		sub.pop_back();
	}	
	
	printSubWithSum(index+1,target,sub,arr,n);
	

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
	
	int target,index=0;
	cin>>target;

	vector<int> sub;

	printSubWithSum(index,target,sub,arr,n);

	return 0;
}