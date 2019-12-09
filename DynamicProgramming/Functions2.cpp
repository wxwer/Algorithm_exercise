
#include "Functions1.h"
#include <stdio.h>
#define N 6
#define MAX 99999

void optimal_BST(){
    float P[N]={0,0.15,0.10,0.05,0.10,0.20};
    float Q[N]={0.05,0.10,0.05,0.05,0.05,0.10};
    float e[N+1][N];
    float w[N+1][N];
    int root[N+1][N]={0};
    for(int i=1;i<=N;i++){
        e[i][i-1]=Q[i-1];
        w[i][i-1]=Q[i-1];
    }
    for(int l=0;l<N-1;l++){
        for(int j=1;j<N;j++){
            int i=j-l;
            e[i][j]=MAX;
            w[i][j]=w[i][j-1]+P[j]+Q[j];
            for(int r=i;r<=j;r++){
                float t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(e[i][j]>t){
                    e[i][j]=t;
                    root[i][j]=r;
                }
            }
        }
    }
    printf("最优解为：%.2f",e[1][N-1]);
}
