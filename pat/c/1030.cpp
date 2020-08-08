#include<cstdio>
#include<iostream>
#define maxn 505
#define INF 0x3fffffff

using namespace std;

int G[maxn][maxn];
int cos[maxn][maxn];//��������ߵ�cost 
int num[maxn]; //��ʾ��ĳ���˵����Сcost 

int isVisit[maxn];//��ʾ��������Ƿ���ʹ� 
int dis[maxn];//����������ľ��� 
int way[maxn];//�����������ǰ������ 
int N,M,S,D;


//��ʼ������ֵ�Ĳ��� 
void init(){
	fill(dis,dis+maxn,INF); //����������ľ��붼��INF
	fill(isVisit,isVisit+maxn,0);//���㶼δ���� 	
	fill(G[0],G[0]+maxn * maxn,INF); 
	fill(num,num+maxn,INF);//��ʼ�����������cost	
}

//�����Դ�� 
void dijkstra(int s){
	dis[s] = 0;//������ľ���Ϊ0 
	num[s] = 0;//�������costΪ0 
	way[s] = s;//�������ǰ��Ϊs
	int i,j,v;		
	for(i = 0;i< N;i++){//�Ӹ����������ҳ�dis[]��̵�·�� ��ѭ��N�Σ��Ӷ���֤���еľ��붼����һ�顿 
		int MIN = INF,u = -1;//u��ʾ��ǰ����Ѱ�ҵõ����м�� 
		for(j = 0;j< N;j++){			
			if(isVisit[j]==0 && MIN > dis[j]){
				u = j;
				MIN = dis[j];//����MINֵ 
			}
		}
		
		isVisit[u] = 1;//�ö����ѷ��� 
		for(v = 0;v < N;v ++){
			if(isVisit[v]==0 && G[u][v]!=INF){//����ýڵ���δ����  && u��v֮�����·�� 
				if(dis[u] + G[u][v] < dis[v]) {//���·����С 
					dis[v] =  dis[u] + G[u][v];//�������·�� 
					num[v] = num[u]+ cos[u][v];//u�����cost + u->v ��cost 
					way[v] = u; 
				}
				else if(dis[u] + G[u][v] == dis[v]) {
					if(num[v] > num[u]+ cos[u][v]){//���֮ǰ��num[v] > num[u] + cos[u][v]������� 
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
		int ver1,ver2;//�ߵ����˵�
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
	
	//��������·���Ľ���� 
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
