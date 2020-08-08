#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define maxSize 100
#define null NULL


typedef struct BiTree{
	struct BiTree *lChild,*rChild;//��������ָ�� 
	int data;//������ 
};


int number;
int postOrder[maxSize];
int inOrder[maxSize];

//�Ӷ��������ҳ���㲢����
//ע�ⷵ�ص��Ƕ�������ͷ���ָ�� 
BiTree* foundData(int postLeft,int postRight,int inLeft,int inRight){

	if(postRight < postLeft){
		return null;
	} 
	int i ;
	int root;//���ڵ��ֵ 
	int rootIndex;//���ڵ������������е��±� 
	
	root = postOrder[postRight];//�ҵ�root 
	BiTree *T;
	T = new BiTree;//ָ�����Ľ�� 
	
	T->data = root;  
	
	//ע��ϸ�ڣ�forѭ���߽�ȡֵ 
	for(i = inLeft;i <= inRight;i++){
		if(inOrder[i] == postOrder[postRight]){
			rootIndex = i;//��¼�±� 
			break;
		}	
	}
	int leftNodeNumber ;//��ʾ�����������Ľ����� 
	leftNodeNumber =  rootIndex - inLeft;//ע���Ǽ�ȥinLeft,����postLeft 
	
	//����Ĺؼ����ڣ�ȷ����Χֵ��ѡȡ 
	/*
	1.�����������⣬����Ӧ�����ȳ�ȡ��һ���Ȼ�����һ������в���
	2.���鷽�������ö��������������ܽ�ı��ʽ���м��飬�ж�����ȷ�� 
	*/ 
	T->lChild = foundData(postLeft, postLeft + leftNodeNumber -1,inLeft,rootIndex-1);//�������� 
	T->rChild = foundData(postLeft + leftNodeNumber, postRight - 1,rootIndex + 1,inRight);//�������� 
	return T;
}

//ǰ����� 
void preTraverseBiTree(BiTree *T){
	if(T == null){
		return ;
	}
	printf("%d ",T->data);
	preTraverseBiTree(T->lChild);
	preTraverseBiTree(T->rChild);	
}

//ʹ�ò�α�����BFS�� 
void BfsBiTree(BiTree *T){
	int count = 0;//������� 
	queue <BiTree*> q;//ʹ�ö��д洢ָ���� 
	q.push(T);//���Ƚ����ڵ����
	while(!q.empty()){//�����зǿ�ʱ 			
		BiTree* now = q.front();//�õ����� 
		q.pop(); //����������
		count ++;
		if(count < number )		printf("%d ",now->data); //��� 
		else printf("%d",now->data); 
		if(now->lChild!=null)		q.push(now->lChild);//��������� --->ע��������now��������T!! 
		if(now->rChild!=null)     q.push(now->rChild);//��������� 
	} 
}

int main(){	
	scanf("%d",&number);
	int i;
	for(i = 0;i< number;i++){
		scanf("%d",&postOrder[i]);
	}	
	//����inOrder 
	for(i = 0;i< number;i++){
		scanf("%d",&inOrder[i]);
	}	
	BiTree *T;
	T = foundData(0,number-1,0,number-1); //������Ϊ���ڵ�
	//preTraverseBiTree(T);//ǰ�����������
	BfsBiTree(T);
}
/*
4
2 3 1 4
1 2 3 4
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
**/ 
