#include <cstdio> 
#include <cstring>

typedef struct {
	int address;
	char data;
	int next;
	int flag;
}Node;

#define maxSize 100001
Node node[maxSize];//存储总的节点 

int main(){	
	for(int i =0;i<maxSize;i++){
		node[i].flag = 0;
	}		 
	int s1,s2,n;//s1,s2分别代表两条链表的首地址
	scanf("%d%d%d",&s1,&s2,&n);
	int i;
	for(i = 0;i<n;i++) {
		scanf("%d %c %d",&node[i].address,&node[i].data,&node[i].next);
	}	
	
	for(i = 0;i< n;i++){
		scanf("%d %c %d---\n",node[i].address,node[i].data,node[i].next);
	}
	
	//制造一个链式循环 
	int p = s1;
	while( p!=-1){
		node[p].flag = 1;//枚举第一条链表的所有节点，另其出现次数为1 
		p = node[p].next;
	} 
	
	p = s2;
	while(p!=-1){
		if(node[p].flag == 1)	break;
		p = node[p].next;//这里怎么可能是node[p]呢！！！ 
	} 
	if(p != -1){
		printf("%05d\n",p);
	}
	else{
		printf("-1");
	}
	return 0; 
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
**/
