#include <stdio.h>

#define size 100001
int main(){
	int n;
	scanf("%d",&n);
	
	int i ,j ,max = 0,min = 1000000002;
	
	int array[size][3];//0为本值，1为是否比前面数都大，2为是否比后面数都小 
	for (i = 0;i<n;i++){
		scanf("%d",&array[i][0]);	
		if(array[i][0] >= max){
			array[i][1] = -1;//避免两个数值恰好相等 
			max = array[i][0];//更新max值 
		}
	} 
	
	for (i = n-1;i >=0;i--){
		if(array[i][0] <= min){
			array[i][2] = -1;
			min = array[i][0];//更新max值 
		}
	} 
	
	int total = 0; 
	int record[size];
	for(i = 0;i<n;i++){		
		if(array[i][1] == -1 && array[i][2] == -1){				
			record[total++] = array[i][0];				
		}	
	}
	
	printf("%d\n",total);
	for(i = 0;i<total;i++){
		printf("%d",record[i]);
		if(i!=total-1){
			printf(" ");
		}
	}
	printf("\n");
}
/**
5
1 3 2 4 5

5
1 3 3 4 5


10
10 9 8 7 6 5 4 3 2 1

1
1

2
1 2
*/	
