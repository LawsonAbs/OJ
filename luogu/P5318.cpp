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
int head[maxN];//head[i] ��ʾ��i���ڵ�ĵ�һ����
int eN = 0; 
Edge edge[maxE];//���ÿ���ߵ���Ϣ
Edge temp_Edge[maxE]; // Ϊɶ���Ҫ������������ſ��ԣ� 
bool vis[maxN]; //������Ϣ 
int temp[maxN]; //�����ʱ�ڵ� 
//���ṹ�尴�չ������� => ���ڱ�֤��dfs��ʱ����Դ�С���� 
int cmp(Edge e1,Edge e2){
	if (e1.next == e2.next){
		return e1.to > e2.to;
	}
	else
		return e1.next < e2.next;
}


//��a,b �����ڵ�ŵ�������  => ��ͼ 
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
		int eTo = edge[i].to; //�õ������������Ϣ 
		if(!vis[eTo]){//δ���ʹ� 
			vis[eTo] = true;
			dfs(eTo);
		} 
	}  
} 

 
void bfs(int root){
	que.push(root);//�����ŵ����� 
	vis[root] = true; //ע��������Ҫ����һ�� 
	while(!que.empty()){
		int cnt = 0;
		for(int i = head[root];i!=-1;i=edge[i].next){
			int eTo = edge[i].to; //�õ������������Ϣ 
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
	
	//���ṹ�尴�չ������� 
	sort(temp_Edge,temp_Edge+m,cmp);
	for (int i = 0;i< m;i++){
		a = temp_Edge[i].next;
		b = temp_Edge[i].to;
		//cout << a <<" " << b <<"\n"; 
		add(a,b);
	}
	
	//1Ϊ�� 
	vis[1] = true;
	dfs(1);
	fill(vis,vis+maxN,false);
	cout <<"\n";
	bfs(1);
}
 
