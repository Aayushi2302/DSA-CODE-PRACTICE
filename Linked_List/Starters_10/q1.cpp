#include <stdio.h>

int main(void) {
    int T, N, K, S,ptr,temp,sum,k;
    scanf("%d",&T);
    
    for ( int i = 0; i < T; i++)
    {

        scanf("%d %d %d",&N,&K,&S);
        int arr[N+K-1];
        for ( int j = 1; j <= (N+K); j+=2)
        {

            ptr = j;
            temp = 1;
            k = 0;
            sum = 0;
            
            while (k < N)
            {
                arr[k] = temp;
                sum += temp;
                temp += 2;
                k++;
            }
            
            while (k < (N+K-1))
            {
                arr[k] = ptr;
                sum += ptr;
                k++;
            }
            
            if (sum == S)
            {
                printf("%d\n",ptr);
            }
        }
    }
    return 0;
}

	


	
