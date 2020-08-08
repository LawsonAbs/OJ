#include <stdio.h>
#define maxn 10000
#include <vector>
using namespace std;

struct Node{//节点所含节点数、孩子结点下标 
	int childNumber;//孩子数
	vector <int> child;//孩子 
};

int main(){
	int N,M,S;//N,the number of nodes in a tree  M,the number of non-leaf node  S,the given weight number
	scanf("%d %d %d",&N,&M,&S);
	int weight[maxn];//存储树的节点权值
	int i,j; 
	for(i = 0;i<N;i++){
		scanf("%d ",&weight[i]);//输入节点权值 
	}
	
	vector<int>  fatherNode[maxn];//存储父节点的孩子 
	int childNumber;//父节点所含的孩子数 
	int temp;//暂存孩子结点的下标 
	vector<int> ::iterator it;//遍历变量 
	 
	for(i = 0;i < M ;i++){
		scanf("%d",&childNumber);
		for(j = 0;j < childNumber; j++){
			scanf("%d ",&temp);
			fatherNode.push_back(temp); 
		}
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
*/ 



/**
//#include <iostream>
#include <cstdio>
using namespace std;
#include <vector>

int main(){
	vector<int> test;
	int i ;
	for(i = 0; i< 5;i++){
		test.push_back(i);
	}
	vector<int> ::iterator it;
	for (it = test.begin();it!=test.end();it++){
		printf("%d ",*it);
	} 
	return 0 ;
}


注：
1.#include <cstdio> 与 #include <stdio.h>与#include <iostream>有什么区别？  

*/
