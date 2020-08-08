#include <stdio.h>

#define size 102
long int array[2][2];//分别存储分子，分母
//使用辗转相除法得到最大公约数 
long  int getBigNumber(long a ,long b){
	long int remain = a;
	while(remain != 0){//如果余数不等于0 		
		remain = a % b;
		a = b ;
		b = remain;		
	}
	return a; //返回最大公约数
} 

void change(long int a,long int b ){
	int flag2 = 0;//用来标志是否输出)号 
	//统一处理 
	if(a<0 && b<0){
		a = (-1) * a;
		b = (-1) * b;
	}
	else if(a < 0 && b > 0){		
		printf("(-");
		a = -1 * a;
		flag2 = 1;
	} 
	else if(a > 0 && b < 0){
		printf("(-");
		b = -1 * b;
		flag2 = 1;
	} 
	
	//求出第一个数的简写形式 
	int flag1 = 0;
	if(a >= b ){
		printf("%ld",a / b);//输出整数部分
		a %= b;
		flag1 = 1;
	}
	if(a!=0){
		long temp = getBigNumber(a,b);		
    	a /= temp;
		b /= temp;		
	}
	else{//a==0 
		if(!flag1){//如果一开始就比b小且为0 
			printf("0");			
		}
	}
	if(a != 0){
		if(flag1){
			printf(" %ld/%ld",a,b);		
		}
		else{
			printf("%ld/%ld",a,b);	
		}
	} 
	if(flag2){
		printf(")");
	}
} 

int main(){
	long int number;			
	scanf("%ld/%ld %ld/%ld",&array[0][0],&array[0][1],&array[1][0],&array[1][1]);//输入分子分母 	
		
	long int sumA = 0, sumB = 1; //和
	long int difA = 0, difB = 1;	//差 
	long int proA = 1, proB = 1; //积
	long int quoA = 0, quoB = 1; //商 	
	
	//求和 与 求差 
	if(array[0][1] != array[1][1]){
		if(array[0][1] % array[1][1] == 0){ 
			sumA = array[1][0] * (array[0][1] / array[1][1]) + array[0][0];
			sumB = array[0][1] ;
			
			difA = array[0][0] - array[1][0] * (array[0][1] / array[1][1]) ;
			difB = array[0][1] ;
		}
		else if( array[1][1] % array[0][1] == 0 ){
			sumA = array[0][0] * (array[1][1] / array[0][1]) + array[1][0];
			sumB = array[1][1];
			
			difA = array[0][0] * (array[1][1] / array[0][1]) - array[1][0];
			difB = array[1][1];
		}
		else{
			sumA = array[0][0] * array[1][1] + array[1][0] * array[0][1];
			sumB =  array[0][1] * array[1][1];
			
			difA = array[0][0] * array[1][1] - array[1][0] * array[0][1];
			difB =  array[0][1] * array[1][1];
		}
	}
	else{//如果两者相等 
		sumA = array[0][0] + array[1][0] ;
		sumB = array[0][1];
		
		difA = array[0][0] - array[1][0] ;
		difB = array[0][1];
	}
	
	//求积
	proA = array[0][0] * array[1][0] ;
	proB = array[0][1] * array[1][1];
		
	//求商
	int flagQro = 1; 
	if(array[1][0]!=0){
		quoA = array[0][0] * array[1][1] ;
		quoB = array[0][1] * array[1][0];				
	} 
	else{
		flagQro = 0;
	}
	
	//输出加减乘除 
	change (array[0][0],array[0][1]);printf(" + ");change (array[1][0],array[1][1]);printf(" = ");change(sumA,sumB);printf("\n"); 
	change (array[0][0],array[0][1]);printf(" - ");change (array[1][0],array[1][1]);printf(" = ");change(difA,difB);printf("\n");
	change (array[0][0],array[0][1]);printf(" * ");change (array[1][0],array[1][1]);printf(" = ");change(proA,proB);printf("\n");
	if(flagQro)
	{
		change (array[0][0],array[0][1]);printf(" / ");change (array[1][0],array[1][1]);printf(" = ");change(quoA,quoB);printf("\n");	
	}
	else
	{
		change (array[0][0],array[0][1]);printf(" / ");change (array[1][0],array[1][1]);printf(" = ");printf("Inf\n");
	}
}

/*
2/3 -4/2

1/2  2/4

1/3 -2/6

4/3 0/2

1/1 1/1 

0/1 2/1 

2/1 0/2



**/
