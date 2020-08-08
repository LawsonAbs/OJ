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
	//遍历 
	for(i = 0;i<length;i++){
		if(string[i] == 'P'){//如果开头一个字符为p 
			for(j = i+1;j<length;j++){
				if(string[j] == 'A'){//如果后面一个数为A 
					for(k = j+1;k<length;k++){
						if(string[k] == 'T'){
							total++;
							total %= 1000000007;
						} 
					}
				}
			}			
		}
	} 
	printf("%d",total);
}

/*
APPAPT

PAT
**/
