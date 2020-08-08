#include<cstdio>
#include<cstring> 
#include<iostream>

using namespace std;

struct node{
	char data[15];//根节点的值 ，是一个符号 
	int leftChi,rightChi;//左右孩子的节点 
};

int N;//二叉树的节点数 
int array[22];//用于求出根节点 
node n[22];	

//中序遍历 得到中缀表达式 
void ldr(int root){
	if( strcmp(n[root].data,"+") == 0|| 
		strcmp(n[root].data,"-") == 0||
		strcmp(n[root].data,"*") == 0||
		strcmp(n[root].data,"/") == 0||
		strcmp(n[root].data,"%") == 0||
		strcmp(n[root].data,"&") == 0) 		
		cout << "(";
	if(n[root].leftChi!=-1){//如果存在左孩子 
		ldr(n[root].leftChi);		
	}
	cout << n[root].data ;
	if(n[root].rightChi!=-1){
		ldr(n[root].rightChi);		
	}
	
	if( strcmp(n[root].data,"+") == 0|| 
		strcmp(n[root].data,"-") == 0||
		strcmp(n[root].data,"*") == 0||
		strcmp(n[root].data,"/") == 0||
		strcmp(n[root].data,"%") == 0||
		strcmp(n[root].data,"&") == 0)
		cout << ")"; 
} 

//找根节点 
int lookRoot(){
	int i ;
	for(i = 1;i<= N;i++){
		if(array[i] == 0) break;//说明是根节点 
	}	
	return i;
}

int main(){	
	scanf("%d",&N);
	int i ;		
	memset(array,0,sizeof(array));//初始化为0 
	for(i = 1;i <= N;i++){	
		getchar();
		scanf("%s %d %d",&n[i].data, &n[i].leftChi, &n[i].rightChi);
		if(n[i].leftChi != -1)	array[n[i].leftChi] = 1; 
		if(n[i].rightChi != -1)	array[n[i].rightChi] = 1;
	} 
	int root;
	root = lookRoot();
	//cout<<"root = "<<root<<endl;
	int leftRoot ,rightRoot;
	leftRoot = n[root].leftChi;
	rightRoot = n[root].rightChi;
	
	//需要在这里判断一下leftRoot 和 rightRoot 是否等于-1。否则会报段错误 
	//但是不理解的是：怎么会有这种输入。 竟然存在leftRoot 和 RightRoot =-1的情况 
	//leftRoot = -1的这种情况是存在的。比如说只有一个表达式： -1
	//rightRoot = -1 的这种情况可能不是存在的。 
	if(leftRoot != -1) ldr(leftRoot);
	cout<<n[root].data;
	if(rightRoot !=-1) ldr(rightRoot);
}
/*
3
- 3 2
a -1 -1
b -1 -1

1
a -1 -1

3
- 2 3
a -1 -1
b -1 -1

8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1
*/ 
