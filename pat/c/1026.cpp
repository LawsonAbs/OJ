#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 10005
 
using namespace std;

struct User{
	int start_hour;//到达的时间 
	int start_min;
	int start_sec;
	int playTime;
	int isVip;//标志是否是vip
	int end_hour; 
	int end_min;
	int end_sec;
};

User user[maxn];
int N,K,M; //N 是人数，K是桌子数，M是VIP的桌子数 

//对user 按照到达时间进行排序 
int cmp(User u1,User u2){
	if(u1.start_hour == u2.start_hour){
		if(u1.start_min == u2.start_min){
			return u1.start_sec < u2.start_sec;
		}
		else return u1.start_min < u2.start_min;
	}
	else return u1.start_hour < u2.start_hour;
}

int getSec(){
	int startSec = 0;	//开始的秒数 
	
} 

//将最开始到的组放入到队列中 
void init(){
	int i,j;
	for(i = 1;i <= K;i++ ){//开始把 成员放入到桌子（队列）中 
		
	} 
}

int main(){
	cin >> N;
	int i,j;
	for(i = 0;i<N;i++){//输入用户的信息 		
		scanf("%d:%d:%d %d %d",&user[i].start_hour, &user[i].start_min,&user[i].start_sec,&user[i].playTime,&user[i].isVip);
		
	}		
	
	cin >> K >> M;
	int vip[maxn] ={0};//表示的是vip桌子的下标号 
	int vipTable = 0;
	for(i= 0;i< M;i++){
		cin >> vipTable;
		vip[i] = vipTable; //表示这个桌子是 vipTable 
	}
	
	sort(user,user+N,cmp);//对用户进行排序 
	queue<int> que[maxn];//que 的二维数组  
	//这里队列的下标跟桌子号一致，都是从1开始 
	
	for(i = 0;i< N;i++){
		printf("%02d:%02d:%02d\n",user[i].start_hour ,user[i].start_min ,user[i].start_sec );
	}
	
	//其实可以省略第一步的初始化操作
	int curTable[maxn]={0};//表示每张桌子的当前时间  ,初始化的值为0 
		
	//开始对 N 个人进行服务 
	for(i = 0;i< N;i++){
		int minTime = 0x3fffffff ;//最小的时间 
		int minTable = -1;//最小的窗口号 	
		j = M;//重置为初始值 
		if(user[i].isVip == 1) {//先判断当前用户是否是vip 
			for(j = 0;j< M;j++){//接着判断是否有vip桌子 
				if(que[vip[j]].empty()) {//如果该队列为空，则放进去 					
					que[vip[j]].push(i);//将i这个用户添加到队列中 
					break; 
				} 
			}
		}
		if(j < M){//说明vip桌子尚未用完，这时，直接进行下一个用户 
			continue;
		}
		
		for(j = 1;j <= K;j++ ){ //找出一个有效的桌子 ，桌子号从1开始 		
			if(!que[j].empty()) {//如果该桌子的队列非空 
				int tempTime = curTable[j] + user[que[j].front()].playTime ;//这里桌子号从 1 开始 
				if(minTime > tempTime){//如果minTime 大于当前的 tempTime 
					minTime = tempTime;
					minTable = j ;//当前的桌号 
				} 
			}
			else {//否则直接使用 
				if(minTime > 0){//如果minTime 大于当前的 tempTime 
					minTime = 0;//直接将当前的时间置为0 				
					minTable = j ;//当前的桌号 
				} 				
			}		
		}
		if(minTime != 0){//如果不是第一次入队 
			curTable[minTable] +=  user[que[minTable].front()].playTime;	//更新桌号的时间 
			user[que[minTable].front()].playTime = curTable[minTable];//更新用户的完成时间 	
			que[minTable].pop();//将队首出队
			que[minTable].push(i); //入队当前的用户 
		} 
		else{
			que[minTable].push(i);//否则将当前的用户入队 			
		}		
	}  
	
	//更新剩余的 table 的时间 
	for(i= 1 ;i<= K;i++){
		while(!que[i].empty()){//如果队列非空 
			curTable[i] +=  user[que[i].front()].playTime;	//更新桌号的时间 
			user[que[i].front()].playTime = curTable[i];//更新用户的完成时间 
			que[i].pop();//出队				
		}
	}	
} 
/*
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2

*/
