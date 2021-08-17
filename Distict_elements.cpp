#include<iostream>
using namespace std;

//To check distinct elements in an array
int main(){
	int N,flag=0;			
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
		
	for(int i=0;i<N;i++){					  								       
		for(int j=i+1;j<N;j++){
			if(arr[i]==arr[j]){				   
				flag++;						  
				break;																	
			}
		}
	}
	
	if(flag!=0)
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}


