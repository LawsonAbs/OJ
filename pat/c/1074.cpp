/*注 
1.本算法运行结果正确，但是时间复杂度过大 
*/
#include <cstdio>
#include <stack>
#define maxn 100000
using namespace std; 

struct Node{//链表节点 
	int next;//指针 
	int address; //地址
	int data;//数据 
	int value;//有效值 
};

int main(){
	Node  node[maxn];
	stack<Node> st;
	Node temp;//暂存信息 
	int i;
	int addr,num,k;//地址，总数，倒转数 
	int flag = 0;//标志 
	int control = 0;//控制输出 
	int tempAddr;
		
	scanf("%d %d %d",&addr,&num,&k);
	for(i = 0;i < num ;i++){
		scanf("%d %d %d",&node[i].address,&node[i].data,&node[i].next);		
		node[i].value = 0; 
	}
	tempAddr = addr;
		
	int count = 0;//找出实际有效的节点数目
	i = 0;//重置为0 
	while(addr != -1){
		if(node[i].address == addr){
			node[i].value = 1; 
			addr = node[i].next;
			count++;
		}
		i++;
		i = i % num;
	} 
	addr = tempAddr;//回到原来的值
	 
//	printf("------\n");	
	int count1 = 0, count2 = 0;//总计数  倒转计数 
	while( count - count1 >= k ) {
		while(count2 < k){
			for(i = 0;i< num && count2 < k  ; i++){
				if(node[i].address == addr && node[i].value == 1){
					addr = node[i].next;//改变addr的值 
					st.push(node[i]);//压入栈 			
					count2++;//找到一个节点，加一
					node[i].value = 0;
					break;//跳出循环 
				}
			}
			if(count2==0){//如果遍历一遍仍然没有找到一个地址 		
				printf(" -1\n");
				return 0;//直接返回 
			} 
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
		if(count - count1 < k){
			if(addr != -1)	printf("%05d\n",addr);//如果恰巧是最后一个 
			else	printf("-1\n");
		}	
		count2 = 0;//重置为0 
	}
	
	//输出剩余的节点 
	int remain = count - count1;
	while(remain--){
		for(i = 0;i< num ;i++){
			if(node[i].address == addr){
				temp = node[i];
				//printf("remain = %d\n",remain);
				if(remain!=0)	printf("%05d %d %05d\n",temp.address,temp.data,temp.next);
				else {
					printf("%05d %d ",temp.address,temp.data);
					printf("-1\n");
				}
				addr = node[i].next;
				break;
			}			
		}
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

