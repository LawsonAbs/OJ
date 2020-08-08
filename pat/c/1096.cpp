#include <stdio.h>
#include <math.h>

#define size 10000

int main(){
	int number;
	scanf("%d",&number);
	
	int i ;
	int array[size]={0},tempPro;//数组array[]用来存储长度，temp用来存储当前可以除尽number的数i
	int tempNum ;

	
	int primeFlag = 1; 
	for(i = 2;i <= sqrt(number);i++){				
		tempNum = number;//暂存number的值 				
		if(tempNum % i == 0 ){//如果说能够除尽
			primeFlag = 0;	//素数标志 
			array[i] ++;//代表连续乘值加1 
			tempPro = i;
			tempNum /= i;//更新 
			int j = i+1; 
			while(tempNum != 0){//直到除尽 				
				if(tempNum % j == 0){//如果能够将j整除 
					if(j == 1 + tempPro){//如果连续 
						array[i]++; //长度加1 
						tempPro = j;//更新tempPro值 
						tempNum /= j;  
					}			
					else
						break;
				}
				else
					break;//跳出循环 
				j++;//j往后加1 
			}
		}
	}
	
	if(primeFlag){
		printf("1\n%d",number);
		return 0;
	}
	
	int max = 0,k;//k是用来记录i值 
	for(i = 2;i < sqrt(number) ;i++){
	//	printf("%d ",array[i]);
		if(array[i] > max){
			max = array[i];
			k = i; 
		}
	} 
	printf("%d\n",array[k]);
	int m = k;
	while(array[k]-- > 0){
		printf("%d",m);
		if(array[k]!=0){
			printf("*");
		}
		m++;
	}printf("\n");
}
/*
630
*/
