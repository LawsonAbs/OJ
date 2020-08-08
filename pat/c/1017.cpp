#include <stdio.h>

char array[1000];//用来存储Mars字符

void dealWith(int number){
	int count = 0;
	if(number == 0){
		array[count++] = '0';
	}
	else{
		while(number!=0){
			if((number)%13>=0 && (number)%13 <=9){
				array[count++] = (number%13)+'0';	
			}
			else if((number%13) == 10){
				array[count++] = 'A';
			}
			else if((number%13) == 11){
				array[count++] = 'B';
			}
			else if((number%13) == 12){
				array[count++] = 'C';
			}
			number = number/13;				
		}		
	}
		
	int i ;
	for(i = count -1;i>= 0 ;i--){		
		if(count == 1 ){
			printf("0%c",array[i]);		
		}
		else{
			printf("%c",array[i]);		
		}		
	}	
}

int main(){
	int a,b,c;//代表三个数字
	scanf("%d %d %d",&a,&b,&c);
	printf("#");
	dealWith(a);
	dealWith(b);
	dealWith(c); 
} 
