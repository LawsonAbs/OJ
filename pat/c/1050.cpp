#include <stdio.h>
#include <string.h>
 
#define N 10002

char str1[N] ,str2[N];
int ascii[128];//��ʾ128��ASCII��� 

int main(){
	gets(str1);
	gets(str2);//���������ַ���
	int len1 = strlen(str1),len2 = strlen(str2);//��������ַ����ĳ���
	
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
