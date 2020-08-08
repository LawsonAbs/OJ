#include <stdio.h>
#include <math.h>

#define size 100//6位足够

/*
1.如果一个数是素数，那么无论在什么进制下都是素数！
*/ 

//在当前radix进制反转后，转换成十进制数total 
int	reverse(int a ,int radix){//a为数，radix为进制 
	int total  = 0 ,i = 0 ,j ;
	int array[size];	
	while(a!=0){//为了得到各位上的数 ---> 需要除以10 
		array[i++] = a % radix;
		a /= radix;
	} 		
	for(j = 0;j < i;j++){
		total = total * radix + array[j];
	}	
	//printf("反转后 = %d\n",total);
	return total;
}


//判断一个数是否为素数 
bool isPrime(int total){
	if(total < 2){//如果是0,1,2,则直接返回true 
		return false;
	}
	int i ;
	for(i = 2;i <= (int)sqrt(1.0 * total);i++){//素数判断从2开始 
		if(total % i == 0){
			return false;//返回false 
		}
	}
	return true;
} 

int main(){
	int number;
	int radix;
	while(scanf("%d %d",&number,&radix) == 2 ){
		if(number < 0){
			break;
		}
		if(number == 1 || number == 0){
			printf("No\n");
		}
		else{
			if(isPrime(number)){
				int total2 = reverse(number,radix);					
				if(isPrime(total2)){
					printf("Yes\n");
				}
				else
					printf("No\n"); 
			}
			else
				printf("No\n");			
		}		
	}		
} 
/**
73 10
23 2
23 10
0 2
-2 3
1 2
*/
