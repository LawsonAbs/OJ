/*总结
1.典型的错误代码。原因：我们在使用下列循环 
	while(p!=-1){
		node[p].flag = true;
		p = node[p].next;		
	}
时，我们应该意识到这里的node[p]中的p是下标，但是在while(p)中的的p的指的是地址，两者并不等同！！ 
2.这里使用到了散列的知识，使得每一个地址对应数组中的每一个下标。 
*/ 
#include <cstdio>
#include <cstring> 

typedef struct{
	char data; 
	int next;//指针
	bool flag ; 
}Node;

#define maxSize 100001 
Node node[maxSize];
 
int main(){
	int start1,start2,n;
	scanf("%d%d%d",&start1,&start2,&n);
	int i ;
	for(i = 0;i< maxSize;i++){
		node[i].flag = false;
	} 
	
	int address,next;//节点地址与后继地址
	char data;//数据 
	for(i = 0;i<n;i++) {
		scanf("%d %c %d",&address,&data,&next);
		node[address].data = data;
		node[address].next =next;
	}	

	int p;
	p =  start1;
	while(p!=-1){
		node[p].flag = true;
		p = node[p].next;		
	}
	
	p =  start2;
	while(p!=-1){
				
		if(node[p].flag == true){
			break;
		}
		p = node[p].next;
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
