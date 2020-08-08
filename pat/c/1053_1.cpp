#include <iostream>
#define maxn 10000
#include <vector>
#include <algorithm> 
using namespace std;

struct Node{//节点
	int childNumber;//孩子数初始化为0 
	vector <int> child;//孩子下标
	int weight;//节点权值 
	int flag;//节点标志 
};


Node  node[maxn];//节点
int N,M,S;//N,the number of nodes in a tree  M,the number of non-leaf node  S,the given weight number
int path[maxn];//记录路径 


bool cmp(int a ,int b){//比较函数 
	return node[a].weight > node[b].weight;//按照节点数据从大到小排序 
}

void DFS(int root,int sumW,int nodeNum);//深搜 

int main(){
	int temp;//暂存孩子值
	int index;//暂存结点序号 
	int i ,j;
	
	scanf("%d%d%d",&N,&M,&S);
	for(i = 0;i<N;i++){
		scanf("%d",&node[i].weight);//输入节点权值 
		node[i].flag = 0;//节点标志初始为0
		node[i].childNumber = 0;
	}
	
	for(i = 0;i < M ;i++){
		scanf("%d",&index);
		scanf("%d",&node[index].childNumber); 
		for(j = 0;j < node[index].childNumber; j++){
			scanf("%d",&temp);//再输入具体孩子节点的下标 
			node[index].child.push_back(temp); 
		}
		sort(node[index].child.begin(),node[index].child.end(),cmp);//先排序 
	}
	
	path[0] = 0;//路径的第一个节点设置为0号结点 
	DFS(0,0,1);//深搜    root = 0,sum = 0; 
}
  

//使用深搜来记录路径之和 
void DFS(int root,int sumW,int nodeNum){//从根开始 
	if(sumW >S){//如果大于给定值，则返回
		return ;
	}
	else{
		sumW += node[root].weight;//加权值
		//printf("root = %d, sumW = %d\n",root,sumW);	
		if(sumW == S && node[root].child.size()!=0)	
			return;
		else if (sumW == S && node[root].child.size()==0){
			for(int i = 0;i<nodeNum;i++){
				printf("%d",node[path[i]].weight);
				if(i < nodeNum -1) 
					printf(" ");
				else
					printf("\n");
			}	
		}
	}
	for(int j = 0;j<node[root].child.size();j++){
		path[nodeNum] = node[root].child[j];//将节点child[j]加入到path 
		DFS(node[root].child[j],sumW,nodeNum+1);//节点的孩子结点				
	} 
} 
 
      
/*sample input
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
注
1.#include <cstdio> 与 #include <stdio.h>与#include <iostream>有什么区别？  
2.printf("%02d ",node[i].number);//输出两位数字 
3.如何解决调用函数中使用main函数中变量的问题？ 
4.输入输出时存在栈使用的问题，即事实上是从右往左输入输出 
如 //scanf("%d %d",&index,&node[index].childNumber);语句。事实上是输入该节点孩子数（node[index].childNumber），再输入节点序号(index)
但是因为index也是输入值，所以会出现错误。
所以存在这种输入有先后关系的数据，一定得分开输入！ 
5.考虑到满足提议的输出（先输出序号大的）我们就可以换方面思考，先进行排序，然后再进行计算求和输出。
6.全局变量与局部变量的区别
7.使用函数参数解决调用问题 
 
	for(i = 0;i< M;i++){
		printf("%02d %d ",node[i].number,node[i].childNumber);
		for(j = 0;j<node[i].childNumber;j++){
			printf("%02d ",node[i].child[j]);			
		}
		printf("flag = %d",node[i].flag); 
		cout<<endl;	
	}
 
	//正确输出1 
	for(i = 0;i< N;i++){
		printf("%02d %d ",i,node[i].childNumber);
		for(vector<int> ::iterator it = node[i].child.begin();it != node[i].child.end();it++){
			printf("%d ",*it);
		}
		printf("\n"); 
	}
	
	//正确输出2 
	for(i = 0;i< N;i++){
		printf("%02d %d ",i,node[i].childNumber);
		for(j =0 ;j<node[i].child.size();j++){
			printf("%d ",node[i].child[j]);
		}
		printf("\n"); 
	}
**/
