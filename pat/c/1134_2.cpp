#include<cstdio>
#include<iostream>
using namespace std;

struct edge{
	int ver[10005];//一个顶点的相邻顶点	集合 
	int index = 0;//表示相邻的顶点数 
};
 
edge e[10005];  

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j,x;
	int left,right; 
	for(i = 0;i< M;i++){
		scanf("%d%d",&left,&right);
		e[left].ver[e[left].index] = right;
		e[left].index++;
		
		e[right].ver[e[right].index] = left;
		e[right].index++;		
	}
	int K;//待查询数 
	scanf("%d",&K);
	int verNum;//表示待查询的顶点集合数 
	int verSet[10005]; //待查询顶点集 
	for(i = 0;i< K;i++){
		scanf("%d",&verNum);	
		for(j = 0;j< verNum;j++){
			scanf("%d",&verSet[j]);//输入待查询的每个vertex 						
		}
				
		int sumEdge = 0;//表示输入集合中总得边数 		
		//找出重复的边数
		int repEdge = 0;
		
		//开始进行处理
		for( x = 0; x < verNum; x++ ){
			sumEdge += e[verSet[x]].index;//这是没有排除重复的情况 
			for(j = x+1;j< verNum;j++){				
				for(int z = 0;z < e[verSet[j]].index;z++){//表示的是 节点号=j的相邻节点数 
					if(e[verSet[j]].ver[z] == verSet[x]){						
						repEdge ++;
					} 
				}			
			} 
		}
		sumEdge -= repEdge;//排除重复的情况 
		if(sumEdge == M) cout <<"Yes"<<endl;
		else cout<<"No"<<endl;		
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
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
*/
