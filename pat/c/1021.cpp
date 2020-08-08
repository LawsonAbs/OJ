#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 10001 

struct Node{
	int data;//�ڵ�ֵ
	int height;//�Ըýڵ�Ϊ���ڵ�ʱ ���ĸ߶� 
	bool visit;//��ʾ�Ƿ���� 
	vector<int> adj;//�ڽӽڵ�洢 
};

Node node[maxn];//�ڽӱ� 
int nodeNum;//����� 
vector<int> result;//��¼���ڵ� 
int rootDepth[maxn]; 

//��ʼ��������Ϣ 
void init(){
	int i;
	for(i = 1;i <= nodeNum;i++){//���ڵ��±��1��ʼ 
		node[i].visit =false;//��ʾδ���� 
		node[i].data = i;
		node[i].height = 1;//��ʼ�߶�Ϊ1 
	} 
} 


void dfs(int root,int depth){//ʹ����ȱ����鿴���Ƿ���ͨ  ͬʱ��¼��� 
	int i ;
	if(node[root].visit == true)	return; //�ڵ�root�ѷ��� 
	else {
		node[root].visit = true; //�޸�node[root]
		node[root].height = depth;
	}	
	
	for(i = 0;i < node[root].adj.size();i++){
		dfs(node[root].adj[i],depth+1);//���α��������ӽڵ�	
	}
}


int main(){
	memset(rootDepth,-1,sizeof(rootDepth));
	scanf("%d",&nodeNum);//�ڵ���
	int i ,j;
	int ver1,ver2;//�������� 
	int maxDepth ; 
	for(i = 0;i < nodeNum-1;i++){//����������n-1���� 
		scanf("%d %d",&ver1,&ver2); 		
		node[ver1].adj.push_back(ver2); 
		node[ver2].adj.push_back(ver1);		
	} 
		
	//������Ƿ���ͨ 
	int block = 0;//��ͨ�� 
	for(i = 1; i <= nodeNum;i++){	
		if(node[i].visit == false){//���node[i] δ���� 
			dfs(i,0);//�Խڵ�i���� --->���뺯�� --->�Ӷ��������ڽڵ�Ҳ����						
			block++;//δ���� ���һ 
		}
	}
	
	if(block > 1)	printf("Error: %d components",block);
	else{
		for(i = 1; i <= nodeNum;i++){	
			init(); //ÿ����Ҫ��ʼ�� 
			dfs(i,0);//�Խڵ�i���� --->���뺯�� --->�Ӷ��������ڽڵ�Ҳ����			
			
			maxDepth = 0;//������
			for(j = 1;j <= nodeNum;j++){
				if(node[j].height > maxDepth){					
					maxDepth = node[j].height;									
				}
			}
			rootDepth[i] = maxDepth;//���������� 
		}
		
		maxDepth = 0;//������Ϊ0 
		for(i = 1;i<= nodeNum;i++){//�������� 
			if(rootDepth [i] > maxDepth ){
				if(!result.empty())	result.clear();//��� 
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
