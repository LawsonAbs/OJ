#include<cstdio>
#include<vector>
#define maxn 1002
using namespace std;

struct Node{
	int level;//层数
	bool visit;
	vector<int> adj;//相邻节点 
}; 
Node node[maxn]; 
int n,l;

void init(){
	for(int i = 1;i<= n;i++){
		node[i].level = -1;
		node[i].visit = false;
	}
}

//深搜求转发 
void dfs(int root,int level){
	if(node[root].level > level){
		node[root].level = level;		
		node[root].visit = false;
	}
	if(node[root].visit == true || level > l)	return;//若已访问或者访问深度已达，则返回
	else{
		node[root].visit = true;//修改为true 
		node[root].level = level;//修改等级 
		for(int i = 0;i < node[root].adj.size();i++){
			dfs(node[root].adj[i],level+1);
		}
	} 
}

int main(){	 
	scanf("%d %d",&n,&l);
	int i ,j;
	int tempNum;//表示被关注的数量 
	int followedUser;
	for(i = 1;i<= n;i++){
		scanf("%d",&tempNum);
		for(j = 0;j< tempNum;j++){
			scanf("%d",&followedUser);
			node[followedUser].adj.push_back(i);//用户i关注followedUser 
		}
	} 	
	//验证输出 
//	for(i = 1;i<=n;i++){
//		printf("%d:",i);
//		for(j = 0;j< node[i].adj.size();j++){
//			printf("%d ",node[i].adj[j]);
//		}printf("\n");
//	}	
	int userNum;
	int userId;//求其post被转发的数量 
	scanf("%d",&userNum);
	for(i = 0;i< userNum;i++){
		scanf("%d",&userId);
		init();//清0 
		dfs(userId,0);//深搜 
				
		int count = 0;
		for(j = 1;j <= n;j++){
			if(node[j].level >0 && node[j].level<=l && node[j].visit == true){ 
				count++;
			}
		}printf("%d\n",count);
	}	
} 
/***
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6

8 3
2 3 4
1 8
2 5 6
2 3 1
2 3 4
1 4
1 5
1 2
2 2 6

3 3
0
1 1
1 2
1 3
*/
