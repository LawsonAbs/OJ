#include <stdio.h>
#define maxn 100

int main(){
	int digit;//有效位
	float num_one ,num_two;//两个浮点数 
	scanf("%d",&digit);
	scanf("%f %f",&num_one,&num_two); 
	int numOne = (int) num_one, numTwo = (int) num_two;
	//printf("%d %d",numOne,numTwo);
	int count1 = 0,count2 = 0;//计数
	int array1[maxn], array2[maxn];
	int i ; 
	while(numOne!=0){
		array1[count1] = numOne % 10 ;
		numOne /= 10;
		count1++; 
		
	}
	while(numTwo!=0){
		array2[count2] = numTwo % 10 ;
		numTwo /= 10;
		count2++; 
	}
	
	for( i = count1 - 1;i >= count1 - digit ;i--){
		if(array1[i]!=array2[i])	
		{
			printf("NO 0.");
			//输出numOne 
			for(int j = count1-1;j >= count1 - digit ; j--){
				printf("%d",array1[j]);
			}	
			printf("*10^%d ",count1);
			
			//输出numTwo 
			printf("0.");
			for(int j = count2-1;j >= count2 - digit;j--){
				printf("%d",array2[j]);
			}	
			printf("*10^%d",count2); 
			break;
		}
	} 
	if(i == count1 - digit - 1 ){
		printf("YES 0.");
		for(int j = count1 - 1;j >= count1 - digit ;j--){
			printf("%d",array1[j]);
		}		
		printf("*10^%d",count1); 	
	}	
} 

/*测试用例 
3 12300 12358.9
3 120 128
1 0.11 0.12 
2 1.111 1.112
3 0.0012 0.012


*/
