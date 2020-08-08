#include <stdio.h> 
#include <algorithm>
using namespace std;
 
#define size 100002


/*
1.使用二分法解决此题
*/ 

int main(){
	int n ,money;//n是number of coins
	scanf("%d %d",&n,&money);
	
	int i;
	int array[size];
	for(i = 0;i<n;i++){
		scanf("%d",&array[i]);//输入各个coin的价值				
	} 
	sort(array,array+n);//将其从小到大排序 
	
//	for(i = 0;i<n;i++){
//		printf("%d ",array[i]);	
//	}
//	printf("\n");
	
	if(n == 1)
	{	
		printf("No Solution");
		return 0 ;
	} 
	for(i = 0;i < n;i++){
		int left = i+1,right = n ;//左右区间，从i+1开始 
		int result = money - array[i];//找这个数字是否存在 (method of bisection) 
		
		while(left <= right){
			int mid = (left + right) /2;			
			if(array[mid]  < result){
				left = mid+1;
			}
			else if(array[mid] > result){
				right = mid-1;
			}
			else{
				printf("%d %d",array[i],array[mid]);				
				return 0;				
			}
		} 
	}
	printf("No Solution");
}
/**
1 15
15

8 15
1 2 8 7 2 4 12 15

7 14
1 8 7 7 4 11 15

7 14
1 8 7 2 4 11 15

8 15
1 2 8 7 2 4 11 15
**/
