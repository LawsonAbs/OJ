#include<cstdio> 
#include<iostream>
#include<algorithm>

#define maxn 510  
#define INF 0x3fffffff 
using namespace std;

int N,M;
int L[maxn][maxn];//��һ���ڽӾ���洢��ͼ�ڵ�֮��ľ��� 
int T[maxn][maxn];//�洢�������ߵ�ʱ�� 
int d[maxn];//��ʾ����Դ�㵽������ľ���
int dd[maxn];//��ʾ���Ǹõ����һ���ڵ� 
int t[maxn];//��ʾ����Դ�㵽�������ʱ��
int td[maxn];//��ʾ���Ǹõ����һ���ڵ�
int w[maxn];//��Ȩ
bool isVisit[maxn];//��ʾ������Щ�ڵ��Ƿ��Ѿ����ʹ� 

//ʹ��dijkstra �㷨�����̾��� 
//����Ĳ����� Դ����±� 
void dijkstraPath(int s){		
	//���ҳ�Դ�㵽�ڵ���̵Ľڵ�u
	int u = -1; //��ʼʱΪ-1 
	int minValue = INF; 		
	for(int i = 0;i < N;i ++ ){
		if(d[i] < minValue && isVisit[i] == false){
			minValue = d[i];
			u = i;//��¼��С�����������е�id 
		}
	}
	
	if(u == -1) return ;//˵�����еĽڵ㶼�Ѿ����ʹ��� 	
	d[u] = minValue;
	isVisit[u] = true;//����ѷ���
	//�ýڵ�u������̾��� 
	for(int j = 0;j< N;j++){
		if(isVisit[j] == false && d[u] + L[u][j] < d[j]){
			d[j] = d[u] + L[u][j];//������̾���
			t[j] = t[u] + T[u][j];//����ʱ��  !!!! ʮ����Ҫ��һ��Ҫ���£� 
			dd[j] = u;//������һ���ڵ� 
		}
		else if(isVisit[j] == false && d[u] + L[u][j] == d[j]){//���������� 
			if(t[j] > t[u] + T[u][j]) {//���t[j]  
			//	cout <<"I'm here' "<<"\n"; 
				t[j] = t[u] + T[u][j];//����ʱ��
				dd[j] = u;//ȡʱ����� 
			}
		}
	}  
}
  
  
void dijkstraTime(int s){		
	//���ҳ�Դ�㵽�ڵ���̵Ľڵ�u
	int u = -1; //��ʼʱΪ-1 
	int minValue = INF; 		
	for(int i = 0;i < N;i ++ ){
		if(t[i] < minValue && isVisit[i] == false){
			minValue = t[i];
			u = i;//��¼��С�����������е�id 
		}
	}
	
	if(u == -1) return ;//˵�����еĽڵ㶼�Ѿ����ʹ��� 
	//cout << u <<"\n";
	t[u] = minValue;
	isVisit[u] = true;//����ѷ���
	//�ýڵ�u������̾��� 
	for(int j = 0;j< N;j++){
		if(isVisit[j] == false && t[u] + T[u][j] < t[j]){
			t[j] = t[u] + T[u][j];//������̾���
			w[j] = w[u] + 1;//����Ȩ�� 
			td[j] = u;//������һ���ڵ� 
		}
		else if(isVisit[j] == false && t[u] + T[u][j] == t[j]){//���ʱ����� 
			if(w[j] > w[u] + 1) {//ȡ��·������ 
				w[j] = w[u] + 1;
				td[j] = u;
			}
		}		
	}  
}



void init(){
	fill(L[0],L[0]+maxn * maxn,INF);//��ʼ��L 
	fill(T[0],T[0]+maxn * maxn,INF);//��ʼ��T
	fill(d,d+maxn,INF);//��ʼ��������� 
	fill(t,t+maxn,INF);//��ʼ������ʱ�� 	
	fill(w,w+maxn,INF);//��Ȩ
	fill(isVisit,isVisit+maxn,false);// ��isVisit�����ʼ��Ϊfalse 
}

int main() {	
	init(); 
	int sour,des;//sour��Դ�� ,des���յ� 
	cin >> N >> M ;
	int i,j;
	int v1,v2, isOneWay, length,time;
	for(i = 0;i< M;i++){
		cin >> v1 >> v2 >> isOneWay >> length >> time;
		L[v1][v2] = length;//����֮��ľ���		
		L[v2][v1] = length;		
		T[v1][v2] = time;//����֮���ʱ�� 
		T[v2][v1] = time;				
	}
	
	cin >> sour >> des;//����Դ�㣬�յ� 	
	d[sour] = 0;//��ʼ������Դ�㵽Դ������ľ���Ϊ0	
	dd[sour] = sour;//��ʼ��ǰ�ڵ� 
	
	t[sour] = 0;//��ʼ������Դ�㵽Դ������ľ���Ϊ0	
	td[sour] = sour;//��ʼ��ǰ�ڵ� 
	w[sour] = 1;
	//���forѭ��Ҳ����д��dijkstra���� 
	for(i = 0;i< N;i++){ 			
		dijkstraPath(sour); 			
	}	
	
	fill(isVisit,isVisit+maxn,false);
	for(i = 0;i< N;i++){ 				
		dijkstraTime(sour); 
	}

	//============== ������� ==============		
	int res[maxn] ;//���ڱ�����·����ֵ 
	int index1 = 0;
	int tempDes = des;
	res[index1++] = tempDes; //�����յ� 
	while(dd[tempDes]!=tempDes){				
		tempDes = dd[tempDes];//����des��ֵ 
		res[index1++] = tempDes; 	
	}		
	
	// ============ ���ʱ�� ============	
	int res2[maxn] ;//���ڱ�����·����ֵ 
	int index2 = 0;
	tempDes = des;
	res2[index2++] = tempDes; //�����յ� 
	while(dd[tempDes]!=tempDes){				
		tempDes = td[tempDes];//����des��ֵ 
		res2[index2++] = tempDes; 	
	}		
	
	if(index1 == index2){//��������±����  ���ж������Ƿ���� 
		for(i = 0;i < index1 ;i++){
			if(res[i] != res2[i] ) break;
		} 
	}
	
	if(i == index1){//˵������ͬ��·�� 
		cout <<"Distance = "<< d[des]<<"; " << "Time = " << t[des]<<": ";
		for(i = index1-1;i >=0 ;i--){
			if(i != 0)	cout << res[i] <<" -> ";
			else cout << res[i] ;
		} cout <<"\n";		
	}
	else {
		cout <<"Distance = "<< d[des]<<": ";
		for(i = index1-1;i >=0 ;i--){
			if(i != 0)	cout << res[i] <<" -> ";
			else cout << res[i] ;
		} cout <<"\n";
		
		cout <<"Time = " << t[des]<<": ";
		for(i = index2-1;i >=0 ;i--){
			if(i != 0)	cout << res2[i] <<" -> ";
			else cout << res2[i] ;
		} cout <<"\n";
	} 	
}
/*
4 4
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
0 3

5 5
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
3 4 0 2 2
0 4


5 5
0 1 0 1 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 5
3 4 0 2 2
0 4
*/
