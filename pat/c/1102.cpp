#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define maxSize 1000 

//使用静态二叉树 
typedef struct{
	int data; //数据 
	int lChild,rChild;//左右孩子 
}BiTree;

//与上面等价的写法 
//typedef struct{
//	int data[3][maxSize];//lChild,rChlid,data 
//}BiNode;


BiTree bt[maxSize];//新建一个数组 
int number;//数据数 
int index;//根节点所在下标 
int result[maxSize];
int count1;

//层次遍历二叉树 
void bfsBiTree(){
	queue<int> que;//新建一个队列 
	que.push(bt[index].data);//将该结点作为根节点尝试入队
	int i = index;//动态改变的下标值 
	int count = 1;
	while(!que.empty()){//当队列非空时 			
		if(bt[i].lChild!=-1)	que.push(bt[i].lChild);//左子树非空，入队 
		if(bt[i].rChild!=-1)	que.push(bt[i].rChild);//右子树非空，入队 		 		
		if(count  < number)		printf("%d ",que.front());//输出头元素 				
		else {
			printf("%d",que.front());//输出头元素 				
		}
		count++;
		que.pop();//队首元素出队
		i = que.front();//获取这个队首	 			
	}
	printf("\n"); 
} 

//中序遍历输出 
void inOrder(int index) {
	if(index == -1)	return ;
	
//count++;//每进入左子树就加一 
	inOrder(bt[index].lChild);		
	result[count1++] = bt[index].data;		
	inOrder(bt[index].rChild);
}


//找出根节点在哪儿
void foundRoot(){
	queue<int> q;//新建一个队列	 
	int i;		
	for(i = 0;i < number;i++ ){
		int j ;//不能改变for循环中的i值【千万要注意，当for循环的基本变量是i的话，那么一定需要使用别的变量作为基本变量】 
		j = i;
		q.push(bt[j].data);//将该结点作为根节点尝试入队		
		int count = 1;//动态重置（计数变量) 
		
		while(!q.empty() && count < number){//当队列非空时 			
			if(bt[j].lChild!=-1)	q.push(bt[j].lChild);//左子树非空，入队 
			if(bt[j].rChild!=-1)	q.push(bt[j].rChild);//右子树非空，入队 
			q.pop();//队首元素出队
			j = q.front();//拿到队首元素 			
			count++;
		}
		if(count >= number){
			index = i; 
			break;//跳出循环 
		}
	}	
} 


int main(){
	scanf("%d",&number);//输入number
	getchar();//吸收换行符 
	int i;
	char a,b;
	for(i = 0;i < number;i++){
		scanf("%c %c",&a,&b);//输入两个字符a,b
		getchar(); 
		bt[i].data = i;//数据域赋值 
		if(a!='-')	bt[i].rChild = a-'0'; 
		else 		bt[i].rChild = -1;//没有左子树 
		if(b!='-')	bt[i].lChild = b-'0'; 
		else 		bt[i].lChild = -1;//没有右子树 
	} 
	//验证输出->遍历
//	 for(i = 0;i< number;i++){
//	 	printf("%d %d %d\n",bt[i].data,bt[i].lChild,bt[i].rChild); 
//	 } 
	foundRoot();
	//printf("index = %d\n",index);
	bfsBiTree();
	inOrder(index);
	for(int j = 0;j<count1;j++){
		if(j<count1 -1 ) printf("%d ",result[j]);
		else printf("%d",result[j]);
	}
} 
/**
2
- 1
- -
1
- - 

8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

4
- 1
- 2
- 3
- -


4
1 -
2 -
3 -
4 -
- -
*/
