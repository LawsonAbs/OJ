#include <stdio.h>
#include <algorithm>
using namespace std;

#define maxSize 10000

//1.系统的初始化数据会很怪 

typedef struct{
	double price,dis;//表示油价，到杭州的距离 
}Station;

bool cmp(Station s1,Station s2){
	return s1.dis < s2.dis;//到杭州距离从小到大 
}

int main(){
	int cMax,D,dAvg,N;//油箱容量，总路程，单位行驶距离，总站数
	scanf("%d %d %d %d",&cMax,&D,&dAvg,&N); 
	
	Station sta[maxSize];
	int i ;
	for(i = 0;i<N;i++){
		scanf("%lf %lf",&sta[i].price,&sta[i].dis);
	} 
	
	sta[i].price = 0,sta[i++].dis = D; 
	sort(sta,sta+N,cmp);
	
	//寻找当前站后面的第一个出现油价比当前站还有便宜的站
	double priceNow = sta[0].price;//表示当前站的油价 
	double total = 0;//总共花费的油钱 
	double maxDis = cMax * dAvg;//满油所能走得最远距离
	double tank = 0;//表示当前汽车内油箱的油	 
	int now = 0;//当前的位置 
	
	if(sta[0].dis!=0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	} 
	
	while(now < N){					
		//观察是否能够到达终点 ，如果不能，则跳出循环 
		if(sta[now+1].dis - sta[now].dis > maxDis)		break;
		
		//1.先找有没有满足能够到达且油价比当前低的站 
		int flag = 1;
		//need 为到达下一站需要的油量
		double need = 0; 
		for(i = now+1 ;i<=N ;i++){						
			//如果说后面存在：比当前站的油价还便宜的站
			//越早发现越好，（潜意思：找到最近的小于当前的油价站！！） 
			if(sta[i].price < sta[now].price && maxDis >= (sta[i].dis - sta[now].dis) ){								
				need = (sta[i].dis - sta[now].dis) / dAvg;
				if(tank < need){//如果不够 
					total += ( ( (sta[i].dis - sta[now].dis) / dAvg - tank) * sta[now].price );
					tank = 0;//到了油价低的站，置为0 
				}
				else{//如果够的话，则直接相减 
					tank -=need;
				}							
				now = i;//将第i站变为当前站
				flag = 0;//则不进入下面2 
				break;//跳出循环 				
			}
		}
		
		//2.如果没有找到比当前站油价低的站，则再找能到达站中油价尽可能低的站 
		if(flag){
			//求出未来几站中最低的油价--->保证比接下来的第一个站还要高一点 
			double minPrice = sta[now+1].price + 1 ; 
			int k;//存储最低油价的那个站点下标 
				 
			for(i = now+1;i<N;i++){
				//当该站的油价小于minPrice时，且可到达，且是最低的油价 
				if( minPrice > sta[i].price && maxDis >= (sta[i].dis - sta[now].dis)){
					minPrice = sta[i].price;										
					//需要的油量 
					need = (sta[i].dis - sta[now].dis) / dAvg; 	
					k = i;				
				}
			}
			//求出加满需要的钱 
			total += (cMax - tank)	 * sta[now].price ;	
			
			//油箱变满 
			tank = cMax; 
			
			//求出剩余量 
			tank -=need;					
			now = k;//变化当前站 
		}			
	} 
	if(now == N){
		printf("%.2lf",total); 
	} 
	//如果不能到达，则输出能够到达的最远距离 
	else{
		printf("The maximum travel distance = %.2lf\n",sta[now].dis + maxDis);
	}
}

/**
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

50 1300 12 2
7.10 0
7.00 600

50 1300 12 2
7.10 1
7.00 600
*/ 
