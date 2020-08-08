#include <cstdio>
#include <algorithm>
using namespace std;

#define maxSize 100001
 
typedef struct{
	int data;//值域
	int next;//指针域值 
	int location;//自己的位置 	
}Lnode;//定义节点 

//定义比较函数 
bool cmp(Lnode a,Lnode b){
	return	a.data < b.data;
}

int main(){
	int number;//输入数据数
	int startLocation; //初始位置
	Lnode node[maxSize];//申请一个LNode型数组
	 
	scanf("%d %d",&number,&startLocation);	
	int i;	
	int data,next,location;
	for(i = 0;i<number;i++){
		scanf("%d%d%d",&node[i].location,&node[i].data,&node[i].next);//输入数据值 
	} 
	
	sort(node,node+i,cmp);//使用sort排序 
	printf("%d %05d\n",number,node[0].location);
	for(int j = 0;j < i;j++){
		if(j != i-1){
			printf("%05d %d %05d\n",node[j].location,node[j].data,node[j+1].location);	
		}
		else
		{
			printf("%05d %d -1\n",node[j].location,node[j].data);
		}		
	}			
}
/**
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

2 00001
00001 0 22222
22222 1000 12345
**/
