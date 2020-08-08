#include <stdio.h>

#define size 1001
/*
1.去重，假设list上有两个连续的楼层 
2.最后不必回到第0层或者第1层，注意题目要求 
*/ 

int main(){
	int number;	
	int array[size], dealWithArray[size]={0};//一开始的数组和处理后的数组 
	
	scanf("%d",&number);
	int i ;
	array[0] = 0;//the start is zero floor 
	for(i = 1;i <= number;i++){
		scanf("%d",&array[i]);
			dealWithArray[i-1] = array[i] - array[i-1];//求出两个楼层之间的距离 						
	}
	
	int sum = 0 ;//初始化sum的值为0
	sum = number * 5;//加上所有楼层停的时间 
	
	for(i = 0; i<number ;i++){
		//printf("%d\n",dealWithArray[i]);
		if(dealWithArray[i] < 0){
			sum = sum + ((-1) * dealWithArray[i] * 4) ;
		}
		else if(dealWithArray[i]>0)
			sum = sum +( dealWithArray[i] * 6 );			
	} 
	printf("%d",sum);
}
/**
3 2 3 1
1 0
**/
