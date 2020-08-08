#include <iostream>
#define maxn 10000
#include <vector>
using namespace std;
struct Node{//节点
	int childNumber;//孩子数初始化为0 
	vector <int> child;//孩子下标
	int weight;//节点权值 
	int flag;//节点标志 
};


Node  node[maxn];//节点
int N,M,S;//N,the number of nodes in a tree  M,the number of non-leaf node  S,the given weight number 

void DFS(int root,int sumW);//深搜 

int main(){
	int temp;//暂存孩子值
	int index;//暂存结点序号 
	int k;//孩子结点数 
	
	scanf("%d%d%d",&N,&M,&S);
	for(int i = 0;i<N;i++){
		scanf("%d",&node[i].weight);//输入节点权值 
		node[i].flag = 0;//节点标志初始为0
		node[i].childNumber = 0;
	}
	
	for(int i = 0;i < M ;i++){
		scanf("%d",&index);
		scanf("%d",&node[index].childNumber); 
		//printf("index = %d  node[index].childNumber = %d\n",index,node[index].childNumber);
		for(int j = 0;j < node[index].childNumber; j++){
			scanf("%d",&temp);//再输入具体孩子节点的下标 
			node[index].child.push_back(temp); 
		}
	}
	
	for(int i = 0;i< N;i++){
		printf("%02d %d ",i,node[i].childNumber);
		for(j =0 ;j<node[i].child.size();j++){
			printf("%d ",node[i].child[j]);
		}
		printf("\n"); 
	}
	DFS(0,0);//深搜    root = 0,sum = 0; 
}
  

//使用深搜来记录路径之和 
void DFS(int root,int numNode,int sum){//从根开始 
	if(sum >S)		return ;
	if(sum == S){
		if(node[root].child.size()!=0)	return;
		for(i = 0;i<numNode;i++){
			printf("%d",node[path[i]].weight);
			if(i < number -1 )	printf(" ");
			else printf("\n");
		}
		return; 
	}
	
	for(j = 0;j < node[root].child.size(); j++){
		int child = node[root].child[j];
		path[numNode] = child;
		DFS(child,numNode + 1,sum+node[child].weight);//节点的孩子结点				
		} 
	} 
} 
      
/*sample input
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
**/
