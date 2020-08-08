#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<iostream>
#define maxn 10005

using namespace std;

int edge[maxn][maxn];//用于存储边的信息
 
int main(){
	int N,M,K;
	scanf("%d%d",&N,&M);	
	int i,j,k;
	int ver1,ver2; 
	for(i = 0;i<M;i++){
		scanf("%d%d",&ver1,&ver2);		
		edge[ver1][ver2] = 1;
		edge[ver2][ver1] = 1;
	}
	
	scanf("%d",&K);	
	set<int> color;
	int flag ;
	map<int,set<int> > query;//查询点的色彩信息 
	int temp;
	set<int> ::iterator bak; 
	set<int> tempSet;
	for(i = 0 ;i< K;i++){
		//初始化信息 
		flag = 0;
		color.clear();	
		
		query.clear();
		
		//输入各个顶点的 染色 情况 
		for(j = 0;j< N;j++){
			scanf("%d",&temp);			
			query[temp].insert(j);//将顶点j插入到query[temp] 中 
			color.insert(temp);
		}
		
		for(map<int,set<int> >::iterator it = query.begin();it!= query.end();it++){
			//cout << it->first<<"\n";			
			tempSet  = it->second;//是一个set 
			for(set<int> ::iterator first = tempSet.begin();first!=tempSet.end();first++)
			{
				bak = first;
				ver1 = *first;
				bak++;
				//cout <<"ver1 = "<<ver1<<"\n";
				for(set<int>::iterator two = bak; two!=tempSet.end();two++){
					ver2 = *two;
					if(edge[ver1][ver2] == 1){
						flag = 1;
						break;
					} 
				}
				if(flag == 1){
					cout << "No" << "\n";
					break;
				}				
			}
			if(flag == 1) break;
		}
		
		if(flag == 0){			
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
1
8 1 0 1 4 1 0 5 3 0

*/
