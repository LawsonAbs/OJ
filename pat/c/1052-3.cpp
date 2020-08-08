#include <cstdio>
#include <algorithm>
using namespace std;
//#define maxSize 100001
const int maxSize = 100003;

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
	Lnode trueNode[maxSize];//真正的链表序列
	 
	scanf("%d %d",&number,&startLocation);	
	int i,j=-1;//循环 
	int count = 0;//表示真正的链表的数目 	
	for(i = 0;i<number;i++){
		scanf("%d%d%d",&node[i].location,&node[i].data,&node[i].next);//输入数据值 			
		if(node[i].location == startLocation){
			j = i;//找出头节点的下标			
		}
	} 
	if(j == -1){//说明没有以startLocation开始的节点 
		printf("0 -1");
		return 0;//直接结束 
	} 
	
	//从头节点开始遍历，找出其中不属于链表的节点		
	while(node[j].next !=-1 ){		
		int k ;//遍历需求 
		for(k = 0;k< i;k++){
			if(node[k].location == node[j].next){
				trueNode[count++] = node[j]; //移动到新的结构体中 
				j = k;//赋值 
			}							
		}
	}	
	trueNode[count] = node[j];//将最后一项赋值 
	
	
	sort(trueNode,trueNode+count+1,cmp);//使用sort排序 	
	printf("%d %05d\n",count+1,trueNode[0].location);
	//如果输出的少一项，则要判断是否是循环中少了一项（写法是否正确） 
	for(int j = 0;j < count + 1;j++){
		if(j != count){
			printf("%05d %d %05d\n",trueNode[j].location,trueNode[j].data,trueNode[j+1].location);	
		}
		else
		{
			printf("%05d %d -1\n",trueNode[j].location,trueNode[j].data);
		}		
	}			
}
/**
5 00001
11111 100 -1
00002 0 -1
33333 100000 11111
12345 -1 33333
22222 1000 12345

2 00001
00001 0 22222
22222 1000 12345
**/
