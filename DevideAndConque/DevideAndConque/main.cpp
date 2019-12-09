#include <iostream>
#include "FuncDefine.h"
#define N1 5
#define N2 10
#define MAX 65535
using namespace std;

int main()
{
    int A[N1]={3,2,1,4,3};
    int G[N1][N1]={{0,2,MAX,1,3},{2,0,4,MAX,MAX},{MAX,4,0,6,3},{1,MAX,6,0,2},{3,MAX,3,2,0}};
    int a=100;
    cout<<Binomial1(1000,5)<<endl;
    //MajorElem(A,N1);
    //cout<<RussianMul(78,3)<<endl;
    //Perm1(A,N1,N1-1);
    //cout<<countSum(A,N1)<<endl;
    return 0;
}
