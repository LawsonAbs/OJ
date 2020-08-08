#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;

#define null NULL 
#define maxSize 100

typedef struct BiTree{
	struct BiTree *lChild,*rChild;//����ָ��
	int data;
}BiTree;


int number;
int preOrder[maxSize];//����
int inOrder[maxSize];//����

//��������������к�����������еõ�һ������������ 
//��������
//���������һ��������ͷ���
 
BiTree* foundData(int preLeft,int preRight,int inLeft,int inRight){
	if(preRight < preLeft){
		return null;
	}
	BiTree *T = new BiTree;
	T->data = preOrder[preLeft];//�������ڵ�
	int i ;
	int rootIndex;
	for(i = inLeft;i <=inRight;i++ ){
		if(inOrder[i] == preOrder[preLeft]){
			rootIndex = i;
			break;//����ѭ�� 
		}
	}	
	int leftNodeNumber ;
	leftNodeNumber = rootIndex - inLeft;//�ҳ��������ĸ��� 
	T->lChild = foundData(preLeft+1,preLeft + leftNodeNumber ,inLeft,rootIndex - 1);
	T->rChild = foundData(preLeft + leftNodeNumber + 1 ,preRight,rootIndex + 1,inRight);
	return T;//������ 
}

int m = 0;
//��������������
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
	char str[maxSize];//�ַ��� 
	int count1 = 0,count2 = 0;//�±� 
	stack<int> sta;
	for(i = 0;i< 2*number;i++){
		gets(str);//�����ַ��� 
		//%s��������ո� 
		int length = strlen(str);//����ַ����ĳ��� 
		int temp = 0;//������� 
		
		int t = 5;//�ӵ�5λ��ʼ�� 
		if(strcmp(str,"Pop") == 0){//���Ϊpop  
			inOrder[count2++] = sta.top(); 
			sta.pop();//��ջ 
		}
		else{
			while(t<length){
				temp = temp*10 + str[t] -'0' ; 			 				
				t++;
			}
			sta.push(temp);//��ջ 
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

/*�ܽ�
1.����Ҫ��ʵ�������ڣ�
�����������ַ���ʱ������Ҫ����ַ���"Push 1"�м��Ǵ��пո�ģ� 
*/
