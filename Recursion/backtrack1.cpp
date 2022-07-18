#include<iostream>
using namespace std;


void printBack(int i,int n){

	if(i < 1)	return;

	printBack(i-1,n);
	cout<<i<<" ";
}

int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	int i=n;
	printBack(i,n);


	return 0;

}