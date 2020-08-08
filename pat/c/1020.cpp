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

int pre[maxn],in[maxn],post[maxn];//�������򣬺���
int n ;//�ڵ����

node* create(int postL,int postR,int inL,int inR){
	if(postL > postR){
		return NULL;//���������г���С�ڵ���0����ֱ�ӷ��� 
	}
	
	node* root = new node();//�½�һ���ڵ㣬������ŵ�ǰ�������ĸ��ڵ�
	root->data = post[postR];//�½ڵ��������Ϊ���ڵ��ֵ
	
	int k ;
	for(k = inL;k<= inR;k++){//�������������ҵ�in[k] == pre[L]�Ľڵ� 
		if(in[k] == post[postR]){
			break;
		}
	} 
	int numLeft = k - inL;
	root->lchild = create(postL,postL+numLeft - 1,inL,k-1);
	root->lchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;//���ظ��ڵ��ַ 
} 

int num = 0;//�Ѿ�����Ľڵ����

void BFS(node* root){//����������� 
	queue<node*> q;//ע������д洢�ĵ�ַ
	q.push(root);
	while(!q.empty()){
		node* now = q.front();//ȡ����Ԫ�� 
		q.pop();
		printf("%d",now->data);//���ʶ���Ԫ�� 
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
	node* root  = create(0,n-1,0,n-1);//����
	BFS(root);//�������
	return 0 ; 
} 
