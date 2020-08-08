#include <cstdio> 
#include <algorithm>
using namespace std;


//注：使用预处理解决问题 
//1.每一对出口都有两种方案来寻找距离 ,但是数据太大会导致超时 
//2.于是我们思考有没有一种更加简单的方式--->将这若干个出口连接成环，计算每一个出口到第一个出口的距离，
//在求解a,b出口之间的距离时，可以直接相减，即可得到距离，但这个还不是最小的，我们需要将其和sum-sum1比较。
//取较小值 
 

int N;
int array[100002];
int dis[100002];//表示当前结点到初始节点的值，所以right到left的值即为dis[right]-dis[left] 
 
int sum1 = 0,sum2 = 0;
int sum= 0;//表示总得一个环的路径长度 


int main(){
	scanf("%d",&N);	
	int i = 0;
	
	dis[0] = 0;//表示第一个结点到自己的距离 
	//arrray[0]是出口1到出口2的距离，类推至n,有array[n-1]为第n个出口到第一个出口的距离 
	for(i = 1;i<=N;i++){
		scanf("%d",&array[i]);
		sum += array[i];//求出总得路径长度
		dis[i] = sum; //表示第i+1个结点到第一个节点的距离 
	}
	
	int M;
	int temp[2];
	scanf("%d",&M);
	while(M--){
		scanf("%d %d",&temp[0],&temp[1]);
		
		//将两个值交换，递增顺序 
		int a = 0;
		if(temp[0]>temp[1]){
			a = temp[0];
			temp[0] = temp[1];
			temp[1] = a;
		}

		sum1 = dis[temp[1] - 1]-dis[temp[0]-1];
		sum2 = sum - sum1;
			
		printf("%d\n",min(sum1,sum2));
		
	} 	
}
/**
5 1 2 4 14 9
3
4 1
1 3
2 5
**/
