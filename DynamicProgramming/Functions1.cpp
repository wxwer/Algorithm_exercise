
#include "Functions1.h"
#include <stdio.h>
#define M 4
#define N 9
#define E 8
#define MAX 9999999
#include <assert.h>

int w(int g[][E],int i,int k,int j){
    assert((k>i&&k<j));
    return g[i][k]+g[k][j]+g[i][j];
}
void Edges(int vex[][E],int i,int j){
    if(i==j || j==i+1)
       return;
    int k=vex[i][j];
    if(!(i==0&&j==E-1))
        printf("(%d,%d) ",i,j);
    Edges(vex,i,k);
    Edges(vex,k,j);
}
void triangle(){
    int graph[][E]={
      {0, 14, 25, 27, 10, 11, 24, 16},
      {0, 0, 18, 15, 27, 28, 16, 14},
      {0, 0, 0, 19, 14, 19, 16, 10},
      {0, 0, 0, 0, 22, 23, 15, 14},
      {0, 0, 0, 0, 0, 14, 13, 20},
      {0, 0, 0,0, 0, 0, 15, 18},
      {0, 0, 0, 0, 0, 0, 0, 27},
      {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int total[E][E]={0};
    int vex[E][E]={0};
    for(int d=2;d<E;d++){
        for(int j=0;j<E-d;j++){
                int mint=MAX,ik;
                for(int k=j+1;k<j+d;k++){
                    if(total[j][k]+total[k][j+d]+w(graph,j,k,j+d)<mint){
                        mint=total[j][k]+total[k][j+d]+w(graph,j,k,j+d);
                        ik=k;
                    }
                }
                total[j][j+d]=mint;
                vex[j][j+d]=ik;
            }
        }
    printf("\n各三角形的权重之和最小为：%d\n",total[0][7]);
    printf("\n弦的集合为：\n");
    Edges(vex,0,E-1);
    printf("\n");

}



void investProject(){
    int A[M][N] = {{0,0,0,0,0,0,0,0,0},{0, 5, 15, 40, 80, 90, 95, 98, 100},
                         {0, 5, 15, 40, 60, 70, 73, 74, 75},
                         {0, 4, 26, 40, 45, 50, 51, 52, 53}};
    int P[M][N];
    for(int k=0;k<M;k++)
    for(int j=0;j<N;j++){
        if(k==0 || j==0)
            P[k][j]=0;
        else{
            int maxP=0;
            for(int v=0;v<=j;v++){
                if(P[k-1][v]+A[k][j-v]>maxP)
                    maxP=P[k-1][v]+A[k][j-v];
            }
            P[k][j]=maxP;
        }
    }
    printf("将不同金额(0~8万元)投资到三个项目中的获利情况\n");
    for(int i=0;i<N;i++){
        printf("%d \t",P[3][i]);
    }
    printf("\n将8万元投资到三个项目中的最大获利为%d\n",P[3][8]);
}




void manifacture(){
    int x1=1000,p1=8,p2=5;
    float a=0.7,b=0.9;
    int f[7][x1+1];
    f[6][0]=0;

}

void bag0_1(int n,int W[],int V[],int C){
    int f[n+1][C+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=C;j++){
            if(j<W[i])
                f[i][j]=f[i-1][j];
            else{
                f[i][j]=f[i-1][C]>(f[i-1][C-W[i]]+V[i])?f[i-1][C]:(f[i-1][C-W[i]]+V[i]);
            }
        }
    }
    printf("最大价值为：%d",f[n][C]);
}
void printArray(int A[],int n){
    if(A==NULL || n<=0)
        return;
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
