#include <iostream>
#include "Functions1.h"
#define N1 5
using namespace std;

int main()
{
    int A[N1]={1,3,5,6,3};
    int W[6] = { 0 , 2 , 3 , 4 , 3 ,2};			//��Ʒ�����2��3��4��5
	int V[6] = { 0 , 3 , 4 , 5 , 6 ,5};			//��Ʒ�ļ�ֵ3��4��5��6
	int C = 8;					        //������С
	//bag0_1(5,W,V,C);
	//investProject();
	//triangle();
	optimal_BST();
    return 0;
}
