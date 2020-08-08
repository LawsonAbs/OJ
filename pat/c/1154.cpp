#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>
#define maxn 10005

 
using namespace std;

int edge[maxn][maxn];//用于存储边的信息
 
int main(){
	int N,M,K;
	cin >> N >> M;
	int i,j,k;
	int ver1,ver2; 
	for(i = 0;i<M;i++){
		cin >> ver1 >> ver2;
		edge[ver1][ver2] = 1;
		edge[ver2][ver1] = 1;
	}
	
	cin >> K;
	int query[maxn];
	//int color[maxn];//注意这里的color的取值范围是maxn，之所以是maxn，其原因是N个节点，至多有N个颜色 
	//但是使用数组并不合适，因为其颜色可能超过下标存储，即出现段错误，所以建议使用 set 存储，非常直接【因为set本身可以去重】 
	set<int> color;
	int flag ;
	for(i = 0 ;i< K;i++){
		//初始化信息 
		flag = 0;
		color.clear();
		//memset(color,0,sizeof(color));
				
		//输入各个顶点的 染色 情况 
		for(j = 0;j< N;j++){
			cin >> query[j];
			color.insert(query[j]) ;
		}
		
		//进行处理
		//因为是遍历节点，所以比较慢。应该遍历颜色信息 
		for(j = 0;j< N ;j++){
			for(k= j+1 ; k < N; k++){
				if(edge[j][k] == 1 && query[j] == query[k] ){//说明两个顶点之间有边 			
						flag =1 ;
						break; 					
				}
			}
			if(flag == 1) {
				cout << "No" << "\n";
				break;	
			}
		}
		if(j == N){			
			cout << color.size() << "-coloring"<<"\n";
		}
	}
}
/*
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
4
0 1 0 1 4 1 0 1 3 0
0 1 0 1 4 1 0 1 0 0
8 1 0 1 4 1 0 5 3 0
1 2 3 4 5 6 7 8 10 9

*/
