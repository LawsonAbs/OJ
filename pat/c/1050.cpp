#include <stdio.h>
#include <string.h>
 
#define N 10002

char str1[N] ,str2[N];
int ascii[128];//表示128个ASCII码表 

int main(){
	gets(str1);
	gets(str2);//输入两个字符串
	int len1 = strlen(str1),len2 = strlen(str2);//求出两个字符串的长度
	
	int i = 0 ;
	for(i = 0;i < len2; i++	){
		ascii[str2[i]]++; 
		
	}
	
	for(i = 0;i<len1;i++){
		if(ascii[str1[i]]>0){
			continue;
		}
		else{
			printf("%c",str1[i]);
		}
	} 	
}
/**
Theay are students.
aeiou 
*/
