#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define maxSize 100010
using namespace std;

//����һ�����Ľ������ 
typedef struct{
	int depth;//��¼������ڲ����� 
	vector<int> child;//���ӽ�� 
}BiTree;


BiTree bt[maxSize];//�½�һ��BiTree������ 


//DFS��������¼ÿ��������� 
void  DFSBiTree(int index,int deep){
	bt[index].depth = deep;//�ı����н������ֵ
	
	//��Ϊ����	
	if(bt[index].child.size() == 0){//�����Ҷ�ӽ�� --->�޺��ӽ�� 
		return ;
	} 
	int i;
	for(i = 0;i< bt[index].child.size();i++){
		DFSBiTree(bt[index].child[i],deep+1);
	}
} 

//BFS��α��� 
void BFSBiTree(int root){
	queue<int> qu;//����һ������ 
	qu.push(root); //�����ڵ����
	int num = 0;//��¼ÿ��Ҷ�ӽ�����Ŀ 
	int current;//�洢��ǰ����Ľ��ֵ 
	int temp;		
	
	while(!qu.empty()){//������зǿ�
		temp = qu.front();//��ö���
		//printf("temp = %d,",temp); 
		int i ;//ѭ������ 
		if(bt[temp].child.size() > 0){//������к��ӽ�� 
			for(i = 0;i<bt[temp].child.size();i++){//���亢�ӽ��ֱ���� 
				qu.push(bt[temp].child[i]); 
			} 		
			qu.pop();//����
			current = qu.front();//���Ӻ�Ķ��� 		
			//printf("current = %d\n",current);	
			
			if(bt[temp].depth == bt[current].depth){//������������ͬ 
				//printf("temp.depth = %d , current.depth = %d\n",bt[temp].depth,bt[current].depth);
				if( bt[temp].child.size() == 0){//��tempΪҶ�ӽ�� 
					num++;
				}
			} 
			else{
				printf("%d ",num);
				num = 0;//���� 
			}
		}
		else{// 
			if( qu.size() > 1){//��������л��кܶ�Ԫ�� 
				qu.pop();
				current = qu.front(); 
				if(bt[temp].depth == bt[current].depth){//������������ͬ 
					if( bt[temp].child.size() == 0){//��tempΪҶ�ӽ�� 
						num++;
					}
				} 
				else{
					num++; 
					printf("%d ",num);
					num = 0;//���� 
				}	
			}
			else{
				num++;//��������ڵ�϶�Ϊ���е����һ���ڵ㣬ֱ����� 
				printf("%d",num); 
				qu.pop(); 	
			}			
		} 		
	} 
}

int main(){
	int n,m;//n�ǽ������m�Ƿ�Ҷ�ӽ����
	scanf("%d %d",&n,&m);
	int i ,j;
	
	for(i = 0;i<m;i++){
		int node,childNumber,childIndex;;//��Ҷ�ӽ��	//���ӽ����	 //���ӽ���±� 		
		scanf("%d %d",&node,&childNumber);//�����Ҷ�ӽ����±� �Լ� �亢�ӽ���� 
		for(j = 1;j <= childNumber;j++){//���뺢�ӽ����Ϣ --->���ڵ��1��ʼ 
			scanf("%d",&childIndex);//���뺢�ӽ���±�
			bt[node].child.push_back(childIndex); //���뵽���ӽڵ��� 
		}
	} 
	
	DFSBiTree(1,0);//���ڵ���±�����1������ʼ���Ϊ0
	
//	for(j = 1 ;j <= n;j++){
//		printf("j = %d,",j);
//		for(i = 1;i <= bt[j].child.size();i++){
//			printf("%d ",bt[j].child[i-1]);//ע������ĺ��ӽ���������д洢��ʼ��ַ��0 
//		}
//		printf(",depth = %d\n",bt[j].depth);
//	}
	 
	BFSBiTree(1); 
}
/**
2 1
01 1 02

2 1
1 1 2

10 5
01 3 02 03 04
02 2 05 06
03 2 07 08
04 1 09
05 1 10
*/
