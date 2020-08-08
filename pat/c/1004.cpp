#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define maxSize 100010
using namespace std;

//建立一个树的结点类型 
typedef struct{
	int depth;//记录结点所在层次深度 
	vector<int> child;//孩子结点 
}BiTree;


BiTree bt[maxSize];//新建一个BiTree型数组 


//DFS遍历，记录每个结点的深度 
void  DFSBiTree(int index,int deep){
	bt[index].depth = deep;//改变所有结点的深度值
	
	//作为返回	
	if(bt[index].child.size() == 0){//如果是叶子结点 --->无孩子结点 
		return ;
	} 
	int i;
	for(i = 0;i< bt[index].child.size();i++){
		DFSBiTree(bt[index].child[i],deep+1);
	}
} 

//BFS层次遍历 
void BFSBiTree(int root){
	queue<int> qu;//申请一个队列 
	qu.push(root); //将根节点入队
	int num = 0;//记录每层叶子结点的数目 
	int current;//存储当前处理的结点值 
	int temp;		
	
	while(!qu.empty()){//如果队列非空
		temp = qu.front();//获得队首
		//printf("temp = %d,",temp); 
		int i ;//循环变量 
		if(bt[temp].child.size() > 0){//如果还有孩子结点 
			for(i = 0;i<bt[temp].child.size();i++){//将其孩子结点分别入队 
				qu.push(bt[temp].child[i]); 
			} 		
			qu.pop();//出队
			current = qu.front();//出队后的队首 		
			//printf("current = %d\n",current);	
			
			if(bt[temp].depth == bt[current].depth){//如果两层深度相同 
				//printf("temp.depth = %d , current.depth = %d\n",bt[temp].depth,bt[current].depth);
				if( bt[temp].child.size() == 0){//且temp为叶子结点 
					num++;
				}
			} 
			else{
				printf("%d ",num);
				num = 0;//置零 
			}
		}
		else{// 
			if( qu.size() > 1){//如果队列中还有很多元素 
				qu.pop();
				current = qu.front(); 
				if(bt[temp].depth == bt[current].depth){//如果两层深度相同 
					if( bt[temp].child.size() == 0){//且temp为叶子结点 
						num++;
					}
				} 
				else{
					num++; 
					printf("%d ",num);
					num = 0;//置零 
				}	
			}
			else{
				num++;//否则这个节点肯定为树中的最后一个节点，直接输出 
				printf("%d",num); 
				qu.pop(); 	
			}			
		} 		
	} 
}

int main(){
	int n,m;//n是结点数，m是非叶子结点数
	scanf("%d %d",&n,&m);
	int i ,j;
	
	for(i = 0;i<m;i++){
		int node,childNumber,childIndex;;//非叶子结点	//孩子结点数	 //孩子结点下标 		
		scanf("%d %d",&node,&childNumber);//输入非叶子结点的下标 以及 其孩子结点数 
		for(j = 1;j <= childNumber;j++){//输入孩子结点信息 --->根节点从1开始 
			scanf("%d",&childIndex);//输入孩子结点下标
			bt[node].child.push_back(childIndex); //加入到孩子节点中 
		}
	} 
	
	DFSBiTree(1,0);//根节点的下边是在1处，初始深度为0
	
//	for(j = 1 ;j <= n;j++){
//		printf("j = %d,",j);
//		for(i = 1;i <= bt[j].child.size();i++){
//			printf("%d ",bt[j].child[i-1]);//注意这里的孩子结点在数组中存储起始地址是0 
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
