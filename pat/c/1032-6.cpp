/*�ܽ�
1.���͵Ĵ�����롣ԭ��������ʹ������ѭ�� 
	while(p!=-1){
		node[p].flag = true;
		p = node[p].next;		
	}
ʱ������Ӧ����ʶ�������node[p]�е�p���±꣬������while(p)�еĵ�p��ָ���ǵ�ַ�����߲�����ͬ���� 
2.����ʹ�õ���ɢ�е�֪ʶ��ʹ��ÿһ����ַ��Ӧ�����е�ÿһ���±ꡣ 
*/ 
#include <cstdio>
#include <cstring> 

typedef struct{
	char data; 
	int next;//ָ��
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
	
	int address,next;//�ڵ��ַ���̵�ַ
	char data;//���� 
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
