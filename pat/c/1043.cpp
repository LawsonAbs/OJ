#include <stdio.h>
#define null NULL
typedef struct BiTree{
	struct BiTree *lChild,*rChild;//左右子指针
	int data;//数据域 
}BiTree;


//插入数据---建立一棵二叉排序树 
//要明白这里的temp(其实就是bt)，为什么使用了&temp，在最后还能够遍历出来，其原因是：
//使用递归遍历，最后temp的初始值没有变化，是在递归的过程中建立起一棵二叉树。 
void insertBiTree_1(BiTree *&temp,int da){
	//如果根节点为空 
	if(temp == NULL){
		temp = new BiTree;//指向一个新节点 
		temp->data = da; 
		temp->lChild = null;
		temp->rChild = null; 
		return;
	}	
	if(da < temp->data) insertBiTree_1(temp->lChild,da);//这个时候（temp->lChild）已经建立了指向关系 
	else insertBiTree_1(temp->rChild,da);
} 

/**
//插入数据-->建立一棵二叉树
//如果你硬要使用这种方式来创建一棵二叉树，那么你需要一个头结点 
void insertBiTree_2(BiTree *&temp,int da){	
	//BiTree *temp;
	//temp = bt;
		
	//先找到合适的位置--->如果说temp不为null 
	//这里是一个while(temp!=null)循环的原因：可能是在左子树，也可能是右子树 
	while(temp!=NULL){	
		if(temp->data < da ) {//需要循环测试是否为null
			temp = temp->rChild;
		}
		else if( temp != null && temp->data > da ){//需要循环测试是否为null 
			temp = temp->lChild;
		}		
	}
	if(temp == null){
		temp = new BiTree; 
		temp->data = da;//插入数据
		temp->lChild = null;
		temp->rChild = null;	
	}	
} 
**/ 


//先序遍历二叉树
void preOrderBiTree(BiTree *T){
	if(T!=null){
		printf("%d ",T->data);	
	}
	else	return ;//否则终止递归--->递归结束边界 
	preOrderBiTree(T->lChild);//递归左子树 
	preOrderBiTree(T->rChild);//递归右子树 
}

void insertBiTree_2(BiTree *&bt,int da){	
	//先判断树是否为空-->如果为空，则建树，直接返回 
	if(bt==null){	
		bt = new BiTree;//因为在main函数中，bt是null，所以需要先让其指向一个节点，才能在该节点上赋值操作！ 
		bt->data = da;
		bt->lChild = null;
		bt->rChild = null;
		return ;
	} 	
	BiTree *pre;//探索指针
	pre = bt;
	
	BiTree *follow;//跟随指针
	follow = bt;
			
	int flag = -1; 
	while(pre!=NULL){	
		if(pre->data <= da ) {//需要循环测试是否为null
			follow = pre;//暂存值 
			pre = pre->rChild; //变化的是follow!!
			flag = 1;
		}
		else if( pre != null && pre->data > da ){//需要循环测试是否为null 
			follow = pre;//暂存值 
			pre = pre->lChild;//变化的是follow!!
			flag = -1;
		}		
	}
	//注意！！如果说是跟随指针发现孩子为null,则添加节点，且将当前指针（pre）的孩子设成temp 
	if(pre == null){
		//下面是新建一个BiTree节点，并将其修改成标志的二叉树节点（左右子树均赋为空） 
		BiTree *temp;	
		temp = new BiTree; 
		temp->data = da;//插入数据
		temp->lChild = null;
		temp->rChild = null;
		
		if(flag == 1){
			follow->rChild = temp;	
			flag = -1; 
		}
		else if(flag == -1){
			follow->lChild = temp;
			flag = -1;
		}
	}	
} 

int main(){ 
	BiTree *bt;//新建一个BiTree型头指针 
	bt = null;//初始化为null 
	
	int number;//表示节点数
	scanf("%d",&number);//输入number
	int i;
	int da;
	for(i = 0;i< number;i++){
		scanf("%d",&da);		
		insertBiTree_2(bt,da);//从bt的左子树中插入值到树中 
	} 	
	//遍历输出二叉树 
	preOrderBiTree(bt);
}
/**
7
8 6 5 7 10 8 11

7
8 6 5 7 10 9 11
*/
