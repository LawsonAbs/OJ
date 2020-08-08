#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#define maxn 1005

using namespace std;

//���ڴ洢�ڵ����Ϣ 
struct Node{
	int isVisit = 0;//���ڱ�ʾ�ڵ��Ƿ��Ѿ����ʹ�����ʼ��Ϊ0 
	vector<int> nei; //���ڵĽڵ� 		
}; 

Node node[maxn];//��ʾ�����ʼ�����node ��Ϣ 
Node cur[maxn];//��ʾ����ĳ����Ϣ֮���node��Ϣ 
int edge[maxn][maxn];
int N,M,K;

//����ͼ�Ŀ��� 
int dfs(int root){	 	
	node[root].isVisit = 1;//���ó��ѷ��� 	
	cout <<"root = "<<root<<"\n";		
	for(int i = 0; i < node[root].nei.size();i++){
		if(node[node[root].nei[i]].isVisit == 0){//˵���ýڵ�δ���� 			
			dfs(node[root].nei[i]) ;
		}
	}
}


int main(){	
	cin >>N >> M;
	int i,j,k;
	int ver1,ver2;
	//����ߵ���Ϣ 
	for(i = 0;i< M;i++){
		cin >> ver1 >> ver2;
		node[ver1].nei.push_back(ver2); 
		node[ver2].nei.push_back(ver1);				
	}
	
	cin>>K;
	int query[K];
	for(i = 0;i< K;i++){
		cin >> query[i];

		//ȥ��query[i] ����֮�����Ϣ 		
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
			dfs(i);//����ǰ�Ķ���i��Ϊ ��ʼ���ڵ� 
			block++;//������һ 
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

 
