#include <stdio.h>
 
int main(){
	double game[10];//存储三轮结果
	
	int i  = 0;
	while(i<9){			
		scanf("%lf",&game[i++]);
	}
	
	double max1 = 0,max2 = 0,max3 = 0;
	char  flag1,flag2,flag3;
	for(i = 0;i<3;i++){
		if(max1 < game[i]){
			max1 = game[i];
			if(i  == 0){
				flag1 = 'W';	
			}
			else if(i == 1){
				flag1 = 'T';
			}
			else if(i == 2){
				flag1 = 'L';
			}			
		}
	}
	
	//求第二轮中最大 
	for(i = 3;i<6;i++){
		if(max2 < game[i]){
			max2 = game[i];
			if(i  == 3){
				flag2 = 'W';	
			}
			else if(i == 4){
				flag2 = 'T';
			}
			else if(i == 5){
				flag2 = 'L';
			}	
		}
	}
	
	
	//求第三轮中最大 
	for(i = 6;i<9;i++){
		if(max3 < game[i]){
			max3 = game[i];
			if(i  == 6){
				flag3 = 'W';	
			}
			else if(i == 7){
				flag3 = 'T';
			}
			else if(i == 8){
				flag3 = 'L';
			}	
		}
	}	
	double profit;	
	profit = (max1*max2*max3*(0.65)-1)*2;
	
//	profit = (profit*100+0.5)/100;
	printf("%c %c %c %.2lf",flag1,flag2,flag3,profit);	
}

/***
3.0 1.7 1.0
1.2 2.5 1.6
4.1 7.2 7.1

1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
**/
