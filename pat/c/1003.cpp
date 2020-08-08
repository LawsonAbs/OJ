#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 1000
const int MAXV=1000;
const int INF=0x3fffffff;
 
using namespace std;

int N,M,C1,C2;
int G[maxn][maxn];//存储顶点间边的信息
int weight[maxn] ;//各个顶点的权重 

//先求最短距离
bool vis[MAXV]={false};//表示已经访问过的节点，初始值都是为false，未访问; 如果为true，则表示已访问 
int d[MAXV] ; //dis中保留的是 源点到目标城市的访问距离 ，初始的情况下，距离都是最大值 

int pre[MAXV];//到顶点v的前驱节点 
int way[MAXV];//令起点s到顶点u的最短路径条数为num[u] 
int w[MAXV];//表示到各个顶点的最大顶点权之和 

void dijkstra(int s){
	fill(d,d+MAXV,INF);//fill函数将整个d数组赋值为INF 
	fill(way,way+MAXV,0);//将从源点到顶点的路径条数设置为0
		 
	d[s] = 0; //起点到自身的距离为0
	way[s] = 1;//起点到自身的路径为1 
	w[s] = weight[s];//初始化自身的值
		
	int i,j;
	for(i = 0;i< N; i++){
		int u = -1, MIN= INF ;//当前最短路径的这个顶点 	
		for(j = 0;j < N;j++){//第一层 for 循环是用于寻找当前尚未遍历节点中最短的那个路径
			//vis[j] == false => 尚未遍历 
			//最短路径 d[j] < MIN ，然后执行更新操作 
			if(vis[j] == false && d[j] < MIN){ //更新 MIN 值 			
				u = j;
				MIN = d[j];													
			}
		}
		
		if(u == -1)	return;
		vis[u] = true; //对节点u标记为已访问 
		
		//以u为中间节点，对整个未访问的节点执行一次更新操作 
		for(int v = 0; v < N;v++){
			//如果节点v尚未访问 
			//并且有 u->v 的边
			//并且 d[u]+G[u][v] < d[v] 
			if(vis[v] == false && G[u][v]!=INF ){
				if(d[u]+G[u][v] == d[v]) {
					way[v] += way[u] ;//说明到v的最短路径有多条 
					if(w[u] + weight[v] > w[v])	//最短路径相等的情况下，并不更新 
						//只有在w[u] + weight[v] > w[v] 时才更新 
						w[v] = w[u] + weight[v];										
				}
				
				if(d[u]+G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];//优化 d[v] 这个距离					
					pre[v] = u;//计算前驱节点
					way[v] = way[u];
					w[v] = w[u] + weight[v];//因为是最短路径，所以必须更新 
				}				
			}
		}
	}
}

int main(){
	int s;//源点 
	int des;//终点
	 
	cin >> N >> M >> s >>des;
	int i,j;
	int ver1,ver2; 
	int edgeWei;
	fill(G[0],G[0]+MAXV*MAXV,INF);//初始化图G	
	
	//输入各个顶点的权重 
	for(i = 0;i< N;i++){
		cin >> weight[i];
	}
	
	
	for(i = 0;i< M;i++){
		cin >> ver1>> ver2 >> edgeWei;
		G[ver1][ver2] = edgeWei;//输入边之间的权重 
		G[ver2][ver1] = edgeWei;//输入边之间的权重 
	}
	
	dijkstra(s);
//	for(i = 0;i< N;i++){
//		cout << d[i] <<" ";
//	}cout <<"\n";
	
//	cout<<"===========\n";
//	for(i = 0;i < N;i++) {
//		cout <<i<<"的前驱节点是："<< pre[i]<<"\n";
//	}
	
	
//	cout<<"===========\n";
//	for(i = 0;i < N;i++) {
//		cout <<i<<"的路径有："<< way[i]<<"\n";
//	}
	
	cout << way[des] <<" "<< w[des]; 
//	for(i = 0;i< N;i++){
//		cout <<i <<"收集到的人手有："<< w[i]<<"\n"; 
//	} 
}
/*
6 8 0
10 2 1 5 3 4
0 1 2
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2 
3 4 3
4 5 3

5 6 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1 
*/
