#include <cstdio>
#include <string.h>
#define maxn 100

int digit;//有效位 
int array1[maxn],array2[maxn];
int count1 = 0,count2 = 0;
int len1 = 0, len2 = 0; 

void process(char str[],int array[],int &len1,int &count1,int index);//对字符串进行处理
void printOutcome(int array1[],int array2[]);//对字符串进行输出 

int main(){
	char str1[maxn],str2[maxn];	
	int i= 0,j = 0;
	int index = 0;//数组的下标索引 
	
	scanf("%d %s %s",&digit,&str1,&str2);
	
	process(str1,array1,len1,count1,index); 
	process(str2,array2,len2,count2,index);
	printOutcome(array1,array2);
	return 0 ; 
}

void process(char str[],int array[],int &len,int &count,int index){
	int temp,i;
	//对str1操作 
	//1.删除前导0 
	while(strlen(str)>0 && str[index] == '0' ){
		index++; 
	}//index1此时即为第一个不为0的字符所在的下标 
	//2.求指数 求主体 
	if(str[index] == '.'){//情况为000.00123
		index ++;//先跳过小数点 
		temp = index;//小数点后的数的下标 
		while( str[index]!='\0' && str[index] == '0'){//先求出指数 
			count--;//作为幂 
			index ++; 
		} 
		if(str[index]!='\0'){
			while(str[index]!='\0'){
				array[len++] = str[index] - '0';//赋值到array1数组中 
				index++;
			}	
		}
		else{
			count = 0;//重置为0 
			for(i = 0;i < digit ;i++){
				array[i] = 0;
			}
		}	
	}
	else if(str[index] == '\0'){//如果数为0，并且已到末尾 
		for(i = 0;i < digit ;i++){
			array[i] = 0;
		}
	}
	else{//情况为000012.123 
		temp = index ;	
		while(str[index]!='.' && str[index]!='\0'){ 
			index++;
			count++;//作为幂 			
		}
		index =  temp;
		while(str[index]!='\0'){
			if(str[index]!='.'){
				array[len++] = str[index] - '0';	
			}
			index++;
		}
	}
} 

void printOutcome(int array1[],int array2[]){
	int i,j;
	//对比输出
	for(i = 0;i < digit;i++){
		if(array1[i]!=array2[i]){
			printf("NO 0.");							
			for( j = 0;j <digit ; j++){//输出numOne 
				printf("%d",array1[j]);
			}
			printf("*10^%d ",count1);
								
			printf("0.");//输出numTwo 
			for(j = 0;j <  digit;j++){
				printf("%d",array2[j]);
			}	
			printf("*10^%d",count2);
			break;	
		}
	} 
	if(i == digit  ){
		printf("YES 0.");
		for(j = 0;j < digit ;j++){
			printf("%d",array1[j]);
		}		
		printf("*10^%d",count1); 	
	}	
}	
	
/*
3 0012.123 12.234
2 1.111 1.112
4 1.111 1.112
3 12300 12358.9
3 120 128
1 0.11 0.12
2 0.11 0.12
2 1.12 1.21
4 0 0000.00
4 000.00 00

注
2.不能直接对浮点数取整数，否则样例4会出现问题 
3.没有全面考虑测试用例 
4.删除前导0  
*/ 
