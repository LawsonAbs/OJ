#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define maxSize 100010

typedef struct {
	int weight;//仓库中的数据 
	vector<int> child;//使用vector存储孩子节点---->节省空间 
}BiTree;


BiTree bt[maxSize];//申请一个这么大的BiTree类型数组 
double sum = 0.0;//存储总得金钱数 
double p,r;//number是结点个数，p是价格，r是增长率

//深度遍历 
void DFS(int index,int depth){//index是结点下标，depth是结点的深度 
	if(bt[index].weight!=0){//判断是否是retailer 
		int i;//循环计算变量 
		double temp = p;//临时变量 
//		for(i = 0;i< depth;i++){
//			 temp = temp*(1+r/100); 
//		} 
		temp = pow((1+r/100),depth) * temp;
		temp = temp*bt[index].weight;
		sum += temp;//计算总数 
	}
	int k; 
	for(k = 0;k < bt[index].child.size();k++ ){		
		DFS(bt[index].child[k],depth+1); 
	}
} 

int main(){
	int n;
	scanf("%d %lf %lf",&n,&p,&r);//输入信息
	int i,j;
	int number, cd;//number表示的是数字，cd表示的是孩子结点下标 
	for(i = 0;i< n;i++){
		scanf("%d",&number);			
		if(number != 0){
			bt[i].weight = 0;//将非retailer的结点重量初始化为0
			for(j = 0; j< number;j++){
				scanf("%d",&cd);		
				bt[i].child.push_back(cd);//加入到数组下标中 
			}
		}
		else{//是retailer，则输入囤货重量 
			scanf("%d",&bt[i].weight);
		} 		 
	}
	DFS(0,0);//深度遍历
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
/**验证输出 
	for(i = 0;i < n;i++){
		printf("i = %d,",i); 
		if(bt[i].child.size() > 0){
			for(j = 0;j<bt[i].child.size();j++){
				printf("%d ", bt[i].child[j]);//输出孩子结点	
			}printf("\n");
		}
		else
		printf("weight = %d\n",bt[i].weight);//输出货物重量 		
	} 
**/

 
