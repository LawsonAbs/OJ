#include <stdio.h>

typedef struct {
	int address;//��ʼ�ڵ� 
	char data;//���� 
	int next;//��һָ�� 
}Node;

Node n[100002];
Node n1[100002],n2[100002];
	

int main(){
	int start1,start2,number;//��ʼ�ص�1����ʼ�ص�2 
	int i ;
	scanf("%d %d %d",&start1,&start2,&number);
	
	for (i = 0;i<number;i++){
		scanf("%d %c %d",&n[i].address,&n[i].data,&n[i].next);
	}
	
	//���������ݷֳ����� 
	for(i = 0;i<number;i++){
		if(n[i].address == start1){
			n1[0] = n[i];	
		}
		if(n[i].address == start2){
			n2[0] = n[i];
		}		
	} 
	
	int count1 = 0,count2 = 0;
	int j = 0;
	while(n1[count1].next!=-1 || n2[count2].next!=-1 ){
		for(j = 0;j<number;j++){
			if(n[j].address == n1[count1].next){
				count1++;
				n1[count1] = n[j];				
			}
			
			if(n[j].address == n2[count2].next){
				count2++;
				n2[count2] = n[j];				
			}
		}		
	}

//2.��β����ʼ�������ҵ���һ������ͬ�Ľ��
	for(i = count1;i>=0;i--){
		for(j = count2;j>= 0;j--){
			if(n1[i].address == n2[j].address){
				i--;				
			}
			else if(n1[i].address != n2[j].address){
				//printf("%d %d\n",n1[i].address,n2[j].address); 
				if(n1[i+1].address == 0){
					printf("-1");
					return 0;
				}
				else{
					printf("%d",n1[i+1].address);//ֱ����� 
					return 0;					
				}
			}
		}
	} 
}
/*
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
*/
