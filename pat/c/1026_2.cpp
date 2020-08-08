#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#define maxn 10005
 
using namespace std;

struct User{
	int start_hour;//到达的时间 
	int start_min;
	int start_sec;
	int playTime;
	int startTime;//用户到达的时间（sec） 
	int endTime;//用户的完成时间（min为单位） 
	int isVip;//标志是否是vip
	int end_hour; 
	int end_min;
	int end_sec;
	int flag = 0 ;//表志是否已经服务过  初始化为0 
};

User user[maxn];
queue<int> que[maxn];//que 的二维数组  	//这里队列的下标跟桌子号一致，都是从1开始 
set<int> vip ;//表示的是vip桌子的下标号 
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
	
	//循环的条件是： i<N  
	for(i = 0;i < N ;i++ ){//开始把 N成员放入到桌子（队列）中 
		if(user[i].isVip == 0){//如果是非vip 			 
			for(j = 0;j< K;j++){//找出一张合适的桌子 
				if(vip.find(j) == vip.end() && que[j].empty()){//如果未找到该桌子，说明不是vip桌子 //如果这个桌子没有人					
					que[j].push(i);//将i这个用户 放入到队列j中	
					user[i].flag = 1; 
					break;//添加完用户之后，应该退出						
				}								
			}			
		}	
		else if(user[i].isVip == 1){//如果是vip用户 
			for(j = 0;j< K;j++){//找出一张合适的桌子 
				if(vip.find(j) != vip.end() && que[j].empty()){//如果找到该桌子，说明是vip桌子			//如果这个桌子没有人 
					que[j].push(i);//将i这个用户 放入到队列j中
					user[i].flag = 1; 
					break;				
				}
			}			
		}				
	}
}

int main(){
	cin >> N;
	int i,j;
	for(i = 0;i<N;i++){//输入用户的信息 		
		scanf("%d:%d:%d %d %d",&user[i].start_hour, &user[i].start_min,&user[i].start_sec,&user[i].playTime,&user[i].isVip);		
	}		
	
	cin >> K >> M;	
	int vipTable = 0;
	for(i= 0;i< M;i++){
		cin >> vipTable;
		vip.insert(vipTable) ; //表示这个桌子是 vipTable 
	}
	
	sort(user,user+N,cmp);//对用户进行排序 	
	
	cout <<"排队的用户有：\n"; 
	for(i = 0;i< N;i++){
		printf("i=%d,%02d:%02d:%02d\n",i,user[i].start_hour ,user[i].start_min ,user[i].start_sec );
	}
	
	init();//初始化设置
	for(i = 0;i< K;i++){
		printf("i=%d,队首=%d\n",i,que[i].front() );// 
	} 
	
	//其实可以省略第一步的初始化操作
	int curTable[maxn]={0};//表示每张桌子的当前时间  ,初始化的值为0 
		
	//开始对 N 个人进行服务 
	for(i = 0;i< N;i++){		
		if(user[i].flag == 1){// 如果已经服务过了，则判断下一个 
			continue;
		} 
				
		int minTime = 0x3fffffff ;//最小的时间 
		int minTable = -1;//最小的窗口号 			
				
		if(user[i].isVip == 1) {//先判断当前用户是否是vip 
			for(j = 0;j< K;j++){//接着判断是否有桌子 				
				int tempTime = curTable[j] + user[que[j].front()].playTime ;//这里桌子号从 1 开始 
				if(minTime > tempTime){//如果minTime 大于当前的 tempTime 
					minTime = tempTime;
					minTable = j ;//当前的桌号 
				}					 				 
			}
		}
				
		else{//否则作为一个普通用户进行判断 
			for(j = 0;j < K;j++ ){ //找出一个有效的桌子 ，桌子号从1开始 		
				if(vip.find(j) == vip.end()){//非 vip 桌子 
					int tempTime = curTable[j] + user[que[j].front()].playTime ;//这里桌子号从 0 开始 
					if(minTime > tempTime){//如果minTime 大于当前的 tempTime 
						minTime = tempTime;
						minTable = j ;//当前的桌号 
					} 
				}					
			}
		}		
						
		curTable[minTable] +=  user[que[minTable].front()].playTime;	//更新桌号的时间 
		user[que[minTable].front()].endTime = curTable[minTable];//更新用户的完成时间 	
		que[minTable].pop();//将队首出队
		que[minTable].push(i); //入队当前的用户 		 				
	}  
	
	//更新剩余的 table 的时间 
	for(i= 0 ;i< K;i++){
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
