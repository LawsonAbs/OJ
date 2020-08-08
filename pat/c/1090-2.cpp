#include <stdio.h>
#include <algorithm>
#include <vector>

#define maxSize 100020
using namespace std;

//定义树结点 
typedef struct {
	int data;//存放的数据
	vector<int> a;//声明一个变长数组a 
}TreeNode;


TreeNode tn[maxSize];//申请一个TreeNode 
int maxDepth = 0,num = 0;//最大深度，以及具有最大深度的结点数量 

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
		DFS(tn[index].a[i],depth+1);//递归访问index的子节点	
	} 
} 

int main(){	
	
	int number;
	double p,r;//P是原价,r为增长率 
	scanf("%d %lf %lf",&number,&p,&r);
	r = r/100;//百分比 
	
	int root;//记录根节点 
	int i;
	int member;//会员号 
	for(i = 0;i< number;i++){
		scanf("%d",&member);
		if(member != -1)		tn[member].a.push_back(i);//member是第i个会员的供应商，即member是父节点，第i个会员是子节点 
		else root = i;//记录根节点 
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
