#include <stdio.h>
#include <math.h>

#define size 100000
/*
1.因子被找到的顺序总是从小到大
*/
bool isPrime(int number){
	int i;	
	for(i = 2;i <= sqrt(number);i++){				
		if(number % i == 0 ){//如果说能够除尽		
			return false;//跳出循环 				
			}
		}
	return true;
}	
	
int main(){
	int number;
	scanf("%d",&number);
	
	int i ;
	int array[size]={0};//数组array[]用来存储素数因子，大小表示为指数 
		
	int tempNum = number;
	int compare = 0 , count = 0;
	bool primeFlag = true;//默认为素数 
	
	for(i = 2;i <= sqrt(tempNum) ;i++){
		if(number % i == 0 && isPrime(i)){//能够被除尽，并且为素数 
			primeFlag = false; 
			if(compare != i){
				count++;//表示有多个素数因子 
				compare  = i;
			}
			array[i] ++ ;//表示有数 
			number /= i;
			i--;//可能还会被当前数再整除			
		}
	}
	printf("%d=",tempNum); 
	if(primeFlag){
		printf("%d",tempNum);
		return 0;
	}
		
	int j = 0;
	for(j = 2;j<sqrt(tempNum);j++){
		if(array[j]>0){
			count --;
			if(array[j]>1){
				printf("%d^%d",j,array[j]);
			}
			else
				printf("%d",j);
			if(count!=0){
				printf("*");
			}
		}
	} 
}
/*
64
97532468
*/
