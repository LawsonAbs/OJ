#include <cstdio>
#include <vector>
#include <cmath>
#define maxn 100000
const double eps = 1e-8;
#define equ(a,b)	((fabs((a) - (b))) < (eps))
 
using namespace std;

struct Node{
	double price;//���ۼ۸�
	int leafFlag;//Ҷ�ӱ�־
	vector<int> child;//�洢�����±�
	int childNum;//������	
};
double increment;//�Ƿ�--�̶�--ȫ�ֱ��� 
double minPrice = 10000000.0 ;//������ۼ�,һ��Ҫ�󣬷���������ݵ�price����ڸ�ֵ 
 
Node node[maxn]; 

//����--�������ۼ۸�
//rootΪ���ڵ�  levelΪ���  priceΪ�۸� 
void DFS (int root,double price,double &minPrice){
	if(node[root].childNum!=0){
		for(int i = 0;i < node[root].childNum;i++){//�������еĺ��� 
		//	printf("next root = %d\n",node[root].child[i]);
			DFS(node[root].child[i],price + price*(increment/100),minPrice);
		} 		
	}
	else{//��ֵ ������ 
		node[root].price = price;
		if(minPrice > price){
			minPrice = price;
			//printf("minPrice = %lf\n",minPrice);		
		} 
		//printf("root = %d, price = %lf\n",root,price);
		return;		 
	}
} 


int main(){
	int nodeNum;//�����
	double  startPrice;//��ʼ�۸�	
	int i,j;
	int tempIndex;//�ݴ����� 
	vector<int> leafNodeIndex;//��¼Ҷ�ӽڵ��±� 
	int count = 0;

	scanf("%d %lf %lf",&nodeNum,&startPrice,&increment);
	for(i = 0;i< nodeNum;i++){
		scanf("%d",&node[i].childNum);		
		if(node[i].childNum!=0) {
			for(j = 0;j< node[i].childNum;j++){
				scanf("%d",&tempIndex);
				node[i].child.push_back(tempIndex);
			} 
		} 
		else	leafNodeIndex.push_back(i); //��¼Ҷ�ӽڵ��±� 
	}
	
	DFS(0,startPrice,minPrice);
	
	for(i = 0;i < leafNodeIndex.size();i++){
		if(equ(node[leafNodeIndex[i]].price , minPrice)){
			count++;
		}		
	}
	printf("%.4lf ",minPrice);
	printf("%d",count);
}
/**
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0

1 1.80 1.00
0
ע��
1.�����ú�����ʹ��ȫ�ֱ����Ƿ��ı�ȫ�ֱ�����ֵ��
 
*/
