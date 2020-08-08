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

Node cur[maxn];//��ʾ����ĳ����Ϣ֮���node��Ϣ 
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
		cur[ver1].nei.insert(ver2); 
		cur[ver2].nei.insert(ver1);		
	}					
				
	int query[K];
	for(i = 0;i< K;i++){
		cin >> query[i];		
		
		for(j = 1;j <=N ; j++) {		
			cur[j].isVisit = 0;		
		}
		
		//ֻ��Ҫ����ǰ�Ľڵ� �ó��ѷ��ʼ��� 
		cur[query[i]].isVisit = 1;
		
		int block = 0; 
		for(j = 1;j<= N ;j++){		
			if(cur[j].isVisit == 0){			
				dfs(j);//����ǰ�Ķ���i��Ϊ ��ʼ���ڵ� 
				block++;//������һ 
			}
		}
		//cout << "block = "<<block<<",";
		if(block >= 2) cout << block - 1 <<"\n";
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

 
