#include<cstdio> 
#include<algorithm>
#include<iostream>
#include<map>
#define maxn 205
#define INF 0x3fffffff 

using namespace std;

int G[maxn][maxn];
int dis[maxn];
int way[maxn];
int hap[maxn];
int vis[maxn];
int num[maxn]; //存储起始点到每个节点的幸福值 
int roa[maxn]; //到节点的路径条数 
int N,K;

void init(){
	fill(G[0],G[0]+maxn*maxn,INF);//最大值为INF 
	fill(way,way+maxn,-1);//初始化的路径为-1 
	fill(dis,dis+maxn,INF);
	fill(vis,vis+maxn,0);
	fill(num,num+maxn,0);
	fill(roa,roa+maxn,0);
}

//开始dijkstra 算法 
void dijkstra(int s){
	dis[s] = 0;
	way[s] = 0;
	num[s] = 0;
	roa[s] = 1; //初始情况下，到自身的距离为 1 
	int i,j,v;
	for(i = 0;i< N;i++){
		int MIN = INF,u= -1;
		for(j =0;j< N;j++){
			if(vis[j]==0 && dis[j] < MIN){
				MIN = dis[j]; 
				u = j;
			}
		} 
		
		vis[u]  = 1;//u节点已访问 
		//找出节点 
		for(v = 0;v < N;v++){
			if(vis[v]==0 && G[u][v] !=INF ){
				if(dis[v] > dis[u] + G[u][v] ) {
					way[v] = u; //更新路径前驱
					dis[v] = dis[u] + G[u][v];//更新最短路径
					num[v] = num[u] + hap[v]; 
					roa[v] = roa[u]; 
				}
				
				else if(dis[v] == dis[u] + G[u][v] ) { //如果最短路径相同 					
					roa[v] += roa[u];
					if( num[v] - hap[v] < num[u]) {//如果幸福值比较小
						num[v] = hap[v] + num[u];//更新幸福值 
						way[v] = u;//更新路径前驱
					}
				}
			}	
		}
	}
}

int main(){
	cin >> N >>K;
	map<string,int> stoi;
	map<int,string> itos;
	
	int i,j;
	string staLoc;//开始的位置 
	cin >> staLoc;
	
	stoi[staLoc] = 0;//将初始点加入到 map中 
	itos[0]= staLoc;
	
	string tempLoc;
	int tempHap;
	init();
	for(i = 1;i< N ;i++){
		cin >> tempLoc >> tempHap;
		stoi[tempLoc]= i;
		itos[i] = tempLoc;
		hap[i] = tempHap;//加入每个节点的幸福值		 		
	}
	
	string loc1,loc2;
	int len;
	for(i = 0;i< K;i++){
		cin >> loc1 >> loc2 >> len;
		G[stoi[loc1]][stoi[loc2]] = len;
		G[stoi[loc2]][stoi[loc1]] = len;
	} 
	
	dijkstra(0);
	int des = stoi["ROM"];//得到 ROM 的下标 
	//cout <<"des = "<<des<<"\n";
	int tempDes = des;
	int index = 0;//路径数 
	int anw[maxn]; 
	
//	cout <<"前驱\n";
//	for(i =0;i<N;i++){
//		cout << way[i] << " "; 
//	} cout <<"\n";
//	
//	cout<<"路径条数\n";
//	for(i =0;i<N;i++){
//		cout << roa[i] << " "; 
//	} cout <<"\n";
//	
//	cout<<"路径距离\n";
//	for(i =0;i<N;i++){
//		cout << dis[i] << " "; 
//	} cout <<"\n";
	
	while(tempDes!=way[tempDes]){	
		anw[index]  = tempDes;
		index ++;
		tempDes = way[tempDes];
	}
	anw[index] = tempDes;//开始的起点城市 
	cout << roa[des] <<" "<< dis[des] <<" " << num[des] << " "<<num[des]/index <<"\n";
	
	//cout <<"index = "<<index<<"\n";
	for(i = index ;i>=0;i--){
		cout << itos[anw[i]] ;
		if(i != 0) cout <<"->"	;
	}	
}
/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

*/
