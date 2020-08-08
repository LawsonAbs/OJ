#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#define maxn 20005

using namespace std;

int main(){
	int isVisit[maxn];
	int edge[205][205];
	int N,M;//N 是城市数； M是边数 
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
	int minDis = 999999;//最短路径
	int minIndex;	
	for(i = 0;i< queryNum;i++){
		int num;//表示当前访问城市的个数 
		int array[maxn];//用于存储查询的序列 
		cin  >> num;
		int dis = 0;//节点之间的总距离 
		int pre = 0;//表示上一个节点 
		int flag = 0;

		memset(isVisit,0,sizeof(isVisit));//初始化所有的城市节点访问信息			
		for(j = 0;j< num;j++){
			cin >> array[j]; 
			isVisit[array[j]] = 1;//说明这个节点访问到了 
			
			if(j!=0){//如果当前的节点不是0 
				if(edge[pre][array[j]] != -1){
					dis += edge[pre][array[j]];//求出总和 	
				}
				else{//说明两个城市不存在线路 
					flag = 2; 
					//break;记住这里不能break，否则会造成错误答案 
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
					flag = 1;//表示城市访问不全 
					break; 
				}			 
			} 
			if(j <= N || (array[0] != array[num-1])){//说明不是 cycle
				cout << "Path " << i+1 <<": "<<dis<<" (Not a TS cycle)"<<"\n";					
			}
			else{
				if(num == N + 1){//说明是一个 TS simple cycle 
					cout << "Path " << i+1 <<": "<< dis<<" (TS simple cycle)"<<"\n";				
				}
				else{//说明有重复访问城市 
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

