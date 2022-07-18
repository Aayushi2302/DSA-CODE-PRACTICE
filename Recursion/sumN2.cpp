#include<iostream>
using namespace std;

int returnSum(int n){


	if(n < 1)	return 0;

	return n+returnSum(n-1);
}



int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n;
	cin>>n;

	cout<<"The sum of first "<<n<<" numebrs is : "<<returnSum(n);

	return 0;
}