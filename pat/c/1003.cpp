#include<cstdio>
#include<algorithm>
#include<iostream>
#define maxn 1000
const int MAXV=1000;
const int INF=0x3fffffff;
 
using namespace std;

int N,M,C1,C2;
int G[maxn][maxn];//�洢�����ߵ���Ϣ
int weight[maxn] ;//���������Ȩ�� 

//������̾���
bool vis[MAXV]={false};//��ʾ�Ѿ����ʹ��Ľڵ㣬��ʼֵ����Ϊfalse��δ����; ���Ϊtrue�����ʾ�ѷ��� 
int d[MAXV] ; //dis�б������� Դ�㵽Ŀ����еķ��ʾ��� ����ʼ������£����붼�����ֵ 

int pre[MAXV];//������v��ǰ���ڵ� 
int way[MAXV];//�����s������u�����·������Ϊnum[u] 
int w[MAXV];//��ʾ�������������󶥵�Ȩ֮�� 

void dijkstra(int s){
	fill(d,d+MAXV,INF);//fill����������d���鸳ֵΪINF 
	fill(way,way+MAXV,0);//����Դ�㵽�����·����������Ϊ0
		 
	d[s] = 0; //��㵽����ľ���Ϊ0
	way[s] = 1;//��㵽�����·��Ϊ1 
	w[s] = weight[s];//��ʼ�������ֵ
		
	int i,j;
	for(i = 0;i< N; i++){
		int u = -1, MIN= INF ;//��ǰ���·����������� 	
		for(j = 0;j < N;j++){//��һ�� for ѭ��������Ѱ�ҵ�ǰ��δ�����ڵ�����̵��Ǹ�·��
			//vis[j] == false => ��δ���� 
			//���·�� d[j] < MIN ��Ȼ��ִ�и��²��� 
			if(vis[j] == false && d[j] < MIN){ //���� MIN ֵ 			
				u = j;
				MIN = d[j];													
			}
		}
		
		if(u == -1)	return;
		vis[u] = true; //�Խڵ�u���Ϊ�ѷ��� 
		
		//��uΪ�м�ڵ㣬������δ���ʵĽڵ�ִ��һ�θ��²��� 
		for(int v = 0; v < N;v++){
			//����ڵ�v��δ���� 
			//������ u->v �ı�
			//���� d[u]+G[u][v] < d[v] 
			if(vis[v] == false && G[u][v]!=INF ){
				if(d[u]+G[u][v] == d[v]) {
					way[v] += way[u] ;//˵����v�����·���ж��� 
					if(w[u] + weight[v] > w[v])	//���·����ȵ�����£��������� 
						//ֻ����w[u] + weight[v] > w[v] ʱ�Ÿ��� 
						w[v] = w[u] + weight[v];										
				}
				
				if(d[u]+G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];//�Ż� d[v] �������					
					pre[v] = u;//����ǰ���ڵ�
					way[v] = way[u];
					w[v] = w[u] + weight[v];//��Ϊ�����·�������Ա������ 
				}				
			}
		}
	}
}

int main(){
	int s;//Դ�� 
	int des;//�յ�
	 
	cin >> N >> M >> s >>des;
	int i,j;
	int ver1,ver2; 
	int edgeWei;
	fill(G[0],G[0]+MAXV*MAXV,INF);//��ʼ��ͼG	
	
	//������������Ȩ�� 
	for(i = 0;i< N;i++){
		cin >> weight[i];
	}
	
	
	for(i = 0;i< M;i++){
		cin >> ver1>> ver2 >> edgeWei;
		G[ver1][ver2] = edgeWei;//�����֮���Ȩ�� 
		G[ver2][ver1] = edgeWei;//�����֮���Ȩ�� 
	}
	
	dijkstra(s);
//	for(i = 0;i< N;i++){
//		cout << d[i] <<" ";
//	}cout <<"\n";
	
//	cout<<"===========\n";
//	for(i = 0;i < N;i++) {
//		cout <<i<<"��ǰ���ڵ��ǣ�"<< pre[i]<<"\n";
//	}
	
	
//	cout<<"===========\n";
//	for(i = 0;i < N;i++) {
//		cout <<i<<"��·���У�"<< way[i]<<"\n";
//	}
	
	cout << way[des] <<" "<< w[des]; 
//	for(i = 0;i< N;i++){
//		cout <<i <<"�ռ����������У�"<< w[i]<<"\n"; 
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
