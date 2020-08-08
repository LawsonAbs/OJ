#include <cstdio>
#define maxn 1000

int n,m;//总人数 好朋友组数
int father[maxn];

//初始化操作 
void init(){
	int i;
	for(i = 0;i <= n; i++){
		father[i] = i;//初始化---每个节点的父节点为该节点本身 
	}
}

int findFather(int x){
	//下面这个是循环找出最顶层的父亲 
	while(x != father[x]){
		x = father[x];
	}
	return x;
}

void Union(int a,int b){
	int faA = findFather(a);
	int faB = findFather(b);	
	//是不是同一个祖先，如果是，则将faA 的祖先设置为B 
	if(faA != faB){		
		father[faA] = faB;
	}
} 

int main(){		
	int i,j;
	scanf("%d %d",&n,&m); 
	init(); 
	int a,b;//a与b是朋友关系 
	for(i = 0;i < m;i++){
		scanf("%d %d",&a,&b);
		Union(a,b);
	} 
	
	int group = n; 
	for(i = 1;i<= n;i++){
		printf("father[%d] = %d\n",i,father[i]);
		if(father[i]!=i)
			group --;
	}
	printf("\ngroup = %d",group);	
}
/*
3 2
1 3 
3 4

5 3
1 4
3 5
4 2 


5 3
4 2
1 4
3 5


6 4
1 4
3 5
4 2
5 6
*/
