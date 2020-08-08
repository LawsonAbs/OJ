#include <cstdio> 
#include <algorithm>
using namespace std;

typedef struct {
	int address;//当前地址
	int data;//数据内容
	int next;//下一指针 
}LinkList;

#define maxn 10000

bool cmp(LinkList a ,LinkList b ){
	return a.data < b.data;
}

int main(){
	LinkList list[maxn];//链表
	
	int n,headAddress;//结点数，头结点的地址
	scanf("%d%d",&n,&headAddress);
	int i;//循环变量 
	for(i = 0;i< n;i++){
		scanf("%d%d%d",&list[i].address,&list[i].data,&list[i].next);//输入结点信息 
	}
	
	sort(list,list+n,cmp); 
	
	printf("%d %d\n",n,list[0].address);
	for(i = 0;i< n;i++){
		if(i != n-1){
			printf("%05d %d %05d\n",list[i].address,list[i].data,list[i+1].address);	
		}
		else
			printf("%05d %d -1",list[i].address,list[i].data);
	}	 	
}
/*
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
*/
