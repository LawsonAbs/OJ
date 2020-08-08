#include <stdio.h>
#include <string.h> 

/*
1.int array[128] ={0} ;//如果后期自己使用到数组里面的值（代码29行），那么必须对其进行赋值 
*/ 
 
#define N 100010
char str1[N],str2[N];

int main(){
	gets(str1);	
	gets(str2);	
	
	int len1 = strlen(str1) ,len2 = strlen(str2);
	int array[128] ={0} ;//
	int i ;
	for (i = 0;i < len2;i++){	
		if (str2[i]<='z' && str2[i]>='a' ){					
			array[str2[i]-32] = 1;		
		}
		else if(str2[i]<='Z' && str2[i]>='A') {		
			array[str2[i]+32] = 1;		
		}
			array[str2[i]] = 1;//代表可以出来的数字 
	}
	
	for (i = 0;i < len1 ;i++){
		if(array[str1[i]] != 1){
			if(str1[i]<='z' && str1[i] >='a'){				
				printf("%c",str1[i]-32);
				array[str1[i]-32] = 1; //防止后面再输出 
			} 			
			else if(str1[i]<='Z' && str1[i] >='A')
			{
				printf("%c",str1[i]);
				array[str1[i]+32] = 1; 
			}
			else{
				printf("%c",str1[i]);
			} 
			array[str1[i]] = 1; //动态变化 			
		}
	}	
} 

/*
7_This_is_a_test
_hs_s_a_es
*/
