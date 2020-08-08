#include <stdio.h>
#include <algorithm>
#include <vector>

#define maxSize 100020
using namespace std;

//��������� 
typedef struct {
	int data;//��ŵ�����
	vector<int> a;//����һ���䳤����a 
}TreeNode;


TreeNode tn[maxSize];//����һ��TreeNode 
int maxDepth = 0,num = 0;//�����ȣ��Լ����������ȵĽ������ 

void DFS(int index,int depth){
	if(tn[index].a.size() == 0){
		if(depth > maxDepth){
			maxDepth = depth;
			num = 1;
		}
		else if(depth == maxDepth){
			num++;
		}
		return;
	}	
	for(int i = 0;i < tn[index].a.size();i++){
		DFS(tn[index].a[i],depth+1);//�ݹ����index���ӽڵ�	
	} 
} 

int main(){	
	
	int number;
	double p,r;//P��ԭ��,rΪ������ 
	scanf("%d %lf %lf",&number,&p,&r);
	r = r/100;//�ٷֱ� 
	
	int root;//��¼���ڵ� 
	int i;
	int member;//��Ա�� 
	for(i = 0;i< number;i++){
		scanf("%d",&member);
		if(member != -1)		tn[member].a.push_back(i);//member�ǵ�i����Ա�Ĺ�Ӧ�̣���member�Ǹ��ڵ㣬��i����Ա���ӽڵ� 
		else root = i;//��¼���ڵ� 
	} 	
//	for(i = 0;i< number;i++){
//		printf("i = %d: ",i);
//		for(int j = 0;j < tn[i].a.size();j++){
//			printf("%d ",tn[i].a[j]);	
//		}printf("\n");		
//	} 
	
	DFS(root,0);
	for(int i = 0;i< maxDepth;i++){
		p =  (1 + r)*p ; 	
	}	
	printf("%.2lf %d",p,num);
}
/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
**/
