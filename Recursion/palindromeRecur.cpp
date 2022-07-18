#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str,int i){

	if(i >= str.size()/2)	return true;

	if(str[i] != str[str.size()-1-i])
		return false;
	isPalindrome(str,i+1);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	string str;
	cin>>str;

	int i=0;

	cout<<isPalindrome(str,i);

	return 0;
}