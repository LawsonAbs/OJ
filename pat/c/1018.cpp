#include<cstdio>
#include<algorithm>
#include<iostream> 
#define maxn 505
#define INF 0x3fffffff
 
using namespace std;

int Cmax,N,Sp,M;
int G[maxn][maxn];//һ���ߵ�Ȩ�� 
int way1[maxn];//�����������ǰ���� ����������Ϊԭ�� 
int way2[maxn];//�����������ǰ���� ����������Ϊԭ�� 
int dis[maxn];//��������ľ��� 
int isVisit[maxn];//������� ������Ϣ 
int num1[maxn];//��ʾ����������ĳ�������  ���������ԭ�� 
int num2[maxn];//��ʾ����������ĳ�������  �������ٵ�ԭ�� 
int cap[maxn];//��ǰÿ��station������ 

void init(){
	fill(G[0],G[0]+maxn*maxn,INF);//��ͼ�����֮���������ΪINF 
	fill(dis,dis+maxn,INF);	
	fill(isVisit,isVisit+maxn,0);
	fill(num1,num1+maxn,0);//��ʼ�����Ϊ0 
}

void dijkstra(int s){
	dis[s] = 0; //������ľ���Ϊ0 
	num1[s] = 0; //Դ��ĳ��� Ϊ 0 
	int i,j,v; 
	for(i = 0;i<= N;i++){
		int MIN = INF, u = -1; 
		for(j = 0;j<= N;j++){
			if(isVisit[j] == 0 && dis[j] < MIN){//����ֵ 
				u = j;
				MIN = dis[j] ;
			}
		}
		
		isVisit[u] = 1;
		//��Ϊ�м�ڵ㿪ʼ�Ƚϸ��� 		
		for(v = 0;v<=N;v++){
			if(isVisit[v] == 0 && G[u][v] != INF){//���δ���ʣ��Ҵ��ڱ� 
				if(dis[v] > dis[u] + G[u][v]){
					dis[v] = dis[u] + G[u][v];//�������·�� 
					num1[v] = num1[u] + cap[v];//���³��еĳ��� 
					way1[v] = u;//����·��ǰ�� 					
				}
				else if(dis[v] == dis[u] + G[u][v]){//���������� ����Ҫע��������if - else if 
					if(num1[u] > (num1[v] - cap[v]) ){
						num1[v] = num1[u] + cap[v] ;//���³��еĳ��� 	
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
		
	for(i = 1;i <= N;i++){//station ���±��1��ʼ 
		cin >> cap[i]; 
	}
	
	int ver1,ver2;//�ߵ��������� 
	int weight; 

	init();		
	while(M--){
		cin >> ver1 >> ver2 >> weight;
		G[ver1][ver2] = weight; 
		G[ver2][ver1] = weight; 
	} 
	
	//��ʼ�㶼��s = 0 
	dijkstra(0);
	
//	cout <<"������Ϣ\n" ;
//	for(i = 1;i<= N;i++){
//		cout <<"i = "<<i<<", "<< dis[i]<<"\n";
//	}
//	cout <<"������Ϣ\n"; 
//	for(i = 1;i<= N;i++){
//		cout <<"i = "<<i<<", "<< num[i]<<"\n";
//	}
//	
//	cout<<"·����Ϣ\n";	
//	for(i = 1;i<=N;i++) {
//		cout <<"i = "<<i<<", "<< way[i]<<"\n";
//	}cout<<"\n";
	
	int anw[maxn];//���ڱ���·����Ϣ
	int tempDes = Sp;
	int index = 0;
	while(way1[tempDes]!=tempDes){
		anw[index++] = tempDes;
		tempDes = way1[tempDes];
	} 
	anw[index] = 0;
	
	int need;
	need = (Cmax * index /2) - num1[Sp];
	if(need < 0) cout <<"0 " ; //�������Ҫ���ͳ��� 
	else cout << need <<" ";
	for(i = index;i >=0;i--){
		cout << anw[i];
		if(i!=0) cout<<"->"; 
		
	}cout <<" ";
	
	int backNum = 0;//��Ҫ�˻ص����� 
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

