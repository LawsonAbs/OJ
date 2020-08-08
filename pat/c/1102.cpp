#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
#define maxSize 1000 

//ʹ�þ�̬������ 
typedef struct{
	int data; //���� 
	int lChild,rChild;//���Һ��� 
}BiTree;

//������ȼ۵�д�� 
//typedef struct{
//	int data[3][maxSize];//lChild,rChlid,data 
//}BiNode;


BiTree bt[maxSize];//�½�һ������ 
int number;//������ 
int index;//���ڵ������±� 
int result[maxSize];
int count1;

//��α��������� 
void bfsBiTree(){
	queue<int> que;//�½�һ������ 
	que.push(bt[index].data);//���ý����Ϊ���ڵ㳢�����
	int i = index;//��̬�ı���±�ֵ 
	int count = 1;
	while(!que.empty()){//�����зǿ�ʱ 			
		if(bt[i].lChild!=-1)	que.push(bt[i].lChild);//�������ǿգ���� 
		if(bt[i].rChild!=-1)	que.push(bt[i].rChild);//�������ǿգ���� 		 		
		if(count  < number)		printf("%d ",que.front());//���ͷԪ�� 				
		else {
			printf("%d",que.front());//���ͷԪ�� 				
		}
		count++;
		que.pop();//����Ԫ�س���
		i = que.front();//��ȡ�������	 			
	}
	printf("\n"); 
} 

//���������� 
void inOrder(int index) {
	if(index == -1)	return ;
	
//count++;//ÿ�����������ͼ�һ 
	inOrder(bt[index].lChild);		
	result[count1++] = bt[index].data;		
	inOrder(bt[index].rChild);
}


//�ҳ����ڵ����Ķ�
void foundRoot(){
	queue<int> q;//�½�һ������	 
	int i;		
	for(i = 0;i < number;i++ ){
		int j ;//���ܸı�forѭ���е�iֵ��ǧ��Ҫע�⣬��forѭ���Ļ���������i�Ļ�����ôһ����Ҫʹ�ñ�ı�����Ϊ���������� 
		j = i;
		q.push(bt[j].data);//���ý����Ϊ���ڵ㳢�����		
		int count = 1;//��̬���ã���������) 
		
		while(!q.empty() && count < number){//�����зǿ�ʱ 			
			if(bt[j].lChild!=-1)	q.push(bt[j].lChild);//�������ǿգ���� 
			if(bt[j].rChild!=-1)	q.push(bt[j].rChild);//�������ǿգ���� 
			q.pop();//����Ԫ�س���
			j = q.front();//�õ�����Ԫ�� 			
			count++;
		}
		if(count >= number){
			index = i; 
			break;//����ѭ�� 
		}
	}	
} 


int main(){
	scanf("%d",&number);//����number
	getchar();//���ջ��з� 
	int i;
	char a,b;
	for(i = 0;i < number;i++){
		scanf("%c %c",&a,&b);//���������ַ�a,b
		getchar(); 
		bt[i].data = i;//������ֵ 
		if(a!='-')	bt[i].rChild = a-'0'; 
		else 		bt[i].rChild = -1;//û�������� 
		if(b!='-')	bt[i].lChild = b-'0'; 
		else 		bt[i].lChild = -1;//û�������� 
	} 
	//��֤���->����
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
