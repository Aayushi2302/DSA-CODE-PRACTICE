#include<iostream>
#include<cmath>
using namespace std;


int main(){

    int num;
    cin>>num;

    int n=2,j,flag;

    while(n<=num){

        j=2;
        flag =0;
        
        while(j<=sqrt(num)){

            if(n == j)  j++;

            if(n%j == 0){
                flag++;
            }   

            j++;
        }

        if(flag == 0){

            if(num%n == 0){
                cout<<n<<" ";
                while(num%n == 0)   num/=n;
            }
        }
        n++;
    }
    return 0;
}