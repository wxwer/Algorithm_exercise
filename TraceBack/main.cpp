#include <stdio.h>
#include <queue>
#define INF 999999
#define N 6
using namespace std;


void branch(int G[][N],int k){
	int cost[N];
	queue<int> qq;
	int t;
	for(int i=0;i<N;i++){
        cost[i]=INF;
	}
	cost[k]=0;
	qq.push(k);
	while(!qq.empty()){
		t=qq.front();
		qq.pop();
		for(int i=0;i<N;i++){
			if(G[t][i]!=INF && cost[t]+G[t][i]<cost[i]){
				cost[i]=cost[t]+G[t][i];
				qq.push(i);
			}
		}
	}
	for(int i=0;i<N;i++){
		printf("cost[%d]:%d\n",i,cost[i]);
	}
}

int cost[N];
void DFS(int G[][N],int v){
    if(cost[v]==INF)
        return;
    for(int i=0;i<N;i++){
        if(G[v][i]!=INF && cost[v]+G[v][i]<cost[i]){
            cost[i]=cost[v]+G[v][i];
            DFS(G,i);
        }
    }
}
int main(){
    int G[N][N]={{0,1,2,INF,INF,INF},
             {INF,0,INF,INF,3,5},
             {INF,INF,0,2,INF,INF},
             {INF,INF,INF,0,1,INF},
             {INF,INF,INF,INF,0,1},
             {INF,INF,INF,INF,INF,0}};
    int k=0;
    for(int i=0;i<N;i++)
        cost[i]=INF;
    cost[k]=0;
    DFS(G,k);
	printf("results is:\n");
	for(int i=0;i<N;i++){
		printf("cost[%d]:%d\n",i,cost[i]);
	}
	printf("results2 is:\n");
	branch(G,k);
	return 0;
}
