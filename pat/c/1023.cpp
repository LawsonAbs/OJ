#include <stdio.h>

int main(){
	long long number;
					
	scanf("%lld",&number);
	long long tempNum = number;
	
	int i,j ;
	int array1[10]={0},array2[10] = {0};
	while(number != 0 ) {
		array1[number % 10]++;//出现次数 
		number /= 10;  		
	}
	
	number = 2 * tempNum;
	tempNum = number; 
	while(number != 0){
		array2[number % 10]++;//出现次数 
		number /= 10;
	}
	for(i = 0;i<=9;i++){
		if(array1[i] != array2[i]){
			break;
		}
	}
	if(i > 9){//如果没有遍历完--->不完全相等 
		printf("Yes\n");
		 
	}
	else{
		printf("No\n");
	}
	printf("%lld",tempNum);
}
/*
1234567899
1000000000000000000
*/

