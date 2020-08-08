#include<cstdio> 
#include<algorithm>
# define N 100001

int main(){
	int total;
	scanf("%d",&total);
	
	int i;
	int array[total];
	int result [total+2];//用于保存结果的数 
	int number;
	
	for(i = 0;i<= total+1;i++){
		printf("%d ",result[i]);
	} 
		
	for(i = 1;i <= total + 1 ;i++){
		result[i] = i;
	}	
	
	//输入total 个整数 
	for(i = 0;i< total;i++){
		scanf("%d",&array[i]);
		if(array[i] > 0){//大于 0 
			if(array[i] <= total){ //小于total 
				result[array[i]] = 0;//说明这个整数出现过 
			}
		} 
	}
	
	for(i= 1;i < total + 2;i++){
		if(result[i] != 0){
			printf("%d\n",i);
			break;
		}
	}
}
/*
10
5 -25 9 6 1 3 4 2 5 17

5
1 2 3 4 5


5
1 2 3 5 6

2 
1 -1
*/ 
