#include<iostream>
using namespace std;

void printFact(int i,int fact){


	if(i == 1){
		cout<<fact;
		return;
	}

	printFact(i-1,fact*i);

}

int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int i=n,fact=1;
	printFact(i,fact);

	return 0;
}