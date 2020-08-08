#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1010;
int father[N];//存放父亲节点
int isRoot[N] = {0};//记录每个节点是否作为某个集合的根节点
int course[N] = {0};//初始化为0 
int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
} 

//合并a 和 b所在的集合 
void Union(int a ,int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	} 
}

//初始化father[i]为i,且flag[i]为false 
void init(int n){
	for(int i = 1;i <= n;i++){
		father[i] = i;//初始时每个节点的父节点都是自己 
		isRoot[i] = false;
	}
}

bool cmp(int a,int b){
	return a> b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i = 1;i<= n;i++){
		scanf("%d:",&k);
		for(int j = 0;j<k;j++){
			scanf("%d",&h);
			if(course[h] == 0){
				course[h] = i;
			}
			Union(i,findFather(course[h]));//合并 
		}
	}
	for(int i = 1;i <= n;i++){
		isRoot[findFather(i)]++;//i的根节点是findFather(i)，人数加1 
	} 
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(isRoot[i] != 0){
			ans++;//只统计isRoot[i]不为0 
		}
	} 
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i = 1;i<= ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans)	printf(" ");
	}
	return 0;
}

/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
**/

