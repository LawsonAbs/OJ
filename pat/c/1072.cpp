#include<cstdio> 
#include<algorithm>
#include<iostream>
#include<cstring>
#define maxn 1025
#define INF 0x3fffffff 

using namespace std;

struct result{
	double minDis,avgDis;
	int sta; //最终的那个加油站下标 
}; 

result anw[maxn];
int N,M,K,D; 
//N的最大值是1000, M的 最大值是10 
int G[maxn][maxn];
int visit[maxn]; 
int dis[maxn];//到各个顶点的距离

int cmp(result r1,result r2){
	if(r1.minDis == r2.minDis) {
		if(r1.avgDis == r2.avgDis) return r1.sta < r2.sta;	
		return r1.avgDis < r2.avgDis;	
	}
	return r1.minDis > r2.minDis;	
} 

void init(){	
	fill(dis,dis+maxn,INF);//重置dis距离	
	fill(visit,visit+maxn,0);//重置访问信息	
}

//获取G1的真正地址 
int getSta(char ch[]){
	int res = 0;
	int len = strlen(ch);
	int flag = 0;
	int i = 0;
	if(ch[0]!='G'){
		while( i < len){
			res = res*10 +(ch[i] - '0');
			i++;	
		}		
	}
	else{
		i = 1;
		while( i < len){
			res = res*10 +(ch[i] - '0');
			i++;	
		}
		flag = 1;
	}
	if (flag == 1) return res+N;
	else return res;
}

void dijkstra(int s){
	dis[s] = 0;
	int i ,j,v;
	for(i = 1;i <= N+M;i++ ){
		int u = -1, MIN = INF;
		for(j = 1; j <= N+M;j++ ){
			if(visit[j] == 0 && dis[j] < MIN){
				u = j; 
				MIN = dis[j]  ;
			}			
		}
		
		visit[u] = 1;
		for(v = 1;v <= N+M;v++){
			if(visit[v]==0 && G[u][v]!=INF){
				if(dis[v] > G[u][v]+dis[u]){
					dis[v] = G[u][v]+dis[u];//更新最短值 
				}
			}
		}
	}
}


int main(){
	cin >> N >> M >> K >> D; 
	int i,j;
	char c1[maxn], c2[maxn];
	int wei;
	int ver1,ver2; 	
	fill(G[0],G[0]+maxn*maxn,INF);
	for(i = 0;i < K;i++){
		cin >> c1 >> c2 >> wei;
		ver1 = getSta(c1);
		ver2 = getSta(c2);		
		G[ver1][ver2] = wei;
		G[ver2][ver1] = wei;		
	}
	
	
//	for(i = 1;i<= N+M;i++){
//		for(j = 1;j<= N+M;j++){
//			if(G[i][j]!=INF)	cout << G[i][j]<<" ";			 
//			else cout <<"- ";
//		}cout <<"\n";
//	}		
	double totalDis;
	double d1; //d1 代表的是station 到居民楼的最短距离 
	int flag ;
	int index = 0;
	//计算各个加油站的参数
	for(i = N+1;i<= N+M;i++){
		init();
		d1 = INF;
		totalDis = 0;		
		flag = 1;
		dijkstra(i);
		for(j = 1;j<= N;j++){
			if(dis[j] > D){
				flag = 0;
				break;		
			}
			totalDis += dis[j];	
			if( dis[j] < d1) d1 = dis[j];			
			//cout <<dis[j]<<" "; 
		}//cout <<"\n";		
		if(flag == 1 ){
			anw[index].avgDis = totalDis/ N ;//求出平均距离 
			anw[index].minDis = d1;	//求出最小的distance 
			anw[index].sta = i - N;		
			index++; 
		}
	}
	
	if(index == 0)	cout <<"No Solution\n";	
	else {
		sort(anw,anw+index,cmp);
		printf("G%d\n%.1f %.1f",anw[0].sta,anw[0].minDis,anw[0].avgDis+0.01); 	
	}
}
/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2


4 3 11 5
1 2 2
1 4 2
1 G2 4
1 G1 3
2 3 2
2 G1 1
3 4 2
3 G3 2
4 G2 3
G1 G2 1
G3 G1 2


4 3 4 5
1 2 2
1 4 2
1 G1 4
1 G2 3

4 11 6 5
1 2 2
1 4 2
1 G11 4
1 G2 3
1 G4 3
1 G5 3

*/
