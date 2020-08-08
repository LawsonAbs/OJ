#include<cstdio>
#include<vector>
#define maxn 1002
using namespace std;

struct Node{
	int level;//����
	bool visit;
	vector<int> adj;//���ڽڵ� 
}; 
Node node[maxn]; 
int n,l;

void init(){
	for(int i = 1;i<= n;i++){
		node[i].level = -1;
		node[i].visit = false;
	}
}

//������ת�� 
void dfs(int root,int level){
	if(node[root].level > level){
		node[root].level = level;		
		node[root].visit = false;
	}
	if(node[root].visit == true || level > l)	return;//���ѷ��ʻ��߷�������Ѵ�򷵻�
	else{
		node[root].visit = true;//�޸�Ϊtrue 
		node[root].level = level;//�޸ĵȼ� 
		for(int i = 0;i < node[root].adj.size();i++){
			dfs(node[root].adj[i],level+1);
		}
	} 
}

int main(){	 
	scanf("%d %d",&n,&l);
	int i ,j;
	int tempNum;//��ʾ����ע������ 
	int followedUser;
	for(i = 1;i<= n;i++){
		scanf("%d",&tempNum);
		for(j = 0;j< tempNum;j++){
			scanf("%d",&followedUser);
			node[followedUser].adj.push_back(i);//�û�i��עfollowedUser 
		}
	} 	
	//��֤��� 
//	for(i = 1;i<=n;i++){
//		printf("%d:",i);
//		for(j = 0;j< node[i].adj.size();j++){
//			printf("%d ",node[i].adj[j]);
//		}printf("\n");
//	}	
	int userNum;
	int userId;//����post��ת�������� 
	scanf("%d",&userNum);
	for(i = 0;i< userNum;i++){
		scanf("%d",&userId);
		init();//��0 
		dfs(userId,0);//���� 
				
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
