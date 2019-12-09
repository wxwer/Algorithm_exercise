#include <iostream>
#include "FuncDefine.h"
#include <math.h>
#define N 5
#define MAX 65535
using namespace std;

int Binomial1(int n,int k){
    int C[n+1][n+1],m;
    for(int i=1;i<=n;i++){
        m=k>i?i:k;
        for(int j=1;j<=m;j++){
            if(j==0 || i==j)
                C[i][j]=0;
            else
                C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    return C[n][k];
}
int Binomial(int n,int k){
    if(k==0 || k==n)
        return 1;
    return Binomial(n-1,k-1)+Binomial(n-1,k);
}
void MajorElem(int A[],int n){
    int mj=A[1],count=1;
    for(int i=1;i<n;i++){
        if(mj==A[i]){
            count++;
        }
        else
            count--;
        if(count==0){
            mj=A[i];
            count=1;
        }
    }
    cout<<mj<<endl;
}
int RussianMul(int m,int n){
    if(n==1){
        return m;
    }
    if(n%2==0)
        return 2*RussianMul(m,n/2);
    else
        return 2*RussianMul(m,(n-1)/2)+m;
}
void printSubSet(int A[],int n,int s){
    for(int i=0;i<n;i++){
        if(s&(1<<i))
            cout<<A[i]<<" ";
        if(i==n-1)
            cout<<endl;
    }
}
void Perm1(int A[],int Len,int n){
    if(n==0){
        printArray(A,Len);
        return;
    }
    for(int i=0;i<n;i++){
        Perm1(A,Len,n-1);
        if(n%2==0)
            swap(A[0],A[n]);
        else
            swap(A[i],A[n]);
    }
}
void Perm(int A[],int Len,int n){
    if(n==0){
        printArray(A,Len);
        return;
    }
    for(int i=0;i<n;i++){
        swap(A[i],A[n]);
        Perm(A,Len,n-1);
        swap(A[i],A[n]);
    }
}
int countSum(int A[],int n){
    int interval=1;
    while(interval<n){
        for(int i=0;i+interval<n;i+=interval){
            A[i]+=A[i+interval];
        }
        interval=interval*2;
    }
    return A[0];
}
int maxDevide(int A[],int l,int r){
    if(l==r)
        return A[r];
    else if(r==l+1)
        return max(A[l],A[r]);
    int mid=(l+r)/2;
    int ml=maxDevide(A,l,mid),mr=maxDevide(A,mid+1,r);
    return max(ml,mr);
}
int numLen(int m){
    if(m==0)
        return 1;
    if(m<0)
        m=m*-1;
    int n=0;
    while(m!=0){
        n++;
        m=m/10;
    }
    return n;
}

int bigIntMul(int x,int y){
    int sig=1;
    int a=fabs(x),b=fabs(y);
    if(x==0 || y==0)
        return 0;
    else if((x>0&&y>0) || (x<0&&y<0))
        sig=1;
    else
        sig=-1;
    int n1=numLen(a),n2=numLen(b);
    if(n1==1 || n2==1)
        return sig*a*b;
    int pn1=(int)pow(10,n1/2),pn2=(int)pow(10,n2/2);
    int A=a/pn1,B=a%pn1;
    int C=b/pn2,D=b%pn2;
    int AC=bigIntMul(A,C),BD=bigIntMul(B,D);
    int AD=bigIntMul(A,D),BC=bigIntMul(B,C);
    return sig*(AC*pn1*pn2+AD*pn1+BC*pn2+BD);
}

void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        if(i<n-1)
            cout<<A[i]<<" ";
        else
            cout<<A[i]<<endl;
    }
}
void minimumTree(int G[][N],int n){
    int i,j,min,k;
    int lowcost[N],adjvex[N];
    lowcost[0]=0;
    for(i=1;i<n;i++){
        lowcost[i]=G[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<n;i++){
        min=MAX;
        k=0;
        for(j=1;j<n;j++){
            if(lowcost[j]!=0 && lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
        }
        cout<<"("<<adjvex[k]<<","<<k<<")"<<" ";
        lowcost[k]=0;
        for(j=1;j<n;j++){
            if(lowcost[j]!=0 && lowcost[j]>G[k][j]){
                lowcost[j]=G[k][j];
                adjvex[j]=k;
            }
        }
    }
}
