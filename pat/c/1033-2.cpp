#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int inf = 10000000;

struct station{
	double price,dis;
}st[maxn];

//按照距离从小到大排序 
bool cmp (station a,station b){
	return a.dis < b.dis;
}

int main(){
	int n;//总站数 
	double cMax,D,dAvg;//油箱最大容量，终点距离，单位耗油行驶距离 
	scanf("%lf %lf %lf %d",&cMax,&D,&dAvg,&n);
	for(int i = 0;i<n;i++){
		scanf("%lf %lf",&st[i].price,&st[i].dis); 
	} 
	
	//为了统一化处理 
	st[n].price = 0,st[n].dis = D;
	
	//对其进行排序 
	sort(st,st+n,cmp);
	
	//1.如果第一个站都不能到达，则直接跳出 
	if(st[0].dis!=0){
		printf("The maximun travel distance = 0.00\n");
	}
	//2.否则，进入程序主系统 
	else{
		int now = 0;//设置当前站点为now 
		
		//ans：总花费，nowTank:汽车当前油量，Max:满油行驶距离 
		double ans = 0,nowTank = 0,Max = cMax * dAvg;
		
		//每次循环将选出下一个需要到达的站 
		while(now < n){
			
			//3.选择从当前加油站能达到范围内的第一个油价低于当前油价的加油站
			//如果没有低于当前油价的加油站，则选择最低价格的那个			
			//-->使用的方法是：priceMin更新 !!即使找不到最低的，也要找一个比较低的！ 
			
			int k = -1;//k：最低油价的加油站编号，初始化为 -1 
			double priceMin = inf;//最低油价， 初始化为比较大的值 
			for(int i = now + 1;i<=n && st[i].dis - st[now].dis <= Max ;i++){
				if(st[i].price < priceMin){//更新最低油价 ，但不一定比当前还要低 
					priceMin = st[i].price; 
					k = i;
								
					//如果找到一个比当前油价还要低的，直接中断循环
					if(priceMin < st[now].price){
						break;
					} 										
				}
			}
			
			//满油状态无法找到加油站，退出循环 
			if(k == -1) break; 
			
			//下面为能找到的加油站k,计算转移花费
			//need 为从now到k需要的油量			
			double need = (st[k].dis - st[now].dis) / dAvg;
			if(priceMin < st[now].price){//如果加油站k的油价低于当前油价 
				//只买足够到达加油站k的油
				if(nowTank < need){//如果油量不足need 
					ans += (need - nowTank) * st[now].price;//补足到need需要的花费 
					nowTank = 0;//到达加油站k后，油箱油量为0 
				} 
				else{
					nowTank -=need;//直接到达 
				} 
			}
			else{
				ans +=(cMax - nowTank) * st[now].price;//将油加满
				nowTank = cMax - need;//求出剩余油量 
			} 
			now = k;//到达加油站k，进入下一层循环 
		} 
		if(now == n){
			printf("%.2f\n",ans);
		} 
		else{
			printf("The maximum travel distance = %.2f\n",st[now].dis + Max);
		}
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
*/ 
