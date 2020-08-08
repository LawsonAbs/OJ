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
int num[maxn]; //�洢��ʼ�㵽ÿ���ڵ���Ҹ�ֵ 
int roa[maxn]; //���ڵ��·������ 
int N,K;

void init(){
	fill(G[0],G[0]+maxn*maxn,INF);//���ֵΪINF 
	fill(way,way+maxn,-1);//��ʼ����·��Ϊ-1 
	fill(dis,dis+maxn,INF);
	fill(vis,vis+maxn,0);
	fill(num,num+maxn,0);
	fill(roa,roa+maxn,0);
}

//��ʼdijkstra �㷨 
void dijkstra(int s){
	dis[s] = 0;
	way[s] = 0;
	num[s] = 0;
	roa[s] = 1; //��ʼ����£�������ľ���Ϊ 1 
	int i,j,v;
	for(i = 0;i< N;i++){
		int MIN = INF,u= -1;
		for(j =0;j< N;j++){
			if(vis[j]==0 && dis[j] < MIN){
				MIN = dis[j]; 
				u = j;
			}
		} 
		
		vis[u]  = 1;//u�ڵ��ѷ��� 
		//�ҳ��ڵ� 
		for(v = 0;v < N;v++){
			if(vis[v]==0 && G[u][v] !=INF ){
				if(dis[v] > dis[u] + G[u][v] ) {
					way[v] = u; //����·��ǰ��
					dis[v] = dis[u] + G[u][v];//�������·��
					num[v] = num[u] + hap[v]; 
					roa[v] = roa[u]; 
				}
				
				else if(dis[v] == dis[u] + G[u][v] ) { //������·����ͬ 					
					roa[v] += roa[u];
					if( num[v] - hap[v] < num[u]) {//����Ҹ�ֵ�Ƚ�С
						num[v] = hap[v] + num[u];//�����Ҹ�ֵ 
						way[v] = u;//����·��ǰ��
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
	string staLoc;//��ʼ��λ�� 
	cin >> staLoc;
	
	stoi[staLoc] = 0;//����ʼ����뵽 map�� 
	itos[0]= staLoc;
	
	string tempLoc;
	int tempHap;
	init();
	for(i = 1;i< N ;i++){
		cin >> tempLoc >> tempHap;
		stoi[tempLoc]= i;
		itos[i] = tempLoc;
		hap[i] = tempHap;//����ÿ���ڵ���Ҹ�ֵ		 		
	}
	
	string loc1,loc2;
	int len;
	for(i = 0;i< K;i++){
		cin >> loc1 >> loc2 >> len;
		G[stoi[loc1]][stoi[loc2]] = len;
		G[stoi[loc2]][stoi[loc1]] = len;
	} 
	
	dijkstra(0);
	int des = stoi["ROM"];//�õ� ROM ���±� 
	//cout <<"des = "<<des<<"\n";
	int tempDes = des;
	int index = 0;//·���� 
	int anw[maxn]; 
	
//	cout <<"ǰ��\n";
//	for(i =0;i<N;i++){
//		cout << way[i] << " "; 
//	} cout <<"\n";
//	
//	cout<<"·������\n";
//	for(i =0;i<N;i++){
//		cout << roa[i] << " "; 
//	} cout <<"\n";
//	
//	cout<<"·������\n";
//	for(i =0;i<N;i++){
//		cout << dis[i] << " "; 
//	} cout <<"\n";
	
	while(tempDes!=way[tempDes]){	
		anw[index]  = tempDes;
		index ++;
		tempDes = way[tempDes];
	}
	anw[index] = tempDes;//��ʼ�������� 
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
