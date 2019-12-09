#include <iostream>
#include "Functions1.h"
#define N1 5
using namespace std;

int main()
{
    int A[N1]={1,3,5,6,3};
    int W[6] = { 0 , 2 , 3 , 4 , 3 ,2};			//商品的体积2、3、4、5
	int V[6] = { 0 , 3 , 4 , 5 , 6 ,5};			//商品的价值3、4、5、6
	int C = 8;					        //背包大小
	//bag0_1(5,W,V,C);
	//investProject();
	//triangle();
	optimal_BST();
    return 0;
}
