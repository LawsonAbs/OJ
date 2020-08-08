#include <cstdio>
#include <set>
using namespace std;

const int N = 51;
set<int> st[N];//N个集合

void compare(int x,int y){//比较set[x]与set[y] 
	int totalNum = st[y].size(),sameNum = 0;
	
	//遍历集合st[x]
	for(set<int>::iterator it = st[x].begin();it !=st[x].end();it++){
		if(st[y].find(*it) != st[y].end())
			sameNum++;
		else
			totalNum++;//在st[y]中不能找到该元素 			
	} 
	printf("%.1f%\n",sameNum * 100.0 / totalNum) ;//输出比例 
} 

int main(){
	int n,k,q,v,st1,st2;
	
	scanf("%d",&n);//集合个数 
	for(int i = 1;i <= n;i++){
		scanf("%d",&k);//集合元素中的个数 
		for(int j = 0;j<k;j++){
			scanf("%d",&v);
			st[i].insert(v); //将元素插入到集合中	
		}		
	} 
	
	//q个查询 
	scanf("%d",&q);
	for(int i = 0;i<q;i++){
		scanf("%d%d",&st1,&st2);
		compare(st1,st2);
	}
	return 0;
} 
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/ 
