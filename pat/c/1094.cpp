#include <cstdio> 
#include <queue>
#define maxn 1000
using namespace std;

struct Node{
	int childNum = 0;//孩子数
	vector<int> child;//存储孩子 
};

int main(){
	queue<int> qu;
	int root = 01, num,father;//根节点  节点总数  父节点数 
	int i,j;
	Node node[maxn];
	int tempNode;//暂存结点 
	int index,tempChild;//结点下标   临时孩子暂存 
	vector<int> temp;//暂存同层中的节点 
	
	scanf("%d %d",&num,&father);
	for(i = 0;i<father;i++){
		scanf("%d",&index);
		scanf("%d",&node[index].childNum);
		for( j = 0;j< node[index].childNum;j++){
			scanf("%d",&tempChild);		
			node[index].child.push_back(tempChild);
		}
	}
	
	qu.push(root); //入队 
	vector<int> level;//每层结点数存入vector中 
	int count = 0;//每个节点所含孩子数 
	j = 0;
	do{
		while(!qu.empty()){		
			j++; 
			count++; 
			temp.push_back(qu.front());//队首入temp中 
			qu.pop();//队首出队			
		} 
							
		//一层遍历完全 队列为空			
		level.push_back(count);
		count = 0;//重置 			
		
		//temp[i]表示根节点的第i+1个节点 
		for(i = 0;i < temp.size();i++){//将temp中所有节点的所有孩子结点入队 
			if(node[temp[i]].childNum!=0){//如果孩子数不为0 
				for(int k = 0;k < node[temp[i]].child.size();k++)
				qu.push(node[temp[i]].child[k]);//加入孩子 
			} 
		}
		temp.clear();//清除vector<int> temp中的内容 
	}while(j<num);
	
	int max = 0,maxLevel ;
	for(i = 0;i<level.size();i++){
		if(level[i] > max){
			max = level[i];
			maxLevel = i+1;
		}
	}
	printf("%d %d",max,maxLevel);
} 

/**
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
*/ 
