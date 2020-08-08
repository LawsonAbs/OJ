#include <stdio.h>
#define null NULL
#define maxSize 1003

typedef struct BiTree{
	struct BiTree *lChild,*rChild;//左右子指针
	int data;//数据域 
}BiTree;



int  start[maxSize];//初始数组 
int  result1[maxSize];//先序遍历结果数组 
int  result2[maxSize];//后序遍历结果数组 
int  result3[maxSize];//DRL遍历结果数组 
int  result4[maxSize];//DRL遍历结果数组

int count1 = 0;//申请一个全局变量，用来存储LDR（先序遍历） 
int count2 = 0;//用来存储LRD（后序遍历） 
int count3 = 0;//用来存储DRL（未定义名遍历） 
int count4 = 0;//用来存储RLD（未定义名遍历） 
 
void insertBiTree(BiTree *&bt,int da){	
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

//先序遍历正常二叉树
void preOrderBiTree(BiTree *T){	 
	if(T!=null){
		result1[count1++] = T->data;	
		//printf("%d ",T->data);	
	}
	else	return ;//否则终止递归--->递归结束边界 
	preOrderBiTree(T->lChild);//递归左子树 
	preOrderBiTree(T->rChild);//递归右子树 
}

//后序遍历正常二叉树
void postOrderBiTree(BiTree *T){
	if(T!=null){
		postOrderBiTree(T->lChild);//递归左子树 
		postOrderBiTree(T->rChild);//递归右子树 		
		result2[count2++] = T->data;	
	}	  
	else	return ;//否则终止递归--->递归结束边界
}

//DRL遍历正常二叉树--->得到镜像二叉树数据 
void DRLOrderBiTree(BiTree *T){	 
	if(T!=null){
		result3[count3++] = T->data;
		DRLOrderBiTree(T->rChild);//递归右子树 
		DRLOrderBiTree(T->lChild);//递归左子树 	
	}
	else	return ;//否则终止递归--->递归结束边界 	
}

//RLD遍历镜像二叉树
void RLDOrderBiTree(BiTree *T){	 		
	if(T!=null){
		RLDOrderBiTree(T->rChild);//递归右子树 
		RLDOrderBiTree(T->lChild);//递归左子树 
		result4[count4++] = T->data;	
		//printf("%d ",T->data);	
	}
	else	return ;//否则终止递归--->递归结束边界 	
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
		start[i] = da;//存放到start中		
		insertBiTree(bt,da);//从bt的左子树中插入值到树中 
	} 		
	//先序遍历输出二叉树 
	preOrderBiTree(bt);
	postOrderBiTree(bt);
	DRLOrderBiTree(bt);
	RLDOrderBiTree(bt);
	
	//比较两个数组是否相同
	for(i = 0;i< number;i++){
		if(start[i]!=result1[i]){
			break;
		}
	} 
	if(i == number ){
		printf("YES\n");
		for(int j = 0;j < number ;j++){//输出后序遍历序列 
			if(j < number-1) {
				printf("%d ",result2[j]);
			}
			else
				printf("%d\n",result2[j]);
		}
		return 0; 
	} 
	
	for(i = 0;i< number;i++){
		if(start[i]!=result3[i]){
			break;
		}
	} 
	if(i< number ){
		printf("NO\n");	
	}
	else{
		printf("YES\n");
		for(int j = 0;j < number ;j++){//输出遍历序列 
			if(j < number-1) {
				printf("%d ",result4[j]);
			}
			else
				printf("%d\n",result4[j]);
		}
	}
}
/**
7
8 6 5 7 10 8 11

7
8 10 11 8 6 7 5

7
8 6 8 5 10 9 11

*/
