#include <cstdio>
#include <algorithm> 
#include <queue>
#define maxn 10000
using namespace std;

struct Node{
	int data;
	int left,right;//左右孩子 
};

queue<int> qu;
int value[maxn];//初始序列 
int nodeNum;
Node node[maxn];//完全二叉排序树--->用数组存储 

//使用中序遍历赋值完整二叉排序树 
void inOrder(int root,int& count){
	if(root == -1)	return;//如果左孩子为-1 
	else {
		inOrder(node[root].left,count);
		node[root].data = value[count++];//赋值 				
	}	
	if(root == -1)	return;
	else	inOrder(node[root].right,count);
} 

//层次遍历CBT 
void levelCBT(int root){
	int count = 0;
	qu.push(root);
	while(!qu.empty()){
		if(count != nodeNum-1)	printf("%d ",node[qu.front()].data);
		else printf("%d",node[qu.front()].data);
		if(node[qu.front()].left!=-1)	qu.push(node[qu.front()].left);
		if(node[qu.front()].right!=-1)	qu.push(node[qu.front()].right);
		qu.pop();//删除队首
		count++; 
	}
} 

int main(){		
	int i ;
	int count = 0 ;
	scanf("%d",&nodeNum);//输入节点数
	for(i = 0;i< nodeNum;i++){
		scanf("%d %d",&node[i].left,&node[i].right);		
	}
	
	//输入并排序 
	for(i = 0;i < nodeNum;i++){
		scanf("%d",&value[i]);
	}	
	sort(value,value+nodeNum);	
	
	//初始root = 0 
	inOrder(0,count);
	 		
	//层次遍历并输出 
	levelCBT(0); 	
} 

/**
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/

