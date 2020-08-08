#include <stdio.h>

int main() {
	int number;//Êı×Ö 
	int base;//½øÖÆ 
	
	scanf("%d %d",&number,&base);
	int i; 
	
	if(number ==0){
		printf("Yes\n0\n");
		return 0;
	} 
	
	int array[1000];
	while(number!=0){
		array[i++] = number%base;
		number = number / base;
	}
	
	int j; 
	for (j = 0;j<i/2;j++){
		if(array[j] != array[i-1-j]) {
			break;
		}
//		printf("%d ",array[j]);
	}	
	if(j == i/2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	for (j = i-1;j >=0;j--){
		if(j!=0){
			printf("%d ",array[j]);	
		}
		else
		printf("%d",array[j]);
		
	}
	
}

/**
27 2
**/
