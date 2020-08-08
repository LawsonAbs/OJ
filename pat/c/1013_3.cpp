#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#define maxn 1005

using namespace std;

//用于存储节点的信息 
struct Node{
	int isVisit = 0;//用于表示节点是否已经访问过，初始化为0 
	set<int> nei; //相邻的节点 		
}; 

Node node[maxn];//表示的是最开始输入的node 信息 
Node cur[maxn];//表示处理某个信息之后的node信息 
vector<vector<int> > ver(maxn);//表示的是每个顶点的相连顶点信息 
int N,M,K;

//计算图的块数 
void dfs(int root){	 	
	cur[root].isVisit = 1;//设置成已访问 		
	for(set<int> :: iterator it = cur[root].nei.begin();it!=cur[root].nei.end();it++){
		if(cur[*it].isVisit == 0){//说明该节点未访问 			
			dfs(*it) ;
		}
	}
}

int main(){	
	cin >>N >> M >>K;
	int i,j,k;
	int ver1,ver2;
	//输入边的信息 
	for(i = 0;i< M;i++){
		cin >> ver1 >> ver2;
		node[ver1].nei.insert(ver2); 
		node[ver2].nei.insert(ver1);
		ver[ver1].push_back(ver2);		
		ver[ver2].push_back(ver1);
	}
		
	int query[K];
	for(i = 0;i< K;i++){
		cin >> query[i];		
		
		//赋值结构体信息		
		for(j = 1;j <=N ; j++) {
			cur[j].isVisit = 0;//将所有的节点的访问信息都置为0
			cur[j].nei.clear();//清空set所有 信息
			if(j != query[i]){
				cur[j].nei =  node[j].nei;				
			}
		}
				
		//去除query[i] 顶点之后的信息 
		int curNode;
		for(j = 0;j < ver[query[i]].size(); j++){
			//cout << ver[query[i]][j] <<" ";//需要删除的顶点信息
			curNode = ver[query[i]][j];//当前正在查看的节点 
			cur[curNode].nei.erase(query[i]);//删除掉这个信息 			
		}
		
		int block = 0; 
		for(j = 1;j<= N ;j++){		
			if(cur[j].isVisit == 0){			
				dfs(j);//将当前的顶点i作为 初始化节点 
				block++;//块数加一 
			}
		}
		//cout << "block = "<<block<<",";
		if(block >= 2) cout << block - 2 <<"\n";
		else cout<<"0"<<"\n";					
	}
}
/*
3 2 3
1 2
1 3
1 2 3

4 3 3
1 2
1 3
1 4
1 2 3

4 4 3
1 2
1 3
1 4
2 3
1 2 3


2 1 1
1 2
1

1 0 1
1

*/
