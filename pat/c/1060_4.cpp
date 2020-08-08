#include <cstdio>
#include <string.h>
#define maxn 100

int main(){
	int digit;//有效位 
	char str1[maxn],str2[maxn];
	int array1[maxn],array2[maxn];
	int count1 = 0,count2 = 0;
	int i= 0,j = 0;
	int index1 = 0,index2 = 0;//两个数组的下标索引 
	int len1 = 0, len2 = 0; 
	int temp;
		
	scanf("%d %s %s",&digit,&str1,&str2);
	
	//对str1操作 
	//1.删除前导0 
	while(strlen(str1)>0 && str1[index1] == '0' ){
		index1++; 
	}//index1此时即为第一个不为0的字符所在的下标 
	//2.求指数 求主体 
	if(str1[index1] == '.'){//情况为000.00123
		index1 ++;//先跳过小数点 
		temp = index1;//小数点后的数的下标 
		while( str1[index1]!='\0' && str1[index1] == '0'){//先求出指数 
			count1--;//作为幂 
			index1 ++; 
		} 
		if(str1[index1]!='\0'){
			while(str1[index1]!='\0'){
				array1[len1++] = str1[index1] - '0';//赋值到array1数组中 
				index1++;
			}	
		}
		else{
			count1 = 0;//重置为0 
			for(i = 0;i < digit ;i++){
				array1[i] = 0;
			}
		}	
	}
	else if(str1[index1] == '\0'){//如果数为0，并且已到末尾 
		for(i = 0;i < digit ;i++){
			array1[i] = 0;
		}
	}
	else{//情况为000012.123 
		temp = index1 ;	
		while(str1[index1]!='.' && str1[index1]!='\0'){ 
			index1++;
			count1++;//作为幂 			
		}
		index1 =  temp;
		while(str1[index1]!='\0'){
			if(str1[index1]!='.'){
				array1[len1++] = str1[index1] - '0';	
			}
			index1++;
		}
	}
	
	//对str2操作 
	//1.删除前导0 
	while(strlen(str2)>0 && str2[index2] == '0' ){
		index2++; 
	}
	//2.求指数 求主体 
	if(str2[index2]=='.'){//情况为000.00123
		index2 ++;//先跳过小数点 
		temp = index2;//小数点后的数的下标 
		while( str2[index2]!='\0' && str2[index2] == '0'){//先求出指数 
			count2--;//作为幂 
			index2 ++; 
		} 
		if(str2[index2]!='\0'){
			while(str2[index2]!='\0'){
				array2[len2++] = str2[index2] - '0';//赋值到array1数组中 
				index2++;
			}		
		} 		
		else{
			count2 = 0;//重置为0 
			for(i = 0;i < digit ;i++){
				array2[i] = 0;
			}
		}	
	}
	else if(str2[index2] =='\0'){
		for(i = 0;i<digit;i++){
			array2[i] = 0;
		}
	}
	else{//情况为000012.123 
		temp = index2 ;	
		while(str2[index2]!='.' && str2[index2]!='\0'){ 
			index2++;
			count2++;//作为幂 			
		}
		index2 =  temp;
		while(str2[index2]!='\0'){
			if(str2[index2]!='.'){
				array2[len2++] = str2[index2] - '0';	
			}
			index2++;
		}
	}
	
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
1.double型变量可以使用lf%或者f%输入，但是必须使用lf%来输出，（最好用lf%）；float型变量可以用lf%输出，但是必须用f%输入（最好用f%）。 
2.不能直接对浮点数取整数，否则样例4会出现问题 
3.没有全面考虑测试用例 
4.删除前导0 
5.c语言中，strlen()函数用于获取字符串长度


*/ 
