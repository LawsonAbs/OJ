#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

struct edge{
	int left,right;//一条边的左右两个顶点 
	int isVisit = 0;//表示是否访问过 
};
 
edge e[10005];  

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int i,j,x;
	int left,right; 
	for(i = 0;i< M;i++){
		scanf("%d%d",&e[i].left,&e[i].right);	
	}
	int K;//待查询数 
	scanf("%d",&K);
	int verNum;//表示待查询的顶点集合数 
	set<int> verSet; //待查询顶点集 
	int vertex;//每个顶点 
	for(i = 0;i< K;i++){
		scanf("%d",&verNum);	
		for(j = 0;j< verNum;j++){
			scanf("%d",&vertex);//输入待查询的每个vertex
			verSet.insert(vertex);//插入到set中 
		}

//		for(set<int>::iterator it= verSet.begin();it!=verSet.end();it++){
//			cout<<*it<<" ";
//		}						
		//开始进行处理
		for( x= 0; x<M;x++ ){
			if(verSet.find(e[x].left)==verSet.end() 
			&& verSet.find(e[x].right)==verSet.end() ){				
				break;
			}
		}
		
		if(x == M) cout <<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		verSet.clear();//clear set		
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
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2

*/
