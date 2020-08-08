#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10001 

struct Node{
	int data;//节点值
	int height;//以该节点为根节点时 树的高度 
	bool visit;//表示是否访问 
	vector<int> adj;//邻接节点存储 
};

Node node[maxn];//邻接表 
int nodeNum;//结点数 
vector<int> result;//记录根节点 
int rootDepth[maxn]; 

//初始化访问信息 
void init(){
	int i;
	for(i = 1;i <= nodeNum;i++){//根节点下标从1开始 
		node[i].visit =false;//表示未访问 
		node[i].data = i;
		node[i].height = 1;//初始高度为1 
	} 
} 


void dfs(int root,int depth){//使用深度遍历查看树是否连通  同时记录深度 
	int i ;
	if(node[root].visit == true)	return; //节点root已访问 
	else {
		node[root].visit = true; //修改node[root]
		node[root].height = depth;
	}	
	
	for(i = 0;i < node[root].adj.size();i++){
		dfs(node[root].adj[i],depth+1);//依次遍历根下子节点	
	}
}


int main(){
	memset(rootDepth,-1,sizeof(rootDepth));
	scanf("%d",&nodeNum);//节点数
	int i ,j;
	int ver1,ver2;//两个顶点 
	int maxDepth ; 
	for(i = 0;i < nodeNum-1;i++){//紧接着输入n-1条边 
		scanf("%d %d",&ver1,&ver2); 		
		node[ver1].adj.push_back(ver2); 
		node[ver2].adj.push_back(ver1);		
	} 
		
	//检查树是否连通 
	int block = 0;//连通块 
	for(i = 1; i <= nodeNum;i++){	
		if(node[i].visit == false){//如果node[i] 未访问 
			dfs(i,0);//对节点i访问 --->进入函数 --->从而对其相邻节点也访问						
			block++;//未访问 则加一 
		}
	}
	
	if(block > 1)	printf("Error: %d components",block);
	else{
		for(i = 1; i <= nodeNum;i++){	
			init(); //每次需要初始化 
			dfs(i,0);//对节点i访问 --->进入函数 --->从而对其相邻节点也访问			
			
			maxDepth = 0;//最大深度
			for(j = 1;j <= nodeNum;j++){
				if(node[j].height > maxDepth){					
					maxDepth = node[j].height;									
				}
			}
			rootDepth[i] = maxDepth;//放入数组中 
		}
		
		maxDepth = 0;//最大深度为0 
		for(i = 1;i<= nodeNum;i++){//遍历数组 
			if(rootDepth [i] > maxDepth ){
				if(!result.empty())	result.clear();//清空 
				result.push_back(i);
				maxDepth = rootDepth[i]; 
			}
			else if(rootDepth[i] == maxDepth){
				result.push_back(i);
			}
		} 
		
		sort(result.begin(),result.end());
		for(i = 0;i< result.size();i++){
			printf("%d\n",result[i] ); 
		}		
	}	
}
 

/**
5
1 2
1 3
1 4
2 5

5
1 3
1 4
2 5
3 4
Error: K components
*/
