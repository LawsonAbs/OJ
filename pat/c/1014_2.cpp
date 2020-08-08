/**
1.仔细分析题意，观察队列的大小从而决定排在哪一条队伍中 
2.题目假设的是，需要银行服务的人都是提前到达的，即是人等窗口，而非窗口等人 
3.顾客与窗口的下标都是从1开始！！ 
*/
#include<cstdio>
#include<queue>
using namespace std;
#define maxn 1002

struct Window{
	queue<int> q;//队列存储人的序号
	int endTime,popTime;//队尾 队首 
}; 

int convertToMinute(int h,int m){
	return h* 60 + m;//将时间转化为分钟 
} 

Window win[20]//最多只有20个窗口
int winNum, lineContain,customerNum,queryNum;
int startTime = 8 * 60;//银行上班的时间 
int ans[maxn] , needTime[maxn];//服务结束的时间（下标从1开始）  服务需要的时间（下标从1开始） 

int main(){
	scanf("%d %d %d %d",&winNum,&lineContain,&customerNum,&queryNum);
	int i;
	for(i = 0;i< customerNum;i++){//顾客下标从1开始 
		scanf("%d",needTime[i]);//需要服务的时间
	} 
	for(i = 0;i< queryNum;i++){
		scanf("%d",&query[i]);//输入查询的序号	
	}
	
	int index = i;//第index位顾客尚未入队 
	for(i = 0;i < customerNum && i < (lineContain * winNum) ;i++){//将人循环入队  并且同时计算服务结束时间 
		win[i%winNum].q.push(i);
		win[i%winNum].endTime += needTime[i];//更新窗口的服务结束时间
		ans[i] = win[i%n].endTime;		
	}
	
	
	int j; 
	int count = 1; 
	for(;i <= customerNum ;i++){//处理剩余未入队的人 
		for(j = 0;j < winNum;j++){//从所有的窗口中找一个最早结束的窗口 
			win[j].popTime = win[j].q.front()
			ans[count++] = win[j].endTime; 
		}
	} 
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
***/
  
