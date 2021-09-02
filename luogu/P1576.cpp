#include<iostream>
#include<cstdio>
using namespace std;
const int maxN = 2001;
double gra[maxN][maxN] ;
double dis[maxN] ;//dis[i] 表示source -> i点的距离
int n,m;
const int INF = 1e9;
bool vis[maxN];

//source -> destination
void dijkstra(){
	int cnt = n;// 初始化 
	while(cnt--){
		int cur_dis = INF,cur_node;
		for (int i = 1;i<=n;i++){
			if(!vis[i]){//如果该节点未访问 
				if(dis[i] < cur_dis){//找出当前最小的距离 	
					cur_dis = dis[i];
					cur_node = i; 	
				}			
			}
		} 
		vis[cur_node] = true;//表示已经确认了 
		//使用cur_node作为中间节点，迭代更新距离 
		for(int i = 1;i<=n;i++){
			if(gra[cur_node][i]!=1){//如果两者之间有边 
				double temp =  (dis[cur_node]/(1.0-gra[cur_node][i])); 
				if(!vis[i] && dis[i] > temp){
					dis[i] = temp;
				}
			}
		}
	} 
}

int main(){
	cin >> n >> m;
	int a,b,c;
	double z;
	fill(dis,dis+maxN,INF);//初始化为最大值 
	fill(vis,vis+maxN,false);
	fill(gra[0],gra[0]+maxN*maxN,1);//初始化为1 
	for(int i = 0;i< m;i++){
		cin >> a >> b >> c;
		z = c * 0.01; 
		gra[a][b] = z; // 权重 
		gra[b][a] = z;
	}
	int s,d;//源点，终点 
	cin >> s >> d;
	dis[s] = 100; 
	dijkstra(); 
	printf("%0.8f",dis[d]);  
}
/*
3 2                                    
1 2 1
1 3 3
1 3
*/
 
