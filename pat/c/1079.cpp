#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define maxSize 100010

typedef struct {
	int weight;//�ֿ��е����� 
	vector<int> child;//ʹ��vector�洢���ӽڵ�---->��ʡ�ռ� 
}BiTree;


BiTree bt[maxSize];//����һ����ô���BiTree�������� 
double sum = 0.0;//�洢�ܵý�Ǯ�� 
double p,r;//number�ǽ�������p�Ǽ۸�r��������

//��ȱ��� 
void DFS(int index,int depth){//index�ǽ���±꣬depth�ǽ������ 
	if(bt[index].weight!=0){//�ж��Ƿ���retailer 
		int i;//ѭ��������� 
		double temp = p;//��ʱ���� 
//		for(i = 0;i< depth;i++){
//			 temp = temp*(1+r/100); 
//		} 
		temp = pow((1+r/100),depth) * temp;
		temp = temp*bt[index].weight;
		sum += temp;//�������� 
	}
	int k; 
	for(k = 0;k < bt[index].child.size();k++ ){		
		DFS(bt[index].child[k],depth+1); 
	}
} 

int main(){
	int n;
	scanf("%d %lf %lf",&n,&p,&r);//������Ϣ
	int i,j;
	int number, cd;//number��ʾ�������֣�cd��ʾ���Ǻ��ӽ���±� 
	for(i = 0;i< n;i++){
		scanf("%d",&number);			
		if(number != 0){
			bt[i].weight = 0;//����retailer�Ľ��������ʼ��Ϊ0
			for(j = 0; j< number;j++){
				scanf("%d",&cd);		
				bt[i].child.push_back(cd);//���뵽�����±��� 
			}
		}
		else{//��retailer��������ڻ����� 
			scanf("%d",&bt[i].weight);
		} 		 
	}
	DFS(0,0);//��ȱ���
	printf("%.1lf",sum); 
} 	

/**
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
/**��֤��� 
	for(i = 0;i < n;i++){
		printf("i = %d,",i); 
		if(bt[i].child.size() > 0){
			for(j = 0;j<bt[i].child.size();j++){
				printf("%d ", bt[i].child[j]);//������ӽ��	
			}printf("\n");
		}
		else
		printf("weight = %d\n",bt[i].weight);//����������� 		
	} 
**/

 
