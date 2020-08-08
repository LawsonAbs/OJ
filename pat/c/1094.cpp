#include <cstdio> 
#include <queue>
#define maxn 1000
using namespace std;

struct Node{
	int childNum = 0;//������
	vector<int> child;//�洢���� 
};

int main(){
	queue<int> qu;
	int root = 01, num,father;//���ڵ�  �ڵ�����  ���ڵ��� 
	int i,j;
	Node node[maxn];
	int tempNode;//�ݴ��� 
	int index,tempChild;//����±�   ��ʱ�����ݴ� 
	vector<int> temp;//�ݴ�ͬ���еĽڵ� 
	
	scanf("%d %d",&num,&father);
	for(i = 0;i<father;i++){
		scanf("%d",&index);
		scanf("%d",&node[index].childNum);
		for( j = 0;j< node[index].childNum;j++){
			scanf("%d",&tempChild);		
			node[index].child.push_back(tempChild);
		}
	}
	
	qu.push(root); //��� 
	vector<int> level;//ÿ����������vector�� 
	int count = 0;//ÿ���ڵ����������� 
	j = 0;
	do{
		while(!qu.empty()){		
			j++; 
			count++; 
			temp.push_back(qu.front());//������temp�� 
			qu.pop();//���׳���			
		} 
							
		//һ�������ȫ ����Ϊ��			
		level.push_back(count);
		count = 0;//���� 			
		
		//temp[i]��ʾ���ڵ�ĵ�i+1���ڵ� 
		for(i = 0;i < temp.size();i++){//��temp�����нڵ�����к��ӽ����� 
			if(node[temp[i]].childNum!=0){//�����������Ϊ0 
				for(int k = 0;k < node[temp[i]].child.size();k++)
				qu.push(node[temp[i]].child[k]);//���뺢�� 
			} 
		}
		temp.clear();//���vector<int> temp�е����� 
	}while(j<num);
	
	int max = 0,maxLevel ;
	for(i = 0;i<level.size();i++){
		if(level[i] > max){
			max = level[i];
			maxLevel = i+1;
		}
	}
	printf("%d %d",max,maxLevel);
} 

/**
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
*/ 
