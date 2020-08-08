#include<cstdio>
#include<queue>
#include<iostream>
#define maxn 1005
#define winMaxn 25
 
using namespace std;

int N,M,K,Q;

//有N个窗口 => 队列有N个 
queue<int> que[winMaxn];

//将分钟格式化输出为 小时：分钟 
void printRes(int totalMin){
	int min = totalMin % 60;
	int hour = totalMin / 60;		
	printf("%02d:%02d\n",hour+8,min);
} 

//初始化队列 
void initQue() {
	int i,j;
	int start = 1;	
	for(j = 1;j<= M;j++){ //黄线内的人数 
		start = (j-1) * N + 1;
		for(i = 1;i<= N;i++ ){		
			que[i].push(start);
			start++;
		}
	}
} 

int main(){	
	cin >> N >> M >> K >> Q;
	int i,j;
	int time[maxn];//表示每个人的需求时间	
	int comp[maxn];//表示对K个人的处理结果 
	int query[maxn];//表示查询的序列 
	int curWindow[N+1] = {0};//表示当前窗口的时间 
	
	//输入每个人的处理时间 
	for(i=1;i<=K;i++){
		cin >> time[i];
	}
	
	for(i = 1;i<=Q;i++) { //输入需要查询的人 
		cin >> query[i]; 
	}
	//首先对队列进行初始化处理
	initQue(); 
	
	//对剩下未入队的人进行轮流处理 
	//下标从1 开始 【不是从1开始，因为已经初始化过了】 ，故开始的下标是 N*M+1	
	for(i = N*M+1 ; i <= K;i++){
		//cout <<"当前正在判断的人是："<<i<<"\n";		
		int minWindow = -1;//最小时间所对应的窗口
		int minTime = 0x3fffffff;//所有窗口中，最小的时间	
						
		for( j = 1; j <= N;j++){ //从1号窗口开始 
		//	cout <<"队首的人是："<< que[j].front()<<"\n"; 
			int tempTime = ( curWindow[j] + time[que[j].front()] );
			if(minTime > tempTime ){//如果当前窗口的时间小于minTime,则选择更新minTime，并且更新minWindow 
				minWindow = j;
				minTime = tempTime ;
			}
		//	cout <<"minTime = "<<minTime<<"\n";			
		}	
		//cout <<"这次出队的是："<< que[minWindow].front() <<"\n";		
		curWindow[minWindow] += time[que[minWindow].front()];
		comp[que[minWindow].front()] = curWindow[minWindow];//写入完成的时间 		
		que[minWindow].pop();//将minWindow号窗口的第一个人出队		
		que[minWindow].push(i);//入i 			
	}
	
	//对黄线内的M 个人开始服务 
	for(i = 1;i<=N;i++){
		while(!que[i].empty()){
			curWindow[i] += time[que[i].front()];
			comp[que[i].front()] = curWindow[i];//写入完成的时间
			que[i].pop();//将队首元素出队 
		}
	}
	
	for(i = 1;i<=Q;i++){	
		int startTime = comp[query[i]] - time[query[i]];//表示顾客的开始处理时间
		if(startTime >= 540) cout <<"Sorry\n";
		else printRes(comp[query[i]]);			
	}
} 
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

2 2 4 4
1 2 6 4
1 2 3 4


1 2 4 4
1 2 6 4
1 2 3 4

1 2 4 4
1 2 597 4
1 2 3 4

3 2 4 4
1 2 540 4
1 2 3 4
*/

/*
上面这个代码存在问题：
01.这个N*M 如果大于当前的人数K怎么办？ 
02.这里简化了一个问题，就是人全部都是8:00到达。统一处理 
*/
