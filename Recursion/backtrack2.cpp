#include<iostream>
using namespace std;

void printBack(int i,int n){

	if(i > n)	return;

	printBack(i+1,n);
	cout<<i<<" ";
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	int i=1;
	printBack(i,n);



	return 0;
}