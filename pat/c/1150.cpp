#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#define maxn 20005

using namespace std;

int main(){
	int isVisit[maxn];
	int edge[205][205];
	int N,M;//N �ǳ������� M�Ǳ��� 
	cin >> N >> M;
	int i ,j;
	int ver1,ver2,a;
	
	for(i = 0;i< 205;i++){
		for(j = 0;j< 205;j++)
			edge[i][j] = -1;
	}
	
	for(i = 0;i< M ;i++){
		cin >> ver1>> ver2 >> a;
		edge[ver1][ver2] = a;
		edge[ver2][ver1] = a;
	}		
	
	int queryNum;
	cin >> queryNum;
	int minDis = 999999;//���·��
	int minIndex;	
	for(i = 0;i< queryNum;i++){
		int num;//��ʾ��ǰ���ʳ��еĸ��� 
		int array[maxn];//���ڴ洢��ѯ������ 
		cin  >> num;
		int dis = 0;//�ڵ�֮����ܾ��� 
		int pre = 0;//��ʾ��һ���ڵ� 
		int flag = 0;

		memset(isVisit,0,sizeof(isVisit));//��ʼ�����еĳ��нڵ������Ϣ			
		for(j = 0;j< num;j++){
			cin >> array[j]; 
			isVisit[array[j]] = 1;//˵������ڵ���ʵ��� 
			
			if(j!=0){//�����ǰ�Ľڵ㲻��0 
				if(edge[pre][array[j]] != -1){
					dis += edge[pre][array[j]];//����ܺ� 	
				}
				else{//˵���������в�������· 
					flag = 2; 
					//break;��ס���ﲻ��break���������ɴ���� 
				}				
			} 
			pre = array[j];
		}		
	 
	 	if(flag == 2){
	 		cout << "Path " << i+1 <<": NA (Not a TS cycle)"<<"\n";	 		
		}
		else{		 
			for(j = 1;j <= N;j++ ){
				if(isVisit[j] == 0){
					flag = 1;//��ʾ���з��ʲ�ȫ 
					break; 
				}			 
			} 
			if(j <= N || (array[0] != array[num-1])){//˵������ cycle
				cout << "Path " << i+1 <<": "<<dis<<" (Not a TS cycle)"<<"\n";					
			}
			else{
				if(num == N + 1){//˵����һ�� TS simple cycle 
					cout << "Path " << i+1 <<": "<< dis<<" (TS simple cycle)"<<"\n";				
				}
				else{//˵�����ظ����ʳ��� 
					cout << "Path " << i+1 <<": "<< dis <<" (TS cycle)"<<"\n";
				}						
				if(minDis > dis){
					minDis = dis;
					minIndex = i+1;
				} 
			}	
		}
	} 	 
	cout << "Shortest Dist("<<minIndex << ") = "<<minDis<<"\n";
} 
/*
6 10
6 2 1
3 4 1
1 5 1
2 5 1
3 1 8
4 1 6
1 6 1
6 3 1
1 2 1
4 5 1
2
7 6 3 2 5 4 1 6
9 6 2 1 6 3 4 5 2 6

*/ 

