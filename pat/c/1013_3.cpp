#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#define maxn 1005

using namespace std;

//���ڴ洢�ڵ����Ϣ 
struct Node{
	int isVisit = 0;//���ڱ�ʾ�ڵ��Ƿ��Ѿ����ʹ�����ʼ��Ϊ0 
	set<int> nei; //���ڵĽڵ� 		
}; 

Node node[maxn];//��ʾ�����ʼ�����node ��Ϣ 
Node cur[maxn];//��ʾ����ĳ����Ϣ֮���node��Ϣ 
vector<vector<int> > ver(maxn);//��ʾ����ÿ�����������������Ϣ 
int N,M,K;

//����ͼ�Ŀ��� 
void dfs(int root){	 	
	cur[root].isVisit = 1;//���ó��ѷ��� 		
	for(set<int> :: iterator it = cur[root].nei.begin();it!=cur[root].nei.end();it++){
		if(cur[*it].isVisit == 0){//˵���ýڵ�δ���� 			
			dfs(*it) ;
		}
	}
}

int main(){	
	cin >>N >> M >>K;
	int i,j,k;
	int ver1,ver2;
	//����ߵ���Ϣ 
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
		
		//��ֵ�ṹ����Ϣ		
		for(j = 1;j <=N ; j++) {
			cur[j].isVisit = 0;//�����еĽڵ�ķ�����Ϣ����Ϊ0
			cur[j].nei.clear();//���set���� ��Ϣ
			if(j != query[i]){
				cur[j].nei =  node[j].nei;				
			}
		}
				
		//ȥ��query[i] ����֮�����Ϣ 
		int curNode;
		for(j = 0;j < ver[query[i]].size(); j++){
			//cout << ver[query[i]][j] <<" ";//��Ҫɾ���Ķ�����Ϣ
			curNode = ver[query[i]][j];//��ǰ���ڲ鿴�Ľڵ� 
			cur[curNode].nei.erase(query[i]);//ɾ���������Ϣ 			
		}
		
		int block = 0; 
		for(j = 1;j<= N ;j++){		
			if(cur[j].isVisit == 0){			
				dfs(j);//����ǰ�Ķ���i��Ϊ ��ʼ���ڵ� 
				block++;//������һ 
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
