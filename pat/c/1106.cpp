#include <cstdio>
#include <vector>
#include <cmath>
#define maxn 100000
const double eps = 1e-8;
#define equ(a,b)	((fabs((a) - (b))) < (eps))
 
using namespace std;

struct Node{
	double price;//销售价格
	int leafFlag;//叶子标志
	vector<int> child;//存储孩子下标
	int childNum;//孩子数	
};
double increment;//涨幅--固定--全局变量 
double minPrice = 10000000.0 ;//最低零售价,一定要大，否则测试数据的price会大于该值 
 
Node node[maxn]; 

//深搜--计算销售价格
//root为根节点  level为层次  price为价格 
void DFS (int root,double price,double &minPrice){
	if(node[root].childNum!=0){
		for(int i = 0;i < node[root].childNum;i++){//遍历所有的孩子 
		//	printf("next root = %d\n",node[root].child[i]);
			DFS(node[root].child[i],price + price*(increment/100),minPrice);
		} 		
	}
	else{//赋值 并返回 
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
	int nodeNum;//结点数
	double  startPrice;//初始价格	
	int i,j;
	int tempIndex;//暂存索引 
	vector<int> leafNodeIndex;//记录叶子节点下标 
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
		else	leafNodeIndex.push_back(i); //记录叶子节点下标 
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
注：
1.被调用函数中使用全局变量是否会改变全局变量的值？
 
*/
