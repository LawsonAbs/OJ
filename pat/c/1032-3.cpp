#include <stdio.h> 

typedef struct {
	char data;
	int address;
	int next;
	int flag = 1; 
}Node;

#define maxSize 100001
Node node[maxSize];//存储总的节点 

int main(){			 
	int start1,start2,number;//起始地点1，起始地点2 
	int i ;
	int record;//记录-1的节点序号值 
	int count = 0;//记录尾部指针相同的指针有几个 
	scanf("%d %d %d",&start1,&start2,&number);	
	for (i = 0;i<number;i++){
		scanf("%d %c %d",&node[i].address,&node[i].data,&node[i].next);
		if(node[i].next == -1){//如果下一指针为-1，则记录下来 
			record = i;//赋值 
			count ++;
		}
	}
	
	if(count == 2){//则说明有两个-1节点 
		printf("-1");
		return 0;
	}
	
	//从尾部开始找 
	while(1){
		count = 0;//重置为0 
		for(i = 0;i< number&&node[i].flag==1 ;i++){
			if(node[i].next == node[record].address){ 				
				node[record].flag == 0;//减少比较次数 
				record = i;//将record变成i 				
				count++;//记录有几个相同的尾部指针 
				if(count == 2){							
					printf("%05d",node[record].next);//输出	
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
