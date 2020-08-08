#include<cstdio>
#include<algorithm>
#include<iostream> 
#define maxn 505
#define INF 0x3fffffff
 
using namespace std;

int Cmax,N,Sp,M;
int G[maxn][maxn];//一条边的权重 
int way1[maxn];//到各个顶点的前驱点 【按车数多为原则】 
int way2[maxn];//到各个顶点的前驱点 【按车数少为原则】 
int dis[maxn];//到各顶点的距离 
int isVisit[maxn];//各顶点的 访问信息 
int num1[maxn];//表示到各个顶点的车的数量  【按车多的原则】 
int num2[maxn];//表示到各个顶点的车的数量  【按车少的原则】 
int cap[maxn];//当前每个station的容量 

void init(){
	fill(G[0],G[0]+maxn*maxn,INF);//将图顶点的之间距离设置为INF 
	fill(dis,dis+maxn,INF);	
	fill(isVisit,isVisit+maxn,0);
	fill(num1,num1+maxn,0);//初始情况都为0 
}

void dijkstra(int s){
	dis[s] = 0; //到自身的距离为0 
	num1[s] = 0; //源点的车数 为 0 
	int i,j,v; 
	for(i = 0;i<= N;i++){
		int MIN = INF, u = -1; 
		for(j = 0;j<= N;j++){
			if(isVisit[j] == 0 && dis[j] < MIN){//更新值 
				u = j;
				MIN = dis[j] ;
			}
		}
		
		isVisit[u] = 1;
		//作为中间节点开始比较更新 		
		for(v = 0;v<=N;v++){
			if(isVisit[v] == 0 && G[u][v] != INF){//如果未访问，且存在边 
				if(dis[v] > dis[u] + G[u][v]){
					dis[v] = dis[u] + G[u][v];//更新最短路径 
					num1[v] = num1[u] + cap[v];//更新城市的车数 
					way1[v] = u;//更新路径前驱 					
				}
				else if(dis[v] == dis[u] + G[u][v]){//如果距离相等 ，需要注意这里是if - else if 
					if(num1[u] > (num1[v] - cap[v]) ){
						num1[v] = num1[u] + cap[v] ;//更新城市的车数 	
						way1[v] = u;
					}
				} 
			} 
		} 
	}
}

int main(){	
	cin >>Cmax>>N>>Sp>>M;
	int i,j;
		
	for(i = 1;i <= N;i++){//station 的下标从1开始 
		cin >> cap[i]; 
	}
	
	int ver1,ver2;//边的两个顶点 
	int weight; 

	init();		
	while(M--){
		cin >> ver1 >> ver2 >> weight;
		G[ver1][ver2] = weight; 
		G[ver2][ver1] = weight; 
	} 
	
	//起始点都是s = 0 
	dijkstra(0);
	
//	cout <<"距离信息\n" ;
//	for(i = 1;i<= N;i++){
//		cout <<"i = "<<i<<", "<< dis[i]<<"\n";
//	}
//	cout <<"车数信息\n"; 
//	for(i = 1;i<= N;i++){
//		cout <<"i = "<<i<<", "<< num[i]<<"\n";
//	}
//	
//	cout<<"路径信息\n";	
//	for(i = 1;i<=N;i++) {
//		cout <<"i = "<<i<<", "<< way[i]<<"\n";
//	}cout<<"\n";
	
	int anw[maxn];//用于保存路径信息
	int tempDes = Sp;
	int index = 0;
	while(way1[tempDes]!=tempDes){
		anw[index++] = tempDes;
		tempDes = way1[tempDes];
	} 
	anw[index] = 0;
	
	int need;
	need = (Cmax * index /2) - num1[Sp];
	if(need < 0) cout <<"0 " ; //如果不需要发送车子 
	else cout << need <<" ";
	for(i = index;i >=0;i--){
		cout << anw[i];
		if(i!=0) cout<<"->"; 
		
	}cout <<" ";
	
	int backNum = 0;//需要退回的数量 
	if(need < 0){
		backNum = num1[Sp] - (Cmax * index /2);
	}
	cout << backNum ;
}
/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

10 3 3 5
16 17 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

10 3 1 5
16 17 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1


10 3 1 5
1 1 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

10 3 3 5
1 1 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

*/

