#include<cstdio>
#include<iostream>
#define maxn 505
#define INF 0x3fffffff

using namespace std;

int G[maxn][maxn];
int cos[maxn][maxn];//两个顶点边的cost 
int num[maxn]; //表示到某个端点的最小cost 

int isVisit[maxn];//表示这个顶点是否访问过 
int dis[maxn];//到各个顶点的距离 
int way[maxn];//到各个顶点的前驱城市 
int N,M,S,D;


//初始化各个值的操作 
void init(){
	fill(dis,dis+maxn,INF); //到各个顶点的距离都是INF
	fill(isVisit,isVisit+maxn,0);//顶点都未访问 	
	fill(G[0],G[0]+maxn * maxn,INF); 
	fill(num,num+maxn,INF);//初始化到各顶点的cost	
}

//入参是源点 
void dijkstra(int s){
	dis[s] = 0;//到自身的距离为0 
	num[s] = 0;//到自身的cost为0 
	way[s] = s;//到自身的前驱为s
	int i,j,v;		
	for(i = 0;i< N;i++){//从各个顶点中找出dis[]最短的路径 【循环N次，从而保证所有的距离都找了一遍】 
		int MIN = INF,u = -1;//u表示当前正在寻找得到的中间点 
		for(j = 0;j< N;j++){			
			if(isVisit[j]==0 && MIN > dis[j]){
				u = j;
				MIN = dis[j];//更新MIN值 
			}
		}
		
		isVisit[u] = 1;//该顶点已访问 
		for(v = 0;v < N;v ++){
			if(isVisit[v]==0 && G[u][v]!=INF){//如果该节点尚未访问  && u和v之间存在路径 
				if(dis[u] + G[u][v] < dis[v]) {//如果路径最小 
					dis[v] =  dis[u] + G[u][v];//更新最短路径 
					num[v] = num[u]+ cos[u][v];//u本身的cost + u->v 的cost 
					way[v] = u; 
				}
				else if(dis[u] + G[u][v] == dis[v]) {
					if(num[v] > num[u]+ cos[u][v]){//如果之前的num[v] > num[u] + cos[u][v]，则更新 
						num[v] = num[u]+ cos[u][v]; 
						way[v] = u;
					}
				}
			}
		}		
	} 
}

int main(){	
	cin >> N >> M >> S >> D;		
	int i,j;
	
	init();
	for(i = 0;i< M;i++){
		int ver1,ver2;//边的两端点
		int distance,cost; 		
		cin >> ver1>> ver2 >> distance >>cost;
		G[ver1][ver2] = distance;
		G[ver2][ver1] = distance;
		cos[ver1][ver2] = cost;
		cos[ver2][ver1] = cost; 
	}
		
	if(S == D){
		cout << S <<" "<< D << " 0 0\n";
		return 0;
	}
			
	dijkstra(S);
	
	//保存正向路径的结果集 
	int anw[maxn];
	int index = 0;
	int tempD = D;
	while(way[tempD]!=tempD){	
		anw[index++] = way[tempD];
		tempD = way[tempD];
	}
	
	for(i = index -1;i >=0 ;i--){
		cout << anw[i]<<" "; 
	}
	cout << D <<" "<< dis[D]<<" "<<num[D]<<"\n";
}
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20


4 5 0 0
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/
