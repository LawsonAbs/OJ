#include <cstdio>
#include <stack>
#define maxn 100000
using namespace std; 

struct Node{//链表节点 
	int next;//指针 
	int data;//数据 
	int address; //节点下标即作为节点的地址 
};

int main(){
	Node  node[maxn];
	Node temp;
	stack<Node> st;
	int i;
	int startAddr,num,k;//地址，总数，倒转数 
	int flag = 0;//标志 
	int control = 0;//控制输出 
	int tempAddr;
		
	scanf("%d %d %d",&startAddr,&num,&k);
	for(i = 0;i < num ;i++){
		scanf("%d",&tempAddr);//先输入节点的地址-->作为数组的下标 
		scanf("%d %d",&node[tempAddr].data,&node[tempAddr].next);//再输入data 与 next
		node[tempAddr].address = tempAddr;		
	}
	tempAddr = startAddr;//暂存值 
				
	int count = 0;//实际有效节点的数目
	while(startAddr != -1){
		startAddr = node[startAddr].next;//下一位 		
		count++; //计数 
	} 
	startAddr = tempAddr;//回到原来的值
	 	
	int count1 = 0, count2 = 0;//总计数  倒转计数 
	while( count - count1 >= k ) {
		while(count2 < k){//找节点 
			st.push(node[startAddr]);//压入栈 			
			startAddr = node[startAddr].next;//改变startAddr的值 
			count2++;			
		}
		while(!st.empty()) {//栈不为空则输出
			temp = st.top();
			if(control == 0 && flag == 0 ){
				printf("%05d %d ",temp.address,temp.data);	
			}
			else if(control != 0 && flag == 1){
				printf("%05d\n%05d %d ",temp.address,temp.address,temp.data);	
			} 
			else  {
				printf("%05d\n%05d %d ",temp.address,temp.address,temp.data);	//换行输出 
			}
			st.pop();//栈顶出栈	
			control++; 
		}
		flag = 1;  		
		count1 += k;//自加K 				
		count2 = 0;//重置为0 
	}
	if(count - count1 < k){
		if(startAddr != -1)	printf("%05d\n",startAddr);
		else	printf("-1\n");//最后一个节点 
	}
			 
	while(startAddr != -1){//输出剩余的节点		
		if(node[startAddr].next != -1)	
		printf("%05d %d %05d\n",node[startAddr].address,node[startAddr].data,node[startAddr].next);		
		else {
			printf("%05d %d ",node[startAddr].address,node[startAddr].data);
			printf("-1\n");
		}
		startAddr = node[startAddr].next;
	} 
}
/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00000 6 3
00000 1 11111
11111 2 22222
22222 3 33333
33333 4 -1
77777 5 55555
55555 6 -1

00000 6 2
00000 1 11111
11111 2 -1
22222 3 33333
33333 4 -1
77777 5 55555
55555 6 -1


注：
1.需要考虑到无效的节点，否则会导致死循环，运行超时.针对这种情况，需要先遍历找出所有有效节点的数目 
**/

