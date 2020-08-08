#include <stdio.h> 
#define size 100002


/*
1.当使用二分法的时候，如果是left = mid + 1 ; right  = mid - 1;
则循环结束条件是while(left <= right) {}
*/ 
int main(){
	int n,m;//n表示的是钻石数,m表示的是需要负的价钱 
	int diamond[size];//表示一个链上的钻石数 
	int sum[size];
	sum[0] = 0;//初始化第一项为0 
	scanf("%d %d",&n,&m); 
	
	int i ;
	for(i = 0;i<n;i++){
		scanf("%d",&diamond[i]);
		sum[i+1] = sum[i] + diamond[i]; 
	//	printf("%d\n",sum[i]);
	}
//	printf("%d\n",sum[i]);
	
	//开始遍历寻找价格刚好为m的链 
	int count = 0;//用来表示是否存在有恰好相等的数字
	int min = m;//用来表示两者金额差
	 
	for(i = 1 ; i <= n ; i++){
		int left = i,right = n;//左右边界 
		int mid;
		while(left <= right){//注意循环边界		
			mid = (left + right) / 2;//求出中间值
			if(sum[mid] < sum[i-1] + m) {//如果小于 
				left = mid + 1;//左边界值就等于中间值加1				
			}
			else if(sum[mid] > sum[i-1] + m){//如果大于 
				right = mid - 1;//右边界值就等于中间值减1
				if(min > sum[mid] -( sum[i-1] + m )){
					min = sum[mid] -( sum[i-1] + m );	
				}				
			}
			else{//两者相等 
				printf("%d-%d\n",i,mid); //输出i,mid值 
				min = 0;				
				break;							
			} 
		}
	}
	
	//如果说没有找到恰好相等的金额，那么就找出相对比较小的 
	if(min != 0){
		//printf("min = %d\n",min);
		for(i = 1 ; i <= n ; i++){
			int left = i,right = n;//左右边界 
			int mid;
			while(left <= right){//注意循环边界		
				mid = (left + right) / 2;//求出中间值
				if(sum[mid] < sum[i-1] + m) {//如果中间值小于的话 
					left = mid + 1;//左边界值就等于中间值加1
				}
				else if(sum[mid] > sum[i-1] + m){//如果中间值大于的话 
					right = mid - 1;//右边界值就等于中间值减1 
					//如果说刚好差值为 min 
					if(min == sum[mid] -( sum[i-1] + m )){
						printf("%d-%d\n",i,mid); //输出i,mid值 
					}
				}
			}
		}
	} 
}
/**
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

8 15
3 2 1 5 4 6 8 7

5 13
2 4 5 7 9

3 3
1 2 3

3 5
2 2 2

1 10
18
**/
