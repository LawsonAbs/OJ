#include <stdio.h>
#include <string.h>
/*
1.使用全局变量可以扩大数组范围 
*/
#define size  100001
	
int main(){
	char string[size];//存储字符串 
	
	scanf("%s",string);//输入字符串
	int length;
	length = strlen(string);//求出字符串的长度
	//printf("%d",length);
	 
 	int i, j ,k ;	
 	int total  = 0;//用来表示有多少个pat 
	int sumP = 0,sumT = 0;//表示字符A前P 与后T的数目 
	int array[size][2] ,index = 0;
	//遍历 
	for(i = 0;i<length;i++){
		if(string[i] == 'A'){
			array[index++][0]  = sumP;
		} 
		if(string[i] == 'P'){
			sumP++;//如果为字符P，则加一 
		}
	}
	//index为字符串中A的数目 
	int temp = index; 
	for(i = length - 1;i >= 0;i--){
		if(string[i] == 'A'){
			array[--index][1]  = sumT;
		} 
		if(string[i] == 'T'){
			sumT++;//如果为字符P，则加一 
		}
	}  
	
	for(i = 0;i<temp;i++){
	//	printf("%d %d\n",array[i][0] ,array[i][1]);
		total += (array[i][0] * array[i][1]);
		total %= 1000000007;
	}
	printf("%d",total);
}

/*
APPAPT

PAT

ATPAPAPAT
**/
