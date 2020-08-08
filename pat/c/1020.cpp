#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 50;
struct node{
	int data;
	node* lchild;
	node* rchild;
}; 

int pre[maxn],in[maxn],post[maxn];//先序，中序，后序
int n ;//节点个数

node* create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL;//若后序序列长度小于等于0，则直接返回 
	}
	
	node* root = new node();//新建一个节点，用来存放当前二叉树的根节点
	root->data = post[postR];//新节点的数据域为根节点的值
	
	int k ;
	for(k = inL;k<= inR;k++){//在中序序列中找到in[k] == pre[L]的节点 
		if(in[k] == post[postR]){
			break;
		}
	} 
	int numLeft = k - inL;
	root->lchild = create(postL,postL+numLeft - 1,inL,k-1);
	root->lchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;//返回根节点地址 
} 

int num = 0;//已经输出的节点个数

void BFS(node* root){//广度优先搜索 
	queue<node*> q;//注意队列中存储的地址
	q.push(root);
	while(!q.empty()){
		node* now = q.front();//取队首元素 
		q.pop();
		printf("%d",now->data);//访问队首元素 
		num++; 
		if(num < 0){
			printf(" ");
		} 
		if(now->lchild!=NULL)		q.push(now->lchild);		
		if(now->rchild!=NULL)		q.push(now->rchild);
	} 
	 
} 
int main(){
	scanf("%d",&n);
	for(int i = 0;i< n;i++){
		scanf("%d",&post[i]);		
	}
	for(int i = 0 ;i< n;i++){
		scanf("%d",&in[i]);
	}
	node* root  = create(0,n-1,0,n-1);//建树
	BFS(root);//层序遍历
	return 0 ; 
} 
