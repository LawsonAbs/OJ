#include<cstdio>
#include<string> 
#include<iostream>
#include<algorithm>
#define maxn 1001
using namespace std;
struct Node{
	string name;
	int month,day,hour,min;//月 日 时 分 
	double total;//总金额 
	string status;//on-line  off-line 
}; 

int price[24];//cents/minutes 
Node node[maxn];
int num;

void init(){
	for(int i = 0;i < num;i++){
		node[i].total = 0;
	}
} 

bool cmp(Node n1,Node n2){
	if(n1.name == n2.name){
		if(n1.day == n2.day){
			if(n1.hour == n2.hour){
				return n1.min < n2.min;
			}
			else return n1.hour < n2.hour;
		}
		return n1.day < n2.day;
	}
	else return n1.name < n2.name;
}

int main(){
	int i;
	for(i = 0;i< 24;i++){
		scanf("%d",&price[i]);
	}
	
	scanf("%d",&num);
	for(i = 0;i< num;i++){
		cin>>node[i].name;
		scanf(" %d:%d:%d:%d",&node[i].month,&node[i].day,&node[i].hour,&node[i].min);
		cin>>node[i].status;
	}
	
	sort(node,node+num,cmp);
//	for(i = 0;i< num;i++){
//		cout<<node[i].name;
//		printf(" %02d:%02d:%02d:%02d ",node[i].month,node[i].day,node[i].hour,node[i].min);
//		cout<<node[i].status<<endl;
//	}
	
	//计算费用	
	int dayPrice = 0 ;//一整天的价格
	for(i = 0;i < 24;i++){
		dayPrice += price[i] * 60; 
	}//printf("dayPrice = %d\n",dayPrice); 
		
	int total = 0 , total_two = 0 , total_three = 0;//减去total_two 加上total_three
	int total_four = 0;
	int flagTwo = 0,flagThree = 0;
	string tempName = "0"; 	
	int practicalCount = 0;	
	double result[maxn]={0};//存放结果
	int lastMin = 0;//持续的分钟数 
	for(i = 0;i< num - 1;i++){//num-1 
		if(node[i].status == "on-line" && node[i+1].status == "off-line" && node[i].name == node[i+1].name){//如果符合条件 			
			
			if(node[i].name!=tempName )
			{			
				if(i!=0 && tempName != "0"){//确保不是第一次就输出 
					practicalCount ++;
					printf("Total amount: $%.2lf\n",result[practicalCount-1]);//并非是node[i-1].total 
				} 
				cout<<node[i].name;
				printf(" %02d\n",node[i].month);
				tempName = node[i].name;										
			} 
			lastMin = 0;//清0
			total = 0;//清0 			
			printf("%02d:%02d:%02d ",node[i].day,node[i].hour,node[i].min); 
			printf("%02d:%02d:%02d ",node[i+1].day,node[i+1].hour,node[i+1].min);
			if(node[i].day != node[i+1].day){//如果不是一天 ---> 处理天的问题 
				lastMin =( node[i+1].day - node[i].day ) * 24 * 60; 
				total = (node[i+1].day - node[i].day ) * dayPrice;
			}
			
			//01:02:23:03   与01:03:03:02							
			//01:03:23:03
			total_four = 0;			
			if(node[i+1].hour == node[i].hour){//如果相等 
				lastMin += node[i+1].min - node[i].min;
				total_four = (node[i+1].min - node[i].min) * price[node[i].hour];
			}
			
			total_two = 0;										
			while(node[i+1].hour < node[i].hour){//小于 
				flagTwo = 1; 
				if(node[i+1].min == 0){
					lastMin -= 60;
					total_two += 60 * price[node[i+1].hour];
					node[i+1].hour ++;
				}
				if(node[i+1].min != 0){
					lastMin -= (60 - node[i+1].min); 
					total_two += (60 - node[i+1].min) * price[node[i+1].hour];
					node[i+1].hour++;
					node[i+1].min = 0;//置0 
				}				
				 
			}
			if(flagTwo){
				total_two += price[node[i+1].hour] * node[i].min;
				lastMin -= node[i].min;
				flagTwo = 0; 
			}
						
			//01:02:03:03   与01:03:23:02							
			//01:03:03:03			
			//01:05:59 01:07:00	
			total_three = 0;
			while(node[i+1].hour > node[i].hour){//大于 
				flagThree = 1;
				if(node[i].min == 0 ) {
					lastMin += 60; 
					total_three += 60 * price[node[i].hour];
				}
				if(node[i].min != 0){
					lastMin += (60 - node[i].min );
					total_three += (60 - node[i].min) * price[node[i].hour];						  
				}
				node[i].min = 0;
				node[i].hour++;							
			} 
			if(flagThree){
				total_three += node[i+1].min * price[node[i+1].hour];
				lastMin += node[i+1].min; 
				flagThree = 0;//清0 
			}
					
			printf("%d ",lastMin);			
			double tempTotal = (double)(total - total_two + total_three + total_four)/100; 
			printf("$%.2lf\n",tempTotal) ;//输出每次的账单 
			result[practicalCount] += tempTotal;
			i++; //直接跳两个 
		}		
	}
	if(practicalCount == 0)  printf("Total amount: $%.2lf\n",result[0]);
	else	printf("Total amount: $%.2lf\n",result[practicalCount]);
}
/*月日时分 
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line


10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
2
CYJJ 02:01:07:00 off-line
CYJJ 02:01:05:59 on-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
4
CYdd 02:01:07:00 off-line
CYLL 02:01:05:59 on-line
CYJJ 02:01:07:00 off-line
CYJJ 02:01:05:59 on-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
4
CYnn 01:01:07:00 off-line
CYll 01:01:05:59 on-line
CYJJ 01:01:07:00 off-line
CYJJ 01:01:05:59 on-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 off-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 off-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
aaa 01:28:15:41 off-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
4
aaa 01:01:00:00 on-line
aaa 01:02:01:00 off-line
bbb 02:01:00:01 on-line
bbb 02:02:00:03 off-line

10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
4
bbb 02:01:00:01 on-line
bbb 02:02:00:03 off-line
aaa 01:01:00:00 on-line
aaa 01:01:00:01 off-line


10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
6
bbb 01:01:02:00 on-line
bbb 01:02:00:00 off-line
aa 01:01:02:01 on-line
aa 01:02:00:00 off-line
ccc 01:01:02:00 on-line
ccc 01:02:00:01 off-line
**/
