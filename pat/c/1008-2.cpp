#include <stdio.h>

#define size 1001
/*
1.去重，假设list上有两个连续的楼层 
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
	//对数组的最后一个数字进行判断 
	if( array[number] !=1){
		dealWithArray[number] = 1 - array[number];//求出到一楼的距离
		number++;
		//printf("最后= %d, i = %d",dealWithArray[number],i);		
	}
	
	int sum = 0 ;//初始化sum的值为0
	sum = number * 5;//加上所有楼层停的时间 
	
	int count = 0;//表示连续的相同楼层数 
	for(i = 0; i<number ;i++){
		//printf("%d\n",dealWithArray[i]);
		if(dealWithArray[i] < 0){
			sum = sum + ((-1) * dealWithArray[i] * 4) ;
		}
		else if(dealWithArray[i]>0)
			sum = sum +( dealWithArray[i] * 6 );
		else
		{
			//printf("%d",i);
			count ++;//连续楼层数加一 
		}			
	}
	printf("%d\n",sum);
	//printf("count = %d\n",count);
	sum = sum - (count * 5); 
	printf("%d",sum);
}
/**
3 2 3 1
1 0
**/
