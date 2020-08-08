#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

#define maxn 100010


char signNum;//数的符号 
char signExp;//指数的符号 
int array[maxn];//存储数字 
int count = 0;//有效数字位数 
int exponent = 0;//指数 

//对notation进行处理 
void deal(string str){
	int i = 1;
	signNum = str[0];
	
	while(str[i]!='E'){ 
		if(str[i]!='.'){
			array[count++] = str[i] - '0';//求数字  放入array中 
		}
		i++;
	} 
	i++;//指数的符号
	signExp = str[i] ; //存指数的符号
	
	
	i++;//开始求指数 
	int temp = 0;
	while(i<str.length()){
		temp = str[i] -'0';
		exponent = exponent  * 10 + temp;
		i++; 
	}
	//printf("exponent = %d\n",exponent);
}

int main(){
	string notation;//science notation
	cin>>notation;
	deal(notation);	
	int i;
	
	if(signNum == '-')	printf("-");
	if(signExp == '-'){//说明是小数 
		exponent--;
		printf("0.");
		while(exponent--){
			printf("0"); 
		}  		
		for(i = 0;i<count;i++){
			printf("%d",array[i]);
		}		
	}
	else{
		if(exponent >= count-1){//整数型 
			for(i = 0;i<count;i++){
				printf("%d",array[i]);
			}
			exponent -= (count-1);
			while(exponent--){
				printf("0");//输出后缀0 
			}
		}
		else if(exponent < count -1){//整数+小数型 			
			for(i = 0;i<count;i++){
				if(exponent!=0)	printf("%d",array[i]);
				else printf("%d.",array[i]);
				exponent--;//自减 
			}
		}
	} 
	
	
} 
/**
+1.23400E-03
-1.2E+10
+1.234E+02 
*/ 
