#include<cstdio>
#include<iostream>
#include<cstring> 
#include<set>
#define maxn 2005
//因为maxn是用于做查询输入的，所以其范围可能会比较大，可能会超过200 

using namespace std;

int edge[maxn][maxn];//使用邻接矩阵存边的信息 
//需要注意的是：如果顶点的序号是从 0 -> (N-1) ，那么我们可以使用edge[N][N]作为存储
//但是如果顶点的序号是从 1 -> N ，那么就必须是 edge[N+1][N+1]，否则会出现段错误。
//在这里，我使用的是 maxn 作为存储 
 
int main(){
	int  N,M,K;
	cin >> N>>M;
	int i,j,z;	
	int ver1,ver2; 
	set<int> vertex;
	for(i = 0;i< M;i++){
		cin >> ver1 >> ver2;
		edge[ver1][ver2] = 1;//有边 
		edge[ver2][ver1] = 1;//有边 
	}
	
	cin >> K;
	int verNum;
	int query[maxn];
	for(i = 0;i< K;i++){
		cin >> verNum;		 
		memset(query,0,sizeof(query));//重置为0 
		vertex.clear();		
		for(j = 0;j < verNum;j++){
			cin >> query[j];
			vertex.insert(query[j]);
		}
		if(verNum != (N+1) || query[0] != query[N] || vertex.size()!=N) {//是否 simple || 如果起点和终点不同，不是cycle ||如果不涉及到所有的节点 
			cout <<"NO\n";
		}
		else{//这个时候才进入判断
			for(z = 0; z < verNum -1; z++) {
				//cout <<  query[z]<<" ";
				if(edge[query[z]][query[z+1]] != 1){				
					cout <<"NO\n";
					break;
				}				
			}
			if(z == verNum - 1){
				cout <<"YES\n";
			}
		}
	}
}
/*
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1

6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 2 1 2 1 2 1

6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 6 1 2 1 2 1


6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 1 1 1 1 1 1

3 1
1 2
1
4 1 2 3 1

3 2
1 2
2 3
1
4 1 2 3 1


3 3
1 2
2 3
1 3
1
4 1 2 3 1


6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
1
7 1 2 5 1 2 5 1
*/ 
