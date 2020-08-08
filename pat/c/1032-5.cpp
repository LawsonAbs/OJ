#include <stdio.h>

typedef struct{
	char data;
	int address;//地址 
	int next;//指针
	int flag  = 0; 
}Node;

#define maxSize 10000 
Node node[maxSize];
 
int main(){
	int start1,start2,n;
	scanf("%d%d%d",&start1,&start2,&n);
	int i ;
	for(i = 0;i<n;i++){
		scanf("%d %c %d",&node[i].address,&node[i].data,&node[i].next);//输入数据		 
	}
	
	for(i = 0;i<n;i++){
		printf("%d %c %d---\n",node[i].address,node[i].data,node[i].next);//输入数据		 
	}
	int p;
	p =  start1;
	while(p!=-1){
		node[p].flag = 1;
		p = node[p].next;		
	}
	
	p =  start2;
	while(p!=-1){
		p = node[p].next;		
		if(node[p].flag == 1){
			break;
		}
	}
	if(p!=-1){
		printf("%05d\n",p);
	}
	else{
		printf("-1");
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
**/
