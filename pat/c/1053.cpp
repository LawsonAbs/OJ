#include <stdio.h>
#define maxn 10000
#include <vector>
using namespace std;

struct Node{//�ڵ������ڵ��������ӽ���±� 
	int childNumber;//������
	vector <int> child;//���� 
};

int main(){
	int N,M,S;//N,the number of nodes in a tree  M,the number of non-leaf node  S,the given weight number
	scanf("%d %d %d",&N,&M,&S);
	int weight[maxn];//�洢���Ľڵ�Ȩֵ
	int i,j; 
	for(i = 0;i<N;i++){
		scanf("%d ",&weight[i]);//����ڵ�Ȩֵ 
	}
	
	vector<int>  fatherNode[maxn];//�洢���ڵ�ĺ��� 
	int childNumber;//���ڵ������ĺ����� 
	int temp;//�ݴ溢�ӽ����±� 
	vector<int> ::iterator it;//�������� 
	 
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


ע��
1.#include <cstdio> �� #include <stdio.h>��#include <iostream>��ʲô����  

*/
