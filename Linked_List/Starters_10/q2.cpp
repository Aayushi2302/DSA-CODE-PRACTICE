#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        int N,sum=0;
        cin>>N;
        int A[N],B[N-1];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N-1;i++)
            cin>>B[i];
        for(int i=0;i<N;i++){
            for(int j=1;j<N;j++){
                if(i==j)
                    continue;
                else{
                    for(int k=2;k<N;k++){
                        if(i==k||j==k)
                            continue;
                        else{
                            sum+=A[i]+A[j]+A[k];
                            

                        }
                    }
                }
            }
        }

            
    }
}