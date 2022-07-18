#include<bits/stdc++.h>
using namespace std;

int returnFibbo(int i){

	if(i <= 1)	return  i;

	return returnFibbo(i-1)+returnFibbo(i-2);
}

int main(){
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	cout<<returnFibbo(n);
	return 0;
}