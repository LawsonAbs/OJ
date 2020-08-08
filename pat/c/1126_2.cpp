#include <iostream>
#include <vector>

using namespace std;
const int maxn=520;
int numver,numedge,countodd=0;
vector<int> child[maxn];
bool vis[maxn]={0};

//深搜判断是否是一个连通图 
void DFS(int s){
	if(child[s].size()==0) return;//如果没有相邻节点了，则直接返回 
	vis[s]=true;//标记为已经访问了 
	for(int i=0;i<child[s].size();i++)
		if(!vis[child[s][i]]) DFS(child[s][i]); 
}

bool cgraph(){
	int count=0;
	for(int i=1;i<=numver;i++){
		if(!vis[i]){
			DFS(i);
			count++;
		}
	}
	if(count!=1) return false;
	else return true;
}


int main(){
	scanf("%d%d",&numver,&numedge);
	for(int i=0;i<numedge;i++){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		child[v1].push_back(v2);
		child[v2].push_back(v1);
	}
	for(int i=1;i<=numver;i++){
		i!=numver?printf("%d ",child[i].size()):printf("%d\n",child[i].size());
		if(child[i].size()%2==1) countodd++;
	}
	if(!cgraph()){
		printf("Non-Eulerian\n");
		return 0;
	}
	if(countodd==0) printf("Eulerian\n");
	else if(countodd==2) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	return 0;
}
