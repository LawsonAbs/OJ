#include <stdio.h>

/*
1.真正定义一个单链表
2.描述一本书的信息 
*/ 

/*总结 
1.NULL必须大写 
*/
typedef struct Book{ 
	char bookISBN[20];//书号 
	char bookName[20];//书名 
	int price;//数据项 
	struct Book *next;//Book型的指针 	
}Book,*LinkList;//这里的Book为单纯的节点，但是*LinkList则为一个指针类型 

/*声明所需要用到的函数*/ 
void InitLinkList(LinkList &B); //初始化 
void inputBanner();//输出提示信息 
void insertInfo(LinkList &B);//插入信息 
void travelBook(LinkList B);//遍历 


//初始化一个单链表 
void InitLinkList(LinkList &B){
	B = new Book;//新建一个节点
	B->next = NULL;//将上一步中新建的节点的指针域置为空 
} 

//使用后插法插入新的数据（节点）q --->改变链表结构（使用引用&） 
void insertInfo(LinkList &B){ 	
	LinkList p;//指针p
	LinkList r;//指针r 
	p = B;//指向同一链表 
	
	int number,i;
	inputBanner();
	printf("-----------Please input the number of book!----------\n");
	scanf("%d",&number);	
	
	for(i = 0;i< number;i++){
		r = new Book ;//生成新节点r 	
		scanf("%s %s %d",&r->bookISBN,&r->bookName,&r->price);//书号，书名，书价格 						
		r->next = NULL;//其指针域为空		 
		p->next = r;
		p = r;		
	}
} 

//输出提示信息 
void inputBanner(){
	printf("Please input book's data!\n");
}

//遍历这个图书 
void travelBook(LinkList B){
	LinkList p;//新建指针p
	p = B->next;//指针p的初始值为B 	
	while(p->next != NULL){//当不为空的时候，直接输出 
		printf("%s %s %d\n",p->bookISBN,p->bookName,p->price) ;//输出书籍信息 
		p = p->next;//往后推进 
	} 
}

int main(){
	LinkList B;//新建一个节点指针 
	InitLinkList(B);//初始化这个节点（使得这个指针指向一个实际的节点）
	int number;//输入book数
	
	insertInfo(B);//插入具体信息到链表中 
	
	
	//遍历输出链表信息
	travelBook(B); 
}
/**测试数据
4
0001 计算机网络 23
0002 数据结构 34 
0003 计算机组成原理 40
0004 计算机操作系统 35 
**/

