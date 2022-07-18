#include<iostream>
using namespace std;


//Parameterize way
void printSum(int i,int sum){


	if(i < 1){
		cout<<sum;
		return;
	}
	printSum(i-1,sum+i);
}

int main(){

	#ifndef ONLINE__JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int i=n,sum=0;
	printSum(i,sum);

	return 0;
}