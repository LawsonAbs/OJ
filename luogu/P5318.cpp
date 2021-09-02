#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxE = 1e6+5; // max edge num 
const int maxN = 1e5+5;  
typedef struct{
	int next,to;
}Edge;
queue<int> que;
int head[maxN];//head[i] 表示第i个节点的第一条边
int eN = 0; 
Edge edge[maxE];//存放每条边的信息
Edge temp_Edge[maxE]; // 为啥这个要放在外面申请才可以？ 
bool vis[maxN]; //访问信息 
int temp[maxN]; //存放临时节点 
//将结构体按照规则排序 => 用于保证在dfs的时候可以从小到大 
int cmp(Edge e1,Edge e2){
	if (e1.next == e2.next){
		return e1.to > e2.to;
	}
	else
		return e1.next < e2.next;
}


//将a,b 两个节点放到的其中  => 建图 
void add(int a,int b){
	edge[eN].next =  head[a];
	edge[eN].to = b;
	head[a] = eN;
	eN++;
}


void dfs(int cur){
//	vis[cur] = true; 	
	cout << cur<<" ";	
	for(int i = head[cur];i!=-1;i=edge[i].next){
		int eTo = edge[i].to; //得到这个到达点的信息 
		if(!vis[eTo]){//未访问过 
			vis[eTo] = true;
			dfs(eTo);
		} 
	}  
} 

 
void bfs(int root){
	que.push(root);//将根放到其中 
	vis[root] = true; //注意这里需要设置一下 
	while(!que.empty()){
		int cnt = 0;
		for(int i = head[root];i!=-1;i=edge[i].next){
			int eTo = edge[i].to; //得到这个到达点的信息 
			if (!vis[eTo]) {
				vis[eTo] = true;
				temp[cnt] = eTo;
				cnt ++;
			}
		}
		sort(temp,temp+cnt);
		for (int i = 0;i< cnt ;i++){
			que.push(temp[i]);
		}
		root = que.front(); 
		que.pop();
		cout << root <<" ";
	}
}

int main(){
	int n,m;
	cin >>n >> m;
	int a ,b;
	fill(head,head+maxN,-1);
	fill(vis,vis+maxN,false); 
	
	for (int i = 0;i < m;i++){
		cin >> a >> b;
		temp_Edge[i].next = a;
		temp_Edge[i].to = b;
	} 
	
	//将结构体按照规则排序 
	sort(temp_Edge,temp_Edge+m,cmp);
	for (int i = 0;i< m;i++){
		a = temp_Edge[i].next;
		b = temp_Edge[i].to;
		//cout << a <<" " << b <<"\n"; 
		add(a,b);
	}
	
	//1为根 
	vis[1] = true;
	dfs(1);
	fill(vis,vis+maxN,false);
	cout <<"\n";
	bfs(1);
}
 
