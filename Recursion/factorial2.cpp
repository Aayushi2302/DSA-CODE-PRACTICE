#include<iostream>
using namespace std;

int returnFact(int n){


	if(n == 1)	return 1;

	return n*returnFact(n-1);
}

int main(){


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);

	#endif


	int n;
	cin>>n;

	cout<<"Factorial of "<<n<<" is : "<<returnFact(n);
	return 0;
}