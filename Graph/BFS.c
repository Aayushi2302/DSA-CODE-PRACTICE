#include<stdio.h>
#include<stdlib.h>
#include "queu.h"

void BFS(int A[][7],int start,int n){

    int i = start,u;
    int visited[7] = {0};

    printf("%d ",i);
    visited[i] = 1;
    enqueue(i);

    while(!isempty()){

        u = dequeue();
        for(int v=1; v <= n ; v++){
            if(A[u][v] == 1 && visited[v] == 0){
                printf("%d ",v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void DFS(int A[][7],int start,int n){
    
    static int visited[7] = {0};
    int u = start;

    if(visited[u] == 0){
        
        printf("%d ",u);
        visited[u] = 1;
        for(int v=1 ; v <= n ; v++){
            if(A[u][v] == 1 && visited[v] == 0)
                DFS(A,v,n);
        }
    }
}

int main(){

    int A[7][7] =   {
                        {0,0,0,0,0,0,0},
                        {0,0,1,1,0,0,0},
                        {0,1,0,0,1,0,0},
                        {0,1,0,0,1,0,0},
                        {0,0,1,1,0,1,1},
                        {0,0,0,0,1,0,0},
                        {0,0,0,0,1,0,0}
                    };

    BFS(A,3,7);
    printf("\n");
    DFS(A,4,7);

    return 0;
}