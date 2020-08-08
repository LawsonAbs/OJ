#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	vector <int> child;
};

int main(){
	Node node[10];
	int i ,j;
	int temp;//暂存 
	int childNumber;
	
	for(i = 0;i< 10 ;i++){
		node[i].data = i;
		scanf("%d",&childNumber);//输入孩子数目 
		for(int j = 0;j<childNumber;j++){
			scanf("%d",&temp);
			node[i].child.push_back(temp); 
		}
	}	
	printf("输出1\n");
	for(i =  0;i < 10;i++){
		printf("node[i].data = %d ",node[i].data);
		for(vector<int> ::iterator it = node[i].child.begin();it != node[i].child.end();it++){
			printf("%d ",*it);
		}
		printf("\n");
	}
	
	printf("输出2\n");
	for(i =  0;i < 10;i++){
		printf("node[i].data = %d ",node[i].data);
		for(j = 0;j<node[i].child.size();j++){
			printf("%d ",node[i].child[j]);
		}
		printf("\n");
	}	
}
/**
1 1
2 1 2
3 1 2 3
4 1 2 3 4
5 1 2 3 4 5
2 6 2
3 1 2 9
4 8 9 2 4
1 10
2 5 3

*/
