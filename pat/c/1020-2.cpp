#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#define maxSize 100
#define null NULL


typedef struct BiTree{
	struct BiTree *lChild,*rChild;//左右子树指针 
	int data;//数据域 
};


int number;
int postOrder[maxSize];
int inOrder[maxSize];

//从二叉树中找出结点并建树
//注意返回的是二叉树的头结点指针 
BiTree* foundData(int postLeft,int postRight,int inLeft,int inRight){

	if(postRight < postLeft){
		return null;
	} 
	int i ;
	int root;//根节点的值 
	int rootIndex;//根节点在中序数组中的下标 
	
	root = postOrder[postRight];//找到root 
	BiTree *T;
	T = new BiTree;//指向具体的结点 
	
	T->data = root;  
	
	//注意细节！for循环边界取值 
	for(i = inLeft;i <= inRight;i++){
		if(inOrder[i] == postOrder[postRight]){
			rootIndex = i;//记录下标 
			break;
		}	
	}
	int leftNodeNumber ;//表示左子树包含的结点个数 
	leftNodeNumber =  rootIndex - inLeft;//注意是减去inLeft,而非postLeft 
	
	//代码的关键所在，确定范围值得选取 
	/*
	1.对于这种问题，我们应该首先抽取出一般项，然后对其一般项进行操作
	2.检验方法：试用多个特殊的项来对总结的表达式进行检验，判断其正确性 
	*/ 
	T->lChild = foundData(postLeft, postLeft + leftNodeNumber -1,inLeft,rootIndex-1);//建左子树 
	T->rChild = foundData(postLeft + leftNodeNumber, postRight - 1,rootIndex + 1,inRight);//建右子树 
	return T;
}

//前序遍历 
void preTraverseBiTree(BiTree *T){
	if(T == null){
		return ;
	}
	printf("%d ",T->data);
	preTraverseBiTree(T->lChild);
	preTraverseBiTree(T->rChild);	
}

//使用层次遍历（BFS） 
void BfsBiTree(BiTree *T){
	int count = 0;//输出计数 
	queue <BiTree*> q;//使用队列存储指针结点 
	q.push(T);//首先将根节点入队
	while(!q.empty()){//当队列非空时 			
		BiTree* now = q.front();//得到队首 
		q.pop(); //将根结点出队
		count ++;
		if(count < number )		printf("%d ",now->data); //输出 
		else printf("%d",now->data); 
		if(now->lChild!=null)		q.push(now->lChild);//左子树入队 --->注意这里是now，而非是T!! 
		if(now->rChild!=null)     q.push(now->rChild);//右子树入队 
	} 
}

int main(){	
	scanf("%d",&number);
	int i;
	for(i = 0;i< number;i++){
		scanf("%d",&postOrder[i]);
	}	
	//输入inOrder 
	for(i = 0;i< number;i++){
		scanf("%d",&inOrder[i]);
	}	
	BiTree *T;
	T = foundData(0,number-1,0,number-1); //返回作为根节点
	//preTraverseBiTree(T);//前序遍历二叉树
	BfsBiTree(T);
}
/*
4
2 3 1 4
1 2 3 4
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
**/ 
