#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;

#define null NULL 
#define maxSize 100

typedef struct BiTree{
	struct BiTree *lChild,*rChild;//左右指针
	int data;
}BiTree;


int number;
int preOrder[maxSize];//先序
int inOrder[maxSize];//中序

//根据先序遍历序列和中序遍历序列得到一棵完整二叉树 
//建二叉树
//先序遍历第一个结点就是头结点
 
BiTree* foundData(int preLeft,int preRight,int inLeft,int inRight){
	if(preRight < preLeft){
		return null;
	}
	BiTree *T = new BiTree;
	T->data = preOrder[preLeft];//建立根节点
	int i ;
	int rootIndex;
	for(i = inLeft;i <=inRight;i++ ){
		if(inOrder[i] == preOrder[preLeft]){
			rootIndex = i;
			break;//跳出循环 
		}
	}	
	int leftNodeNumber ;
	leftNodeNumber = rootIndex - inLeft;//找出左子树的个数 
	T->lChild = foundData(preLeft+1,preLeft + leftNodeNumber ,inLeft,rootIndex - 1);
	T->rChild = foundData(preLeft + leftNodeNumber + 1 ,preRight,rootIndex + 1,inRight);
	return T;//返回树 
}

int m = 0;
//输出后序遍历序列
void postTraverseBiTree(BiTree *T) {
	if(T == null)	{
		return ;
	}
	postTraverseBiTree(T->lChild); 
	postTraverseBiTree(T->rChild);
	
	if(m < number-1)	printf("%d ",T->data);
	else printf("%d",T->data); 
	m++;	
}

int main() {
	
	scanf("%d",&number);
	getchar();
	int i;
	char str[maxSize];//字符串 
	int count1 = 0,count2 = 0;//下标 
	stack<int> sta;
	for(i = 0;i< 2*number;i++){
		gets(str);//输入字符串 
		//%s不能输入空格 
		int length = strlen(str);//求出字符串的长度 
		int temp = 0;//求出数字 
		
		int t = 5;//从第5位开始求 
		if(strcmp(str,"Pop") == 0){//如果为pop  
			inOrder[count2++] = sta.top(); 
			sta.pop();//出栈 
		}
		else{
			while(t<length){
				temp = temp*10 + str[t] -'0' ; 			 				
				t++;
			}
			sta.push(temp);//入栈 
			preOrder[count1++] = temp;				
		} 				
	}	
//	for(i = 0;i< number;i++){
//		printf("%d ",preOrder[i]);
//	} 
//	printf("\n");
//	for(i = 0;i< number;i++){
//		printf("%d ",inOrder[i]);
//	}
//	printf("\n");
	
	BiTree *T = foundData(0,number-1,0,number-1);
	postTraverseBiTree(T);
}
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
*/

/*总结
1.基础要扎实。体现在：
在我们输入字符串时，我们要清楚字符串"Push 1"中间是带有空格的， 
*/
