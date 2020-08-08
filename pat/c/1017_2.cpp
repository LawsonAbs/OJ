/**
1.把到达、处理、等待的时间全部使用秒来计算。 
*/ 
#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;
#define maxn 10001

struct People{
	int arriveTime;
	int process;//需要处理的时间
};

vector<People> qu;//将人加入到队列中 

bool cmp(People p1,People p2){
	return p1.arriveTime < p2.arriveTime;
}

int main(){
	int num,winNum;//总人数  总窗口数 
	int i;
	People tempPeo;//暂存人的信息
	scanf("%d %d",&num,&winNum);
	int hour,minute,second,process;//时 分 秒 
	int boundary = 17 * 60 * 60 ;//17:00:00
	int count = 0;
	int window[maxn] ;//存放的是当前窗口的时间 
	int startTime = 8 * 60 * 60;//开始时间
	
	for(i = 0;i<num;i++){
		scanf("%d:%d:%d %d",&hour,&minute,&second,&process);//输入每个人的信息
		tempPeo.arriveTime = hour*60*60 + minute * 60 + second;		
		tempPeo.process = process * 60;
		if(tempPeo.arriveTime <= boundary){
			qu.push_back(tempPeo);//将每个人的信息入队 
			count ++; 
		} 
	}
	sort(qu.begin(),qu.end(),cmp);	
	for(i = 0;i < winNum;i++ ){//按照窗口数  进行初始化 
		window[i] = startTime; 
	} 

	double wait = 0; 
	int minStart;//找一个最小开始时间 去服务
	int index ;//最小开始时间的下标 
	//开始处理任务 
	while(!qu.empty()){//假设还有剩余人数未服务 
		minStart = 9999999;
		for(i = 0;i < winNum ;i++){//找第一个可以服务的窗口 
			if(window[i] < minStart){
				minStart = window[i];
				index = i;
			}
		}
		tempPeo = qu[0];
		qu.erase(qu.begin());//删除头 
		if(tempPeo.arriveTime < window[index]){//如果先到  窗口还未开启 
			wait += (window[index] - tempPeo.arriveTime); 
			window[index] += tempPeo.process;
		}	
		else{
			window[index] = tempPeo.arriveTime + tempPeo.process;
		} 
		//更新时间 ---> 不应该仅仅只是单纯的加 而是取两者较大值再加上处理的时间 
	}
	double avg = ( wait / 60) / count; 
	printf("%.1lf",avg);
}
/**
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

2 1
07:55:00 16
17:00:01 2

2 2
08:00:00 16
07:58:00 2
*/
