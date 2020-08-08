#include <stdio.h>

#define size 102

//使用辗转相除法得到最大公约数 
int  getBigNumber(int a ,int b){
	if(a % b == 0){
		return b;
	}
	else if(b % a == 0){
		return a;
	}
	
	int remain = a % b;
	while(remain != 0){//如果余数不等于0 
		remain = a % b;
		a = b;
		b = remain;				 
	}
	return a; //返回最大公约数
} 

int main(){
	int number;
	long array[size][2];//分别存储分子，分母
	
	scanf("%d",&number);
	int i;
	for(i = 0;i<number;i++){
		scanf("%d/%d",&array[i][0],&array[i][1]);//输入分子分母 
	}
	
	int a = 0, b=1  ; //a为分子，b为分母 
	//依次两两求和 
	for (i = 0;i<number;i++){
		if(array[i][1] != b){//如果两者分母不一样 --->同分母 
			if(array[i][1] % b == 0){ 
				a = a * (array[i][1] / b) + array[i][0];
				b = array[i][1] ;
			}
			else if( b % array[i][1] == 0 ){
				a = a + array[i][0] * (b / array[i][1]);
			}
			else{
				a  *= array[i][1];
				array[i][0] *=b;
				a += array[i][0];
				b *= array[i][1];
			}
		}
		else{//如果两者相等 
			a += array[i][0];//a为两者相加，b不变 			
		}
		
		//化成最简分数 
		int n = getBigNumber(a,b);
		a /= n;
		b /= n; 
	}
	
	int  flag = 0; 
	if(a == 0){
		printf("0\n");
		return 0;
	}
	if(a > b){		
		printf("%d",a/b);
		a %= b;	
		flag = 1;
	}
	if(a != 0){
		//printf("%d/%d\n",a,b);
		int n = getBigNumber(a,b);
		//printf("n = %d\n",n);
		
		//控制空格 
		if(flag){
			printf(" %d/%d\n",a/n,b/n);	
		}
		else{
			printf("%d/%d\n",a/n,b/n);	
		}		
	}
}

/*
5
2/5 4/15 1/30 -2/60 8/3

4
1/3 -1/3 -1/3 1/3

3
1/3 -1/6 1/8
**/
