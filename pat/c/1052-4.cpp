#include <stdio.h>

/*
1.��������һ��������
2.����һ�������Ϣ 
*/ 

/*�ܽ� 
1.NULL�����д 
*/
typedef struct Book{ 
	char bookISBN[20];//��� 
	char bookName[20];//���� 
	int price;//������ 
	struct Book *next;//Book�͵�ָ�� 	
}Book,*LinkList;//�����BookΪ�����Ľڵ㣬����*LinkList��Ϊһ��ָ������ 

/*��������Ҫ�õ��ĺ���*/ 
void InitLinkList(LinkList &B); //��ʼ�� 
void inputBanner();//�����ʾ��Ϣ 
void insertInfo(LinkList &B);//������Ϣ 
void travelBook(LinkList B);//���� 


//��ʼ��һ�������� 
void InitLinkList(LinkList &B){
	B = new Book;//�½�һ���ڵ�
	B->next = NULL;//����һ�����½��Ľڵ��ָ������Ϊ�� 
} 

//ʹ�ú�巨�����µ����ݣ��ڵ㣩q --->�ı�����ṹ��ʹ������&�� 
void insertInfo(LinkList &B){ 	
	LinkList p;//ָ��p
	LinkList r;//ָ��r 
	p = B;//ָ��ͬһ���� 
	
	int number,i;
	inputBanner();
	printf("-----------Please input the number of book!----------\n");
	scanf("%d",&number);	
	
	for(i = 0;i< number;i++){
		r = new Book ;//�����½ڵ�r 	
		scanf("%s %s %d",&r->bookISBN,&r->bookName,&r->price);//��ţ���������۸� 						
		r->next = NULL;//��ָ����Ϊ��		 
		p->next = r;
		p = r;		
	}
} 

//�����ʾ��Ϣ 
void inputBanner(){
	printf("Please input book's data!\n");
}

//�������ͼ�� 
void travelBook(LinkList B){
	LinkList p;//�½�ָ��p
	p = B->next;//ָ��p�ĳ�ʼֵΪB 	
	while(p->next != NULL){//����Ϊ�յ�ʱ��ֱ����� 
		printf("%s %s %d\n",p->bookISBN,p->bookName,p->price) ;//����鼮��Ϣ 
		p = p->next;//�����ƽ� 
	} 
}

int main(){
	LinkList B;//�½�һ���ڵ�ָ�� 
	InitLinkList(B);//��ʼ������ڵ㣨ʹ�����ָ��ָ��һ��ʵ�ʵĽڵ㣩
	int number;//����book��
	
	insertInfo(B);//���������Ϣ�������� 
	
	
	//�������������Ϣ
	travelBook(B); 
}
/**��������
4
0001 ��������� 23
0002 ���ݽṹ 34 
0003 ��������ԭ�� 40
0004 ���������ϵͳ 35 
**/

