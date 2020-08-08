#include <cstdio>
#include <algorithm> 
#define maxn 10000
using namespace std;

int value[maxn];//初始序列 
int nodeNum;

int CBT[maxn];//完全二叉排序树--->用数组存储 

//使用中序遍历赋值完整二叉排序树 
void inOrder(int root,int& count){
	if(root > nodeNum)	return;
	else {
		inOrder(root*2,count);
		CBT[root] = value[count++];//赋值 
		inOrder((root*2)+1,count);		
	}	
} 

int main(){		
	int i ;
	int count = 0 ;
	scanf("%d",&nodeNum);//输入节点数
	for(i = 0;i< nodeNum;i++){
		scanf("%d",&value[i]);
	}
	sort(value,value+nodeNum);	
	//初始root = 1 
	inOrder(1,count);
	for(i = 1;i <= nodeNum;i++ ){
		if(i!=nodeNum)	printf("%d ",CBT[i]);
		else printf("%d",CBT[i]);
	}
} 

/**
10
1 2 3 4 5 6 7 8 9 0
*/

