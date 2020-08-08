#include <cstdio>
#include <algorithm> 
#define maxn 10000
using namespace std;

int value[maxn];//��ʼ���� 
int nodeNum;

int CBT[maxn];//��ȫ����������--->������洢 

//ʹ�����������ֵ�������������� 
void inOrder(int root,int& count){
	if(root > nodeNum)	return;
	else {
		inOrder(root*2,count);
		CBT[root] = value[count++];//��ֵ 
		inOrder((root*2)+1,count);		
	}	
} 

int main(){		
	int i ;
	int count = 0 ;
	scanf("%d",&nodeNum);//����ڵ���
	for(i = 0;i< nodeNum;i++){
		scanf("%d",&value[i]);
	}
	sort(value,value+nodeNum);	
	//��ʼroot = 1 
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

