#include <iostream>
#define maxn 10000
#include <vector>
#include <algorithm> 
using namespace std;

struct Node{//�ڵ�
	int childNumber;//��������ʼ��Ϊ0 
	vector <int> child;//�����±�
	int weight;//�ڵ�Ȩֵ 
	int flag;//�ڵ��־ 
};


Node  node[maxn];//�ڵ�
int N,M,S;//N,the number of nodes in a tree  M,the number of non-leaf node  S,the given weight number
int path[maxn];//��¼·�� 


bool cmp(int a ,int b){//�ȽϺ��� 
	return node[a].weight > node[b].weight;//���սڵ����ݴӴ�С���� 
}

void DFS(int root,int sumW,int nodeNum);//���� 

int main(){
	int temp;//�ݴ溢��ֵ
	int index;//�ݴ������ 
	int i ,j;
	
	scanf("%d%d%d",&N,&M,&S);
	for(i = 0;i<N;i++){
		scanf("%d",&node[i].weight);//����ڵ�Ȩֵ 
		node[i].flag = 0;//�ڵ��־��ʼΪ0
		node[i].childNumber = 0;
	}
	
	for(i = 0;i < M ;i++){
		scanf("%d",&index);
		scanf("%d",&node[index].childNumber); 
		for(j = 0;j < node[index].childNumber; j++){
			scanf("%d",&temp);//��������庢�ӽڵ���±� 
			node[index].child.push_back(temp); 
		}
		sort(node[index].child.begin(),node[index].child.end(),cmp);//������ 
	}
	
	path[0] = 0;//·���ĵ�һ���ڵ�����Ϊ0�Ž�� 
	DFS(0,0,1);//����    root = 0,sum = 0; 
}
  

//ʹ����������¼·��֮�� 
void DFS(int root,int sumW,int nodeNum){//�Ӹ���ʼ 
	if(sumW >S){//������ڸ���ֵ���򷵻�
		return ;
	}
	else{
		sumW += node[root].weight;//��Ȩֵ
		//printf("root = %d, sumW = %d\n",root,sumW);	
		if(sumW == S && node[root].child.size()!=0)	
			return;
		else if (sumW == S && node[root].child.size()==0){
			for(int i = 0;i<nodeNum;i++){
				printf("%d",node[path[i]].weight);
				if(i < nodeNum -1) 
					printf(" ");
				else
					printf("\n");
			}	
		}
	}
	for(int j = 0;j<node[root].child.size();j++){
		path[nodeNum] = node[root].child[j];//���ڵ�child[j]���뵽path 
		DFS(node[root].child[j],sumW,nodeNum+1);//�ڵ�ĺ��ӽ��				
	} 
} 
 
      
/*sample input
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
ע
1.#include <cstdio> �� #include <stdio.h>��#include <iostream>��ʲô����  
2.printf("%02d ",node[i].number);//�����λ���� 
3.��ν�����ú�����ʹ��main�����б��������⣿ 
4.�������ʱ����ջʹ�õ����⣬����ʵ���Ǵ�������������� 
�� //scanf("%d %d",&index,&node[index].childNumber);��䡣��ʵ��������ýڵ㺢������node[index].childNumber����������ڵ����(index)
������ΪindexҲ������ֵ�����Ի���ִ���
���Դ��������������Ⱥ��ϵ�����ݣ�һ���÷ֿ����룡 
5.���ǵ����������������������Ŵ�ģ����ǾͿ��Ի�����˼�����Ƚ�������Ȼ���ٽ��м�����������
6.ȫ�ֱ�����ֲ�����������
7.ʹ�ú������������������ 
 
	for(i = 0;i< M;i++){
		printf("%02d %d ",node[i].number,node[i].childNumber);
		for(j = 0;j<node[i].childNumber;j++){
			printf("%02d ",node[i].child[j]);			
		}
		printf("flag = %d",node[i].flag); 
		cout<<endl;	
	}
 
	//��ȷ���1 
	for(i = 0;i< N;i++){
		printf("%02d %d ",i,node[i].childNumber);
		for(vector<int> ::iterator it = node[i].child.begin();it != node[i].child.end();it++){
			printf("%d ",*it);
		}
		printf("\n"); 
	}
	
	//��ȷ���2 
	for(i = 0;i< N;i++){
		printf("%02d %d ",i,node[i].childNumber);
		for(j =0 ;j<node[i].child.size();j++){
			printf("%d ",node[i].child[j]);
		}
		printf("\n"); 
	}
**/
