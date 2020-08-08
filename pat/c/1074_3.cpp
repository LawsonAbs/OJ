#include <cstdio>
#include <stack>
#define maxn 100000
using namespace std; 

struct Node{//����ڵ� 
	int next;//ָ�� 
	int data;//���� 
	int address; //�ڵ��±꼴��Ϊ�ڵ�ĵ�ַ 
};

int main(){
	Node  node[maxn];
	Node temp;
	stack<Node> st;
	int i;
	int startAddr,num,k;//��ַ����������ת�� 
	int flag = 0;//��־ 
	int control = 0;//������� 
	int tempAddr;
		
	scanf("%d %d %d",&startAddr,&num,&k);
	for(i = 0;i < num ;i++){
		scanf("%d",&tempAddr);//������ڵ�ĵ�ַ-->��Ϊ������±� 
		scanf("%d %d",&node[tempAddr].data,&node[tempAddr].next);//������data �� next
		node[tempAddr].address = tempAddr;		
	}
	tempAddr = startAddr;//�ݴ�ֵ 
				
	int count = 0;//ʵ����Ч�ڵ����Ŀ
	while(startAddr != -1){
		startAddr = node[startAddr].next;//��һλ 		
		count++; //���� 
	} 
	startAddr = tempAddr;//�ص�ԭ����ֵ
	 	
	int count1 = 0, count2 = 0;//�ܼ���  ��ת���� 
	while( count - count1 >= k ) {
		while(count2 < k){//�ҽڵ� 
			st.push(node[startAddr]);//ѹ��ջ 			
			startAddr = node[startAddr].next;//�ı�startAddr��ֵ 
			count2++;			
		}
		while(!st.empty()) {//ջ��Ϊ�������
			temp = st.top();
			if(control == 0 && flag == 0 ){
				printf("%05d %d ",temp.address,temp.data);	
			}
			else if(control != 0 && flag == 1){
				printf("%05d\n%05d %d ",temp.address,temp.address,temp.data);	
			} 
			else  {
				printf("%05d\n%05d %d ",temp.address,temp.address,temp.data);	//������� 
			}
			st.pop();//ջ����ջ	
			control++; 
		}
		flag = 1;  		
		count1 += k;//�Լ�K 				
		count2 = 0;//����Ϊ0 
	}
	if(count - count1 < k){
		if(startAddr != -1)	printf("%05d\n",startAddr);
		else	printf("-1\n");//���һ���ڵ� 
	}
			 
	while(startAddr != -1){//���ʣ��Ľڵ�		
		if(node[startAddr].next != -1)	
		printf("%05d %d %05d\n",node[startAddr].address,node[startAddr].data,node[startAddr].next);		
		else {
			printf("%05d %d ",node[startAddr].address,node[startAddr].data);
			printf("-1\n");
		}
		startAddr = node[startAddr].next;
	} 
}
/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00000 6 3
00000 1 11111
11111 2 22222
22222 3 33333
33333 4 -1
77777 5 55555
55555 6 -1

00000 6 2
00000 1 11111
11111 2 -1
22222 3 33333
33333 4 -1
77777 5 55555
55555 6 -1


ע��
1.��Ҫ���ǵ���Ч�Ľڵ㣬����ᵼ����ѭ�������г�ʱ.��������������Ҫ�ȱ����ҳ�������Ч�ڵ����Ŀ 
**/

