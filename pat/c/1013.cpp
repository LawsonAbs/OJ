#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#define maxn 1005

using namespace std;

//用于存储节点的信息 
struct Node{
	int isVisit = 0;//用于表示节点是否已经访问过，初始化为0 
	vector<int> nei; //相邻的节点 		
}; 

Node node[maxn];//表示的是最开始输入的node 信息 
Node cur[maxn];//表示处理某个信息之后的node信息 
int edge[maxn][maxn];
int N,M,K;

//计算图的块数 
int dfs(int root){	 	
	node[root].isVisit = 1;//设置成已访问 	
	cout <<"root = "<<root<<"\n";		
	for(int i = 0; i < node[root].nei.size();i++){
		if(node[node[root].nei[i]].isVisit == 0){//说明该节点未访问 			
			dfs(node[root].nei[i]) ;
		}
	}
}


int main(){	
	cin >>N >> M;
	int i,j,k;
	int ver1,ver2;
	//输入边的信息 
	for(i = 0;i< M;i++){
		cin >> ver1 >> ver2;
		node[ver1].nei.push_back(ver2); 
		node[ver2].nei.push_back(ver1);				
	}
	
	cin>>K;
	int query[K];
	for(i = 0;i< K;i++){
		cin >> query[i];

		//去除query[i] 顶点之后的信息 		
		for(j = 1;j<= N ; j++){
			if(j != query[i]){
				cur[j].nei =  node[j].nei;
				if()
			}			
		}		
	}
		
	int block = 0; 
	for(i = 1;i<= N ;i++){		
		if(node[i].isVisit == 0){
			cout << "i = "<< i <<"\n";
			dfs(i);//将当前的顶点i作为 初始化节点 
			block++;//块数加一 
		}
	}
	cout << "block = "<<block<<"\n";
}
/*
3 2 3
1 2
1 3
1 2 3

*/

 
