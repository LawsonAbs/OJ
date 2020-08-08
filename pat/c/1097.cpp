#include <stdio.h>

typedef struct{
	int address; 
	int data;
	int next;//ָ�� 
	int flag = 1;//��ʶ 
}Node;

#define maxSize 100001 
Node node[maxSize];
Node n1[maxSize];//�洢ɾ���Ľڵ� 
Node n2[maxSize];//�洢�����Ľڵ�
 
int array[maxSize];//�����洢�Ƚ�����---->������ظ�����ɾ��
 
int main(){	
	int startLocation, n;
	scanf("%d%d",&startLocation,&n);
	int i ;
	int address,data,next;
	
	for(i = 0;i< maxSize ;i++){
		array[i] = 0;//ȫ����0 
	} 
	
	for(i = 0;i<n;i++){
		scanf("%d %d %d",&address,&data,&next);
		node[address].data = data;
		node[address].next = next;		
	}
	
	//����n���ڵ� 
	int count = 0;	
	for(i = startLocation;i!=-1;i=node[i].next){		
		if(node[i].data < 0){//����ڵ�ֵС��0 
			if(array[((-1)*node[i].data)]==1){//������ֵ�Ѿ��������У����ó��� 
				node[i].flag = 0; 				
			}
			else
			{
				array[((-1)*node[i].data)]++;//����������Ŀ��1
			}			
		}
		else{//����ڵ�ֵ����0 
			if(array[node[i].data]==1){//������ֵ�Ѿ��������У����ó��� 				
				node[i].flag = 0; 
			}
			else
			{
				array[node[i].data]++;//����������Ŀ��1
			}
		}	
	}
	
	//printf("-----------------------------------\n");
	int p = startLocation;
	int count1 = 0,count2 = 0;
	while(p!=-1){
		if(node[p].flag == 1){
			n1[count1] = node[p];
			n1[count1].address = p; 			
			count1 ++;
		}		
		p = node[p].next;
	}
	n1[count1].next = -1;//���-1 
	
	p = startLocation;
	
	while(p!=-1){
		if(node[p].flag == 0){
			n2[count2] = node[p];
			n2[count2].address = p; 			
			count2 ++;
		}		
		p = node[p].next;
	}
	n2[count2].next = -1;//���-1	
	
	
	//���n1 
	i = 0;
	while(i<count1){
		 if(i!=count1-1)
		 printf("%05d %d %05d\n",n1[i].address,n1[i].data,n1[i+1].address);
		 else
		 printf("%05d %d -1\n",n1[i].address,n1[i].data);
		 i++;
	}
	
	//���n2 
	i = 0;
	while(i<count2){
		if(i!=count2-1)
		printf("%05d %d %05d\n",n2[i].address,n2[i].data,n2[i+1].address);
		else
		printf("%05d %d -1\n",n2[i].address,n2[i].data);
		i++;
	}
	
}
/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
*/
