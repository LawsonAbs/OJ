#include <cstdio>
#include <algorithm> 
#include <queue>
#define maxn 10000
using namespace std;

struct Node{
	int data;
	int left,right;//���Һ��� 
};

queue<int> qu;
int value[maxn];//��ʼ���� 
int nodeNum;
Node node[maxn];//��ȫ����������--->������洢 

//ʹ�����������ֵ�������������� 
void inOrder(int root,int& count){
	if(root == -1)	return;//�������Ϊ-1 
	else {
		inOrder(node[root].left,count);
		node[root].data = value[count++];//��ֵ 				
	}	
	if(root == -1)	return;
	else	inOrder(node[root].right,count);
} 

//��α���CBT 
void levelCBT(int root){
	int count = 0;
	qu.push(root);
	while(!qu.empty()){
		if(count != nodeNum-1)	printf("%d ",node[qu.front()].data);
		else printf("%d",node[qu.front()].data);
		if(node[qu.front()].left!=-1)	qu.push(node[qu.front()].left);
		if(node[qu.front()].right!=-1)	qu.push(node[qu.front()].right);
		qu.pop();//ɾ������
		count++; 
	}
} 

int main(){		
	int i ;
	int count = 0 ;
	scanf("%d",&nodeNum);//����ڵ���
	for(i = 0;i< nodeNum;i++){
		scanf("%d %d",&node[i].left,&node[i].right);		
	}
	
	//���벢���� 
	for(i = 0;i < nodeNum;i++){
		scanf("%d",&value[i]);
	}	
	sort(value,value+nodeNum);	
	
	//��ʼroot = 0 
	inOrder(0,count);
	 		
	//��α�������� 
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

