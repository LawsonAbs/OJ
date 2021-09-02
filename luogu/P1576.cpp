#include<iostream>
#include<cstdio>
using namespace std;
const int maxN = 2001;
double gra[maxN][maxN] ;
double dis[maxN] ;//dis[i] ��ʾsource -> i��ľ���
int n,m;
const int INF = 1e9;
bool vis[maxN];

//source -> destination
void dijkstra(){
	int cnt = n;// ��ʼ�� 
	while(cnt--){
		int cur_dis = INF,cur_node;
		for (int i = 1;i<=n;i++){
			if(!vis[i]){//����ýڵ�δ���� 
				if(dis[i] < cur_dis){//�ҳ���ǰ��С�ľ��� 	
					cur_dis = dis[i];
					cur_node = i; 	
				}			
			}
		} 
		vis[cur_node] = true;//��ʾ�Ѿ�ȷ���� 
		//ʹ��cur_node��Ϊ�м�ڵ㣬�������¾��� 
		for(int i = 1;i<=n;i++){
			if(gra[cur_node][i]!=1){//�������֮���б� 
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
	fill(dis,dis+maxN,INF);//��ʼ��Ϊ���ֵ 
	fill(vis,vis+maxN,false);
	fill(gra[0],gra[0]+maxN*maxN,1);//��ʼ��Ϊ1 
	for(int i = 0;i< m;i++){
		cin >> a >> b >> c;
		z = c * 0.01; 
		gra[a][b] = z; // Ȩ�� 
		gra[b][a] = z;
	}
	int s,d;//Դ�㣬�յ� 
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
 
