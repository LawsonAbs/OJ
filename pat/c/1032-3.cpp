#include <stdio.h> 

typedef struct {
	char data;
	int address;
	int next;
	int flag = 1; 
}Node;

#define maxSize 100001
Node node[maxSize];//�洢�ܵĽڵ� 

int main(){			 
	int start1,start2,number;//��ʼ�ص�1����ʼ�ص�2 
	int i ;
	int record;//��¼-1�Ľڵ����ֵ 
	int count = 0;//��¼β��ָ����ͬ��ָ���м��� 
	scanf("%d %d %d",&start1,&start2,&number);	
	for (i = 0;i<number;i++){
		scanf("%d %c %d",&node[i].address,&node[i].data,&node[i].next);
		if(node[i].next == -1){//�����һָ��Ϊ-1�����¼���� 
			record = i;//��ֵ 
			count ++;
		}
	}
	
	if(count == 2){//��˵��������-1�ڵ� 
		printf("-1");
		return 0;
	}
	
	//��β����ʼ�� 
	while(1){
		count = 0;//����Ϊ0 
		for(i = 0;i< number&&node[i].flag==1 ;i++){
			if(node[i].next == node[record].address){ 				
				node[record].flag == 0;//���ٱȽϴ��� 
				record = i;//��record���i 				
				count++;//��¼�м�����ͬ��β��ָ�� 
				if(count == 2){							
					printf("%05d",node[record].next);//���	
					return 0; 
				}						
			}			
		}		
	} 	
}
/**
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

11111 22222 8
00010 a 12345
00003 g -1
12345 d 00002
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 00002
00001 o 00010


00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
*/
