/*ע 
1.���㷨���н����ȷ������ʱ�临�Ӷȹ��� 
*/
#include <cstdio>
#include <stack>
#define maxn 100000
using namespace std; 

struct Node{//����ڵ� 
	int next;//ָ�� 
	int address; //��ַ
	int data;//���� 
	int value;//��Чֵ 
};

int main(){
	Node  node[maxn];
	stack<Node> st;
	Node temp;//�ݴ���Ϣ 
	int i;
	int addr,num,k;//��ַ����������ת�� 
	int flag = 0;//��־ 
	int control = 0;//������� 
	int tempAddr;
		
	scanf("%d %d %d",&addr,&num,&k);
	for(i = 0;i < num ;i++){
		scanf("%d %d %d",&node[i].address,&node[i].data,&node[i].next);		
		node[i].value = 0; 
	}
	tempAddr = addr;
		
	int count = 0;//�ҳ�ʵ����Ч�Ľڵ���Ŀ
	i = 0;//����Ϊ0 
	while(addr != -1){
		if(node[i].address == addr){
			node[i].value = 1; 
			addr = node[i].next;
			count++;
		}
		i++;
		i = i % num;
	} 
	addr = tempAddr;//�ص�ԭ����ֵ
	 
//	printf("------\n");	
	int count1 = 0, count2 = 0;//�ܼ���  ��ת���� 
	while( count - count1 >= k ) {
		while(count2 < k){
			for(i = 0;i< num && count2 < k  ; i++){
				if(node[i].address == addr && node[i].value == 1){
					addr = node[i].next;//�ı�addr��ֵ 
					st.push(node[i]);//ѹ��ջ 			
					count2++;//�ҵ�һ���ڵ㣬��һ
					node[i].value = 0;
					break;//����ѭ�� 
				}
			}
			if(count2==0){//�������һ����Ȼû���ҵ�һ����ַ 		
				printf(" -1\n");
				return 0;//ֱ�ӷ��� 
			} 
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
		if(count - count1 < k){
			if(addr != -1)	printf("%05d\n",addr);//���ǡ�������һ�� 
			else	printf("-1\n");
		}	
		count2 = 0;//����Ϊ0 
	}
	
	//���ʣ��Ľڵ� 
	int remain = count - count1;
	while(remain--){
		for(i = 0;i< num ;i++){
			if(node[i].address == addr){
				temp = node[i];
				//printf("remain = %d\n",remain);
				if(remain!=0)	printf("%05d %d %05d\n",temp.address,temp.data,temp.next);
				else {
					printf("%05d %d ",temp.address,temp.data);
					printf("-1\n");
				}
				addr = node[i].next;
				break;
			}			
		}
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

