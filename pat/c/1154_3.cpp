#include<cstdio>
#include<cstring>
#include<set>
#include<vector> 
#include<iostream>
#define maxn 10005

using namespace std;

vector<vector<int> > edge(maxn);//用于存储边的信息
 
int main(){
	int N,M,K;
	scanf("%d%d",&N,&M);	
	int i,j,k;
	int ver1,ver2; 
	for(i = 0;i<M;i++){
		scanf("%d%d",&ver1,&ver2);		
		edge[i].push_back(ver1);
		edge[i].push_back(ver2);
	}
	
	scanf("%d",&K);	
	set<int> color;
	int flag ;
	int query[maxn];//查询点的色彩信息 
	int temp;
	
	for(i = 0 ;i< K;i++){
		//初始化信息 
		flag = 0;
		color.clear();			
		memset(query,0,sizeof(query));		
		
		//输入各个顶点的 染色 情况 
		for(j = 0;j< N;j++){
			scanf("%d",&query[j]); //将顶点j插入到query[temp] 中 
			color.insert(query[j]);
		}
		
		for(j = 0;j < M ;j++){
			if( query[edge[j][0]] == query[edge[j][1]] ){
				flag = 1;
				break;
			}								
		}
		if(flag == 1){
			cout << "No" << "\n";				
		}		
		
		else if(flag == 0){			
			cout << color.size() << "-coloring"<<"\n";
		}
	}
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
1
8 1 0 1 4 1 0 5 3 0

*/
